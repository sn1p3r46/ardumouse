/*

  This simple Arduino code takes buttons input and send
  messages to the serial port. Those messages contains
  values useful to emulate a mouse on the PC.

  Since with Arduino Nano is not possible to emulate
  an USB device, in order to make it work there is the
  need of a software listening on the serial port capable
  to emulate a mouse.

  AUTHOR: Andrea Galloni
  E-Mail: andrea[dot]galloni[at]studenti[dot]unitn[dot]it

  DEPENDENCES:
    arduino
    arduino-core

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

  For more information, please refer to <http://unlicense.org/>

*/

const int rightPin = 2;
const int downPin = 3;
const int upPin = 4;
const int leftPin = 5;
const int lbPin = 6;
const int rbPin = 7;


const int ledPin = 13;      // the number of the LED pin


int left;
int right;
int up;
int down;

int leftb;
int leftbState = 0;
int statusbl = 0;

int rightb;
int rightbState = 0;
int statusbr = 0;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as an input:
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  pinMode(lbPin, INPUT);
  pinMode(rbPin, INPUT);


  Serial.begin(9600);
}

void loop() {

  // read the state of any button:
  readButtons(rightPin,leftPin,upPin,downPin,lbPin,rbPin);

  // read the state of the right button value:
  right = digitalRead(rightPin);

  if(right == HIGH){Serial.println("right");};

  // read the state of the left button value:
  left = digitalRead(leftPin);
  if(left == HIGH){Serial.println("left");};

  // read the state of the up button value:
  up = digitalRead(upPin);
  if(up == HIGH){Serial.println("up");};

  // read the state of the down button value:
  down = digitalRead(downPin);
  if(down == HIGH){Serial.println("down");};


  // For L and R buttons we would like to output only the state change


  leftb = digitalRead(lbPin);
  if(leftb != leftbState && statusbl==0){
    statusbl = 1;
    Serial.println("lb");

  } else if (leftb != leftbState && statusbl==1){
    statusbl = 0;
    Serial.println("lbr");
  }

  leftbState = leftb;



  rightb = digitalRead(rbPin);
  if(rightb != rightbState && statusbr == 0){
    statusbr = 1;
    Serial.println("rb");

  } else if (rightb != rightbState && statusbr == 1){
    statusbr = 0;
    Serial.println("rbr");
  }

  rightbState = rightb;

}


// If any button is pressed the led will be on

void readButtons(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6){
  int state;

  if (digitalRead(pin1) == HIGH || digitalRead(pin2) == HIGH  || digitalRead(pin3) == HIGH  || digitalRead(pin4) == HIGH  || digitalRead(pin5) == HIGH  || digitalRead(pin6) == HIGH ){
    state = HIGH;
  }

  else{
    state = LOW;
  }
  digitalWrite(ledPin, state);
}
