

// GPIO Defines (Port E) 
#define CLK PIN1_bm
#define DAT PIN0_bm
#define MCLR PIN3_bm  

// Useful constants 
#define CMD_LEN 6
#define DATA_LEN 14

// Commands 
#define load_dat_prog_mem 0b000010 
#define begin_prog 0b001000
#define inc_addr 0b000110 
#define read_prog_mem 0b000100 
#define BLK_ERASE_PROG_MEM 0b001001

// Timing delays (ms)
#define clk_half_period 5 
#define TPROG1 3 // This is also TProg2
#define TDLY2 1 // (us)
#define BITRATE (unsigned long)26// delay for 9600 baud ~104 uS, but millis() has resolution of 4 uS  
#define TERA 6 

// Function definitions
void GPIOconfig();
void write_readback(int data);
void program_pic();
void MCLR_togg();  

static int clockdata(int data, int datalength, int write);   
static void load_data(int data);  
static int read_data();
static void begin_programming(); 
static void pad_zero();  
static void prog_mem_erase();
