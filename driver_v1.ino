/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 Modefied by Ahmad S. for Robojax.com
 on May 19, 2018 at 19:31, at Ajax, Ontario, Canada

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

//push button variables
const int button = A2;
int value = 0;
int reverse = 0;

// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);
Stepper myStepper2(stepsPerRevolution, 10, 11, 12, 13);

void setup() {
  Serial.begin(9600);
  // set the speed at 100 rpm:
  myStepper.setSpeed(100);
  myStepper2.setSpeed(100);

  //setup LED
  pinMode(button, INPUT);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  //read value of button
  value = digitalRead(button);
  Serial.println(value);

  //check if pressed again to reverse
  //if( reverse == 0 ) {
  //if pressed
    if( value == HIGH ) {
      //reverse = reverse + 1;
      // step one revolution  in one direction:
      Serial.println("clockwise");
      myStepper.step(stepsPerRevolution);
      delay(200);
      myStepper2.step(stepsPerRevolution);
      delay(500);
    } 

    else {
      Serial.println("no press");
    }
    
  /*else {
    // L298N for Robojax.com 
    // step one revolution in the other direction:
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    myStepper2.step(-stepsPerRevolution);
    delay(500);
    reverse = 0;
  }*/
}
