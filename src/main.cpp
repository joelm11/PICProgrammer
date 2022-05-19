#include <Arduino.h> 
#include "Commands.h"

void setup() { 

    GPIOconfig(); 
    Serial.begin(9600); 
    pinMode(LED_BUILTIN, OUTPUT); 
    digitalWrite(LED_BUILTIN, HIGH);
    program_pic(); 

}

void loop() { 

    digitalWrite(LED_BUILTIN, HIGH); 
    delay(500); 
    digitalWrite(LED_BUILTIN, LOW); 
    delay(500);

} 
