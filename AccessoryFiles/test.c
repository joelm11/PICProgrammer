#include <xc.h>
#include <pic16f688.h>

int main() {  

    // All pins as output  
    ANSEL = 0x00; 
    TRISC = 0;   
    TRISA = 0; 
    PORTA = 0xFF;
    PORTC = 0xFF;
    return 0;

}