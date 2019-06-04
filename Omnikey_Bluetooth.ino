// Basic serial communication with Bluetooth HM-10
// Receive a trivial string through the Bluetooth HM-10
//
//  Arduino to HM-10 connections
//  Arduino 3.3V or 5V to VCC of HM-10
//  Arduino pin 2 (TX) to voltage divider then to HM-10 RX
//  Arduino pin 3 to HM-10 TX
//  Connect GND from the Arduino to GND on the HM-10
//
// When a command is entered in to the serial monitor on the computer 
// the Arduino will relay the command to the HM-10


// Library to make a Software UART
#include <SoftwareSerial.h>

#define RX 3
#define TX 2
#define Button 13

#define BAUDRATE 9600

char out = 0;
int currState = 0;
int lastState = 0;
char c = ' ';
char K1 = 0;
char K2 = 0;
char K3 = 0;
//char K4 = 0;
//char K5 = 0;
 
SoftwareSerial BTSerial(RX, TX); // (RX, TX)

void setup() {

  // Start Serial Monitor for feedback
  Serial.begin(BAUDRATE);

  // HM-10 default speed in AT command mode
  BTSerial.begin(BAUDRATE);

  pinMode(Button, INPUT);
}
 
void loop() {
  
  // Keep reading from HM-10 and send to Arduino Serial Monitor  
  while(BTSerial.available() > 0) {

    // Read from the bluetooth buffer
    c = BTSerial.read();

    // Write the received bluetooth data to the Serial Monitor
    Serial.println(c);

    // Update Variable according to the data received
    switch(c) {
      case 'A':
        K1 = 1;
        break;
      case 'B':
        K2 = 1;
        break;
      case 'C':
        K3 = 1;
        break;
      case 'a':
        K1 = 0;
        break;
      case 'b':
        K2 = 0;
        break;
      case 'c':
        K3 = 0;
        break;
    }

    // Check button press
    currState = digitalRead(Button);
    if (currState != lastState) {
      if (out == 0) {
        out = 1;
      }
      else {
        out = 0;
      }
      
      // Pop out or retrieve according to variable out
      setKey(K1, out);
      setKey(K2, out);
      setKey(K3, out);
    }
  }
  lastState = currState;
  Serial.println();
//  delay(1000);
}

void setKey(char which, char state) {
  // Set the key which according to state
  
}
