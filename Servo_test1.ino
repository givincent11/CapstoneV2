#include <Servo.h>
 
// Create a servo instance.
Servo servo;
 
void setup() {
  // Attach servo output to pin 12.
  servo.attach(12);
  pinMode(13, OUTPUT);
}
 
void loop() {
  // Move to position 0, or a 1.0 millisecond long pulse:
  // Remember the servo module in Arduino takes in a position in degrees
  // from 0 to 180 instead of a pulse length in milliseconds or other value.
  servo.write(0);
  // Delay for a second.
  delay(2000);
  // Move to position 180, or a 2.0 millisecond long pulse and pause again.
  servo.write(90);
  delay(2000);
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);              // delay(ms)
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(100);              // wait for a second
}
