/*
This sketch is for testing sensors with SharpIR library
*/
#include <SharpIR.h>

int val1 = 0;
int val2 = 0;
SharpIR sharp1(3, 25, 93, 1080);  // sensor attached to pin 2
SharpIR sharp2(5, 25, 93, 1080);  // sensor attached to pin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  val1 = sharp1.distance();
  val2 = sharp2.distance();
  Serial.println(val1-val2);
  delay(100);
}
