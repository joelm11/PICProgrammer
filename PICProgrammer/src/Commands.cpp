#include <Arduino.h>
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
    // Enter program/verify mode 
    MCLR_togg();  
    // Bulk erase 
    prog_mem_erase(); 
    // Word programming and verification loop 
    /* 
    while (input from hex file) 
        program word 
        read back to check accuracy 
        assert: returned word == sent word 
        increment address or break if done
    */ 
    

    return;
}

void GPIOconfig(){ 

  // Set CLK, DAT, and MCLR pins as output
  PORTE_DIR |= CLK + DAT + MCLR; 
  // Start IO low, but set MCLR so PIC does not receive +12V yet
  PORTE_OUT = MCLR;

}  

// Shifts DOUT LSB first 
// TODO: Maybe abstract delay
static int clockdata(int data, int datalength, int write){  
    unsigned long t1, t2;

    if (write) {   
        for (int i = 0; i < 2 * datalength; i++) {   
            t1 = micros();
            // If rising clock edge, toggle data
            if (i % 2 == 0) {  
            // Set databit to 0 or 1 
            int databit = (data & 1 << i / 2) > 0;   
            // Primitive delay
            while((micros() - t1) < BITRATE); 
            PORTE_OUT = CLK + databit;
        } 
        // Else it's a falling edge, don't toggle data
        else {  
            while((micros() - t1) < BITRATE); 
            PORTE_OUT &= ~CLK;
        }
        } 
    // Return CLK and DAT line low when done 
    PORTE_OUT = 0;  
    return 1;
    }   

    else {   
    // Configure DAT line as input
    PORTE_DIR &= ~DAT; 
    // 16 clock cycles to read data, 32 toggles 
    int num_toggles, bit, new_data; 
    num_toggles = 33; 
    bit = 0; 
    new_data = 0;   

    // Clock DIN on falling edge
    for(int i = 0; i < num_toggles; i++){  
        t1 = micros();
        // If falling clock edge, clock in data
        if (i % 2 != 0) {  
        // Shift in databit to data int
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
    PORTE_DIR |= DAT;  
    // Set CLK and DAT low 
    PORTE_OUT &= ~(CLK + DAT);
    return new_data;
  } 
} 


// Clock command, then clock DAT with start/stop bits 
static void load_data(int data){ 

  clockdata(load_dat_prog_mem, CMD_LEN, 1);   
  //for testing and legibility
  delayMicroseconds(25); 
  pad_zero();
  clockdata(data, DATA_LEN, 1);
  pad_zero(); 
  //for testing and legibility
  delayMicroseconds(25);

}

static void begin_programming(){ 

  clockdata(begin_prog, CMD_LEN, 1); 
  delay(TPROG1); 

}

static int read_data(){ 

  clockdata(read_prog_mem, CMD_LEN, 1);  
  delayMicroseconds(25); 
  int ret_data = clockdata(read_prog_mem, CMD_LEN, 0); 
  delayMicroseconds(25);
  return ret_data; 

} 

// Write a register, then read it back 
// TODO: Find nice way to confirm read back data
void write_readback(int data){ 

    load_data(data); 
    begin_programming(); 
    delayMicroseconds(5); 
    int ret_data = read_data(); 
    // Serial.println("Data read:"); 
    // Serial.println(ret_data);

}

static void pad_zero(){  
    unsigned long t1; 
    
    t1 = micros(); 
    while((micros() - t1) < BITRATE);
    PORTE_OUT |= CLK;
    t1 = micros(); 
    while((micros() - t1) < BITRATE); 
    PORTE_OUT &= ~CLK; 

} 

// Toggle MCLR to enter/exit programming mode 
// Setting high turns on BJT bringing MCLR low, need MCLR high for programming mode
static void MCLR_togg(){ 

    // Voltage on chip needs low->high transition to enter programming mode
    PORTE_OUT ^= MCLR;  
    delayMicroseconds(3); 

} 

// Write an erase command, wait erase delay TERA
static void prog_mem_erase(){ 

    clockdata(BLK_ERASE_PROG_MEM, CMD_LEN, 1); 
    delay(TERA);

} 
