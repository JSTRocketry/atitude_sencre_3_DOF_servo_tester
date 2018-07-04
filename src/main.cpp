#include <Arduino.h>
#include <Servo.h>
#include <stdlib.h>
#include <stdio.h>

const byte numChars = 32;
char receivedChars[numChars];   // array to store the received data

boolean newData = false;

Servo xPosServo;
Servo yPosServo;
Servo zPosServo;
String userInput;
String xyzKey;
String tempos;

int pos = 0;
int xPinServo = 4;
int yPinServo = 5;
int zPinServo = 6;
char buffer[100];

void setup() {
  Serial.begin(9600);
  xPosServo.attach(xPinServo);
  yPosServo.attach(yPinServo);
  zPosServo.attach(zPinServo);
}

void loop() {
  //Serial.read();
  while(Serial.available()) {
    userInput = Serial.readString();// read the incoming data as string

    xyzKey = userInput.substring(1,2);
  }

  fgets(buffer, 100, stdin);
  pos = atoi(buffer);
  pos = pos + 90;

  if(xyzKey = "X"||"x"){
    xPosServo.write(pos);
  }
  else if(xyzKey = "Y"||"y");{
    yPosServo.write(pos);
  }
  if(xyzKey = "Z"||"z");{
    zPosServo.write(pos);
  }
}


//make it so that user types in something like x:-23
//make it from ranges -90 to 90   |||   translate from 0 to 180
//x:90   y:34  z:-45

//moosebutter --> spam / i hate mosquitos / rubber monkey
