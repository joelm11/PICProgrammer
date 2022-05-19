""" Compile PIC16F688 source to .hex via XC8 compiler, 
    send line-by-line to arduino for programming on PIC MCU """
import serial 
import subprocess 
import os 
import time 
import struct

def main(): 

    # Get name of PIC sourcefile.c 
    file_to_program = input("Path to source.c: ") 

    # Get arduino connected COM port from user  
    arduinoPort = input("Nano COM Port No.:")  

    # Port, baud, bytsize, parity, stopbits 
    ser = serial.Serial(port = 'COM' + arduinoPort, baudrate = 9600, timeout = 10)   
    # This is a necessary evil in this case https://stackoverflow.com/questions/2301127/pyserial-app-runs-in-shell-by-not-py-script
    time.sleep(1)

    # Generate HEX file from xc8 compiler assuming xc8 is on the system path 
    if not os.path.exists('./PIC_Compiler_Output'): 
        os.mkdir('./PIC_Compiler_Output')
    subprocess.run(['xc8', '--chip=16F688', '--outdir=PIC_Compiler_Output', file_to_program])

    slice_ind1 = file_to_program.rfind('/') + 1 
    slice_ind2 = file_to_program.rfind('.c')
    file_name = file_to_program[slice_ind1 : slice_ind2]   
 
    # Get line count 
    with open ('./PIC_Compiler_Output/' + file_name + '.hex') as file:   
        count = 0 
        for line in file: 
            count += 1   
    
    # Give linecount to Arduino 
    ser.write(struct.pack('B', count)) 
    time.sleep(.2)

    with open ('./PIC_Compiler_Output/' + file_name + '.hex') as file:
        print("Lines in file:", count-1)
        for line in file:  
            # Each hex string formatted as ':<no. data bytes n><address offset><record type><2n data chars><2 checksum chars>' 
            # See https://docs.google.com/document/d/1upHLy-3fykEp5Pi51vpNFDHdkuF2PDd2-0qNSMz2UFw/edit?usp=sharing 
            data_size = line[1:3] 
            addr_offset = line[3:7]
            cmd_type = line[7:9] 
            data = line[9:-3]  
            hex_addr = str2hex(addr_offset) 
            hex_dsize = str2hex(data_size)
            hex_data = str2hex(data) 
            
            if cmd_type == '01':  
                print("Finished file")
                break 
 
            write_and_confirm(ser, hex_addr)  
            write_and_confirm(ser, hex_dsize)
            write_and_confirm(ser, hex_data)
            print("Finished flashing line")
            
""" Takes list of hex values and flashes them to ATMega"""
def write_and_confirm(port, hex_vals): 
 
    # Debug
    print("Bytes to be written:", hex_vals)   
    
    # Read for start bit for data section from Arduino (<Address> <Data size> <Data>)
    port.read_until(expected = b'\x01') 
    for elem in hex_vals:  
        # Pack hex value as a byte to send over serial
        bts = struct.pack('B', elem) 
        port.write(bts)   

def str2hex(str): 
    return [int(str[i:i+2], 16) for i in range(0, len(str), 2)]

if __name__ == "__main__":
    main()