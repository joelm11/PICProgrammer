#include <Arduino.h> 
#include <assert.h>
#include "Commands.h"  

// General algorithm 
/* 
1. Bulk erase 
2. Program word 
3. Read it back and check if correct 
4. Increment address or return 
5. Write config memory (OPTIONAL) 
6. Done
*/ 
void program_pic(){  

    // Receive total lines to program from PC 
    //  
    uint8_t lines_to_program;  
    while (Serial.available() < 1); 
    lines_to_program = Serial.read(); 

    // Enter program/verify mode 
    //
    MCLR_togg();   

    // Bulk erase 
    //
    prog_mem_erase();  

    // Word programming and verification loop 
    //    
    int program_counter = 0; 

    for (uint8_t l = 0; l < lines_to_program - 1; l++) {   
        int address, data, ret_data;
        uint8_t addr_bytes[ADDR_LEN], datasize;   
       
        digitalWrite(LED_BUILTIN, HIGH);

        // Tell PC ready for address data  
        //
        Serial.write(START); 
        // Read address, get move program counter to address   
        // physical address is hexfile address / 2
        while (Serial.available() < 2);  
        Serial.readBytes(addr_bytes, ADDR_LEN);  
        address = ((addr_bytes[0] << 4) + addr_bytes[1]) / 2; 

        if (program_counter != address) { 
            inc_pc(address - program_counter); 
            program_counter = address;
        } 

        // Send ready for datasize to PC 
        //
        Serial.write(START); 
        
        // Read datasize  
        // 
        while (Serial.available() < 1); 
        datasize = Serial.read(); 

        // Read in dsize * databytes  
        //
        uint8_t data_bytes[datasize];  
        Serial.write(START);  
        while (Serial.available() < datasize);
        Serial.readBytes(data_bytes, datasize);  

        // HEX file has bytes in <LSB><MSB> ordering
        //
        for (int i = 0; i < datasize; i += 2) {   
           
            // Format data for MSB ordering 
            //
            data = (data_bytes[i + 1] << 8) + data_bytes[i];  
            
            load_data(data);   
            begin_programming(); 
            delayMicroseconds(5); 
            ret_data = read_data();   
            // TODO verify ret_data in program rather than from waveform

            inc_pc(1);  
            program_counter++;
        }  

        delayMicroseconds(TDLY2); 

    }  
    
    // Write configuration word  
    // 
    // Debug got rid of MCLR enable 
    //  
    // TODO/DEBUG: This programming config memory
    delayMicroseconds(50);
    // write_config_word(INTOSCIO + MCLRB); 
    write_config_word(0x25);

    // Leave program/verify mode 
    // 
    delayMicroseconds(THLD0);
    MCLR_togg();
    digitalWrite(LED_BUILTIN, LOW); 

}

void GPIOconfig(){ 

  // Set CLK, DAT, and MCLR pins as output
  //
  PORTE_DIR |= CLK + DAT + MCLR; 

  // Start IO low, but set MCLR so PIC does not receive +12V yet
  //
  PORTE_OUT = MCLR;

}  

// Shifts DOUT LSB first 
//
static int clockdata(int data, int datalength, int write){  
    unsigned long t1, t2;

    if (write) {   
        for (int i = 0; i < 2 * datalength; i++) {   
            t1 = micros();
            // If rising clock edge, toggle data 
            //
            if (i % 2 == 0) {  
            // Set databit to 0 or 1 (shift out LSb)
            // 
            int databit = (data & 1 << i / 2) > 0;   
            // Primitive delay
            //
            while((micros() - t1) < BITRATE); 
            PORTE_OUT = CLK + databit;
            } 
            // Else it's a falling edge, don't toggle data 
            //
            else {  
                while((micros() - t1) < BITRATE); 
                PORTE_OUT &= ~CLK;
            }
        }  

    // Return CLK and DAT line low when done 
    //  
    PORTE_OUT = 0;
    return 1;
    }   

    else {   
    // Configure DAT line as input
    //
    PORTE_DIR &= ~DAT; 
    // 16 clock cycles to read data, 32 toggles 
    //
    int num_toggles, bit, new_data; 
    num_toggles = 33; 
    bit = 0; 
    new_data = 0;   
    // Clock DIN on falling edge
    //
    for(int i = 0; i < num_toggles; i++){  
        t1 = micros();
        // If falling clock edge, clock in data
        //
        if (i % 2 != 0) {  
        // Shift in databit to data int
        //
        bit = (PORTE_IN & DAT) > 0; 
        new_data <<= 1; 
        new_data |= bit; 
        while((micros() - t1) < BITRATE);
        PORTE_OUT |= CLK;
        } 
        else  { 
            while((micros() - t1) < BITRATE);
            PORTE_OUT &= ~CLK;
        }
    }
    // Make DAT line output again 
    //
    PORTE_DIR |= DAT;  
    // Set CLK and DAT low 
    //
    PORTE_OUT &= ~(CLK + DAT);
    return new_data;
  } 
} 


