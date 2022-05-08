""" Compile PIC16F688 source to .hex via XC8 compiler, 
    send line-by-line to arduino for programming on PIC MCU """
import serial 
import subprocess

# Get path to XC8 Compiler executable 
# pathToXC8 = input("Path to xc8.exe") 

# Get name of PIC sourcefile.c 
file_to_program = input("Path to source.c: ")

# Get arduino connected COM port from user 
# arduinoPort = input("Enter number of arduino COM port:") 

# Port, baud, bytsize, parity, stopbits
# ser = serial.Serial(port = 'COM' + arduinoPort, baudrate = 9600)  

# Generate HEX file from xc8 compiler (?)   
# here we are assuming compiler has been added to path
# subprocess.run(['xc8', '--chip=16F688', file_to_program])

# Serial send HEX file line by line to arduino 
# TODO unhardcode file name
with open('test.hex') as file: 
    for line in file:  
        # Format each line by 
        print(line[1:], end='') 
    # print(list(file))

# Close serial port 
# ser.close()
