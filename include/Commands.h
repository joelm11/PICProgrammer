#ifndef COMMANDS_H 
#define COMMANDS_H 

// GPIO Defines (Port E) 
#define CLK PIN1_bm
#define DAT PIN0_bm
#define MCLR PIN3_bm  

// Useful constants 
#define CMD_LEN 6
#define DATA_LEN 14 
#define ADDR_LEN 2 
#define START 1
#define EOT 4

// Commands 
#define LOAD_DAT_PROG_MEM 0b000010 
#define BEGIN_PROG 0b001000
#define INC_ADDR 0b000110 
#define READ_PROG_MEM 0b000100 
#define BLK_ERASE_PROG_MEM 0b001001 
#define DEBUG 0b010101 
#define LOAD_CONFIG 0b000000 

// Config register bitmasks 
#define INTOSCIO 0x06
#define MCLRB 0x20

// Timing delays (ms) unless specified 
#define TPROG1 3 // This is also TProg2
#define TDLY2 1 // (us)  
#define BITRATE (unsigned long)2 // delay for 9600 baud ~104 uS, but millis() has resolution of 4 uS
#define TERA 6  
#define THLD0 4

// Function definitions
void GPIOconfig();
void write_readback(int data);
void program_pic();
static int clockdata(int data, int datalength, int write);   
static void load_data(int data);  
static int read_data();
static void begin_programming(); 
static void write_config_word(int config_word);
static void pad_zero();  
static void prog_mem_erase(); 
static void inc_pc(int increments); 
static void MCLR_togg();

#endif
