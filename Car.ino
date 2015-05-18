/*
 * NewSerialServo
 * --------------
 * Servo control from the Serial port
 *
 * Alteration of the control interface to use  keys
 * to slew the servo horn left and right.  Works best with
 * the Linux/Mac terminal "screen" program.
 *
 * Created 10 December 2007
 * copyleft 2007 Brian D. Wendt
 * http://principialabs.com/
 *
 * Adapted from code by Tom Igoe
 * http://itp.nyu.edu/physcomp/Labs/Servo
 */
#include <Servo.h> 

Servo myservo;
Servo myservo2;
Servo myservo3;

/** Adjust these values for your servo and setup, if necessary **/
int servoPin     =  3;    // control pin for servo motor
int minPulse     =  600;  // minimum servo position
int moveServo;  
int turnRate = 1;
int pos  = 90;
int pos2 = 90;
int pos3 = 9-0;
int Ipos=90;

void setup() {

  myservo.attach(3);
  myservo2.attach(4);
  myservo3.attach(5);
  myservo.write(Ipos);
  myservo2.write(Ipos);
  myservo3.write(Ipos);
  
  // Give the servo a starting point (or it floats)
  Serial.begin(9600);
  Serial.println("      Arduino Serial Servo Control");
  Serial.println("Servo control,   ");
  Serial.println("Servo 1 Left   : A  ");
  Serial.println("Servo 1 Center : S  ");
  Serial.println("Servo 1 Right  : D  ");
  Serial.println("Servo 2 Left   : F  ");
  Serial.println("Servo 2 Center : G  ");
  Serial.println("Servo 2 Right  : H  ");
  Serial.println("Servo 3 Left   : J  ");
  Serial.println("Servo 3 Center : K  ");
  Serial.println("Servo 3 Right  : L  ");
  Serial.println();
}

void loop() {
  // wait for serial input
  if (Serial.available() > 0) {
    // read the incoming byte:
    moveServo = Serial.read();

    // ASCII '' is 46 (comma and period, really)
    if (moveServo == 65 ) { pos = pos - turnRate; }   // A
    if (moveServo == 68 ) { pos = pos + turnRate; }   // D
    if (moveServo == 83 ) { pos = 90 ; }              // S
    if (moveServo == 70 ) { pos2 = pos2 - turnRate; } // F
    if (moveServo == 72 ) { pos2 = pos2 + turnRate; } // G
    if (moveServo == 71 ) { pos2 = 90 ; }             // H
    if (moveServo == 74 ) { pos3 = pos3 - turnRate; } // J
    if (moveServo == 76 ) { pos3 = pos3 + turnRate; } // K
    if (moveServo == 75 ) { pos3 = 90 ; }             // L

    pos  = constrain(pos, 5, 179);
    pos2 = constrain(pos2, 4, 180);
    pos3 = constrain(pos3, 4, 180);

    myservo.write(pos);
    myservo2.write(pos2);
    myservo3.write(pos3);

Serial.print("Servo1: ");
Serial.println(pos);
Serial.print("Servo 2: ");
Serial.println(pos2);
Serial.print("Servo 3:");
Serial.println(pos3);

}
}
