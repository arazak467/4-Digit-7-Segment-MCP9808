/* Using the MCP9808 to take more accurate temperature readings,
 * display it on the 4 digit 7 segment.
 * 
 * Components:
 *              - Arduino Uno
 *              - MCP9808
 *              - 4 digit 7 segment display
 *             
 * Libraries:
 *              - Wire
 *              - Adafruit_MCP9808
 *              
 * Datasheet: https://cdn-shop.adafruit.com/datasheets/MCP9808.pdf
 * 
 * Created on 13 June 2022 by arazak467
 */

#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempSensor = Adafruit_MCP9808();

int pinA = 11;
int pinB = 7;
int pinC = 4;
int pinD = 2;
int pinE = 1;
int pinF = 10;
int pinG = 5;
int pinDP = 3;

int D1 = 12;
int D2 = 9;
int D3 = 8;
int D4 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);  //11
  pinMode(pinB, OUTPUT);  //7
  pinMode(pinC, OUTPUT);  //4
  pinMode(pinD, OUTPUT);  //2
  pinMode(pinE, OUTPUT);  //1
  pinMode(pinF, OUTPUT);  //10
  pinMode(pinG, OUTPUT);  //5
  pinMode(D1, OUTPUT);    //12
  pinMode(D2, OUTPUT);    //9
  pinMode(D3, OUTPUT);    //8
  pinMode(D4, OUTPUT);    //6

  tempSensor.begin(0x18);
}

void loop() {
  // put your main code here, to run repeatedly:
  float C = tempSensor.readTempC(); // Celsius
//  float F = C*9.0/5.0 + 32; // Fahrenheit 

  // display temperature (Celsius) digis on 4 digit 7 segment display
  int tempd1 = int(C/10);
  int tempd2 = int((int)C%10);

  // display temperature (Fahrenheit) digis on 4 digit 7 segment display
//  int tempd1 = int(F/10);
//  int tempd2 = int((int)F%10);

  // 'for' loop ensures the display is constantly ON within a period of time (approx. 10s)...
  // ...before sensor takes another reading.
  // Temperature reading
  for (int i = 0; i < 2000; i++) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(tempd1);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(tempd2);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    disp(11);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    disp(10);
    delay(1);

    // Fahrenheit symbol
//    digitalWrite(D1, HIGH);
//    digitalWrite(D2, HIGH);
//    digitalWrite(D3, HIGH);
//    digitalWrite(D4, LOW);
//    disp(12);
//    delay(1);
  }
  displayoff();
  tempSensor.shutdown_wake(1);  // shutdown MCP9808 - power consumption ~0.1 micro Ampere
  delay(2000);
  tempSensor.shutdown_wake(0);  // wake up MCP9808 - power consumption ~200 micro Ampere
  
}

void disp(int number) {

  switch (number) {
    case 0 : // display '0' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 1 : // display '1' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 2 : // display '2' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 3 : // display '3' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 4 : // display '4' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 5 : // display '5' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 6 : // display '6' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 7 : // display '7' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 8 : // display '8' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 9 : // display '9' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 10 :  // display 'C' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 11 :  // display 'o' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

//    case 12 : // display "F" on 7 segment
//      digitalWrite(pinA, HIGH);
//      digitalWrite(pinB, LOW);
//      digitalWrite(pinC, LOW);
//      digitalWrite(pinD, LOW);
//      digitalWrite(pinE, HIGH);
//      digitalWrite(pinF, HIGH);
//      digitalWrite(pinG, HIGH);
//      break;
  }
}

void displayoff() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}
