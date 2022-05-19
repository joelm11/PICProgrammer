import serial  
import time

port = serial.Serial('COM3', 9600, timeout = 10)  
time.sleep(1) 
port.flushInput()
# Wait for arduino to send ready command 
print(port.read_until(expected = b'\x01'))    
port.flushInput()
# Write a piece of data and see if arduino got it correctly 
port.write(b'\xAB\xCD\xEF') 
# port.flushInput()
print(port.read_until(expected = b'\xAB\xCD\xEF')) 

