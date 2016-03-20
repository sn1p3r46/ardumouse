""" This Python Software reads messages from serial port and moves the cursor 
    based on received messages.

    AUTHOR: Andrea Galloni
    E-Mail: andrea[dot]galloni[at]studenti[dot]unitn[dot]it

    DEPENDENCES:
      python-serial
      python-uinput

    LICENSE:

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any
    means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

    For more information, please refer to <http://unlicense.org/>"""


import serial
import time
import uinput


def main():
    events = (
        uinput.REL_X,
        uinput.REL_Y,
        uinput.BTN_LEFT,
        uinput.BTN_RIGHT,
        )
    step = 1
    with uinput.Device(events) as device:
	ser = serial.Serial('/dev/ttyUSB2', 9600)

	while True:
		input = ser.readline().strip()
		#print input
		if (input == "up"):
			device.emit(uinput.REL_Y, -step, syn=False)
		elif(input == "down"):
			device.emit(uinput.REL_Y, step, syn=False)
		elif(input == "left"):
			device.emit(uinput.REL_X, -step)
		elif(input == "right"):
			device.emit(uinput.REL_X, step)
		elif(input == "lb"):
			device.emit(uinput.BTN_LEFT, 1)
		elif(input == "lbr"):
			device.emit(uinput.BTN_LEFT,0)
	        elif(input == "rb"):
        		device.emit(uinput.BTN_RIGHT,1)
		elif(input == "rbr"):
            		device.emit(uinput.BTN_RIGHT,0)


# TODO: Implement Movement Acceleration
# TODO: Configuration File


if __name__ == "__main__":
	main()