// Clock command, then clock DAT with start/stop bits  
// TODO may have to investigate any weirdness with sending 14 bits of the 2-byte data
static void load_data(int data){ 

  clockdata(LOAD_DAT_PROG_MEM, CMD_LEN, 1);   
  //for testing and legibility
  delayMicroseconds(25); 
  pad_zero();
  clockdata(data, DATA_LEN, 1);
  pad_zero(); 
  //for testing and legibility
  delayMicroseconds(25);

}

static void begin_programming(){ 

  clockdata(BEGIN_PROG, CMD_LEN, 1); 
  delay(TPROG1); 

}

static int read_data(){ 

  clockdata(READ_PROG_MEM, CMD_LEN, 1);  
  delayMicroseconds(25); 
  int ret_data = clockdata(READ_PROG_MEM, CMD_LEN, 0); 
  delayMicroseconds(25);
  return ret_data; 

} 

// Write a register, then read it back 
// TODO: Find nice way to confirm read back data
//
void write_readback(int data){ 

    load_data(data); 
    begin_programming(); 
    delayMicroseconds(5); 
    int ret_data = read_data(); 
    // Serial.println("Data read:"); 
    // Serial.println(ret_data);

}

// Clock a 0 bit
//
static void pad_zero (){  
    unsigned long t1; 
    
    t1 = micros(); 
    while((micros() - t1) < BITRATE);
    PORTE_OUT |= CLK;
    t1 = micros(); 
    while((micros() - t1) < BITRATE); 
    PORTE_OUT &= ~CLK; 

} 

// Toggle MCLR to enter/exit programming mode 
// setting high turns on BJT bringing MCLR low, need MCLR high for programming mode
//
static void MCLR_togg (){ 

    // Voltage on chip needs low->high transition to enter programming mode
    //
    PORTE_OUT ^= MCLR;  
    delayMicroseconds(3); 

} 

// Write an erase command, wait erase delay TERA 
//
static void prog_mem_erase (){ 

    clockdata(BLK_ERASE_PROG_MEM, CMD_LEN, 1); 
    delay(TERA);

} 

static void inc_pc (int increments){  

    for (int i = 0; i < increments; i++){ 
        clockdata(INC_ADDR, CMD_LEN, 1); 
        delayMicroseconds(20);
    } 

} 

// Writing this command sets PC to 2000h and loads data latches
// this is a bit of pain, consult F3-18, programming guide(latching weirdness) and DS
static void write_config_word (int config_word){ 

    delay(5);       
    // Send load configuration command and 0-padded data
    // 
    // 1. Load config command 2. 7x inc 3. Load data for prog mem cmd 4. being prog cmd 
    // 5. Wait some time 6. end prog command. 7. Read it back  
    clockdata(LOAD_CONFIG, CMD_LEN, 1);  
    delayMicroseconds(TDLY2); 
    pad_zero(); 
    clockdata(config_word, DATA_LEN, 1); 
    pad_zero();
    delayMicroseconds(25);
    for (int i = 0; i < 4; i++) { 
    delayMicroseconds(TDLY2);  
    // maybe need to clock a word here not sure (on this line)
    load_data(config_word); 
    begin_programming();
    delay(3); 
    read_data(); 
    inc_pc(1);
    }
    
    inc_pc(3); 
    load_data(config_word); 
    delayMicroseconds(TDLY2); 
    begin_programming(); 
    delay(3); 
    read_data();
}