#include <Arduino.h> 
#include "Commands.h"

void setup() { 

  GPIOconfig(); 
  Serial.begin(9600); 

}

void loop() { 

    write_readback(0x3FFF);
    delay(1); 

} 
