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

int pos = 90;
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
  if(Serial.available()) {
    //get input
    userInput = Serial.readString();// read the incoming data as string
    //try to get the axis
    xyzKey = userInput.substring(0,2);
    Serial.print(xyzKey);
    //get the start of the number
    //int startNum = userInput.find(":");
    //extract numberString
    String degree = userInput.substring(2,5);
    Serial.println(degree);
    //convert to float
    float actualDegree = degree.toFloat();
    //offset
    float pos = actualDegree + 90;
    if(xyzKey.equalsIgnoreCase("X")){
      xPosServo.write(pos);
    }
    else if(xyzKey.equalsIgnoreCase("Y"));{
      yPosServo.write(pos);
    }
    if(xyzKey.equalsIgnoreCase("Z"));{
      zPosServo.write(pos);
    }
  }
}

//make it so that user types in something like x:-23
//make it from ranges -90 to 90   |||   translate from 0 to 180
//x:90   y:34  z:-45

//moosebutter --> spam / i hate mosquitos / rubber monkey
