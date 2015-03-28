/*
feedback:
more power motor
lower the dangerous level
*/
#include <SharpIR.h>

SharpIR sharp1(2, 25, 93, 1080);  // sensor attached to pin 2
SharpIR sharp2(3, 25, 93, 1080);  // sensor attached to pin 3
SharpIR sharp3(5, 25, 93, 1080);  // sensor attached to pin 5
int val_sensor_ahead = 0;
int val_sensor_right = 0;
int val_sensor_left = 0;
int dangerous_level = 60;

void setup() {
  // setup motor channels
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  
  // setup serial monitor
  Serial.begin(9600);
}

void loop() {
  // read sensors distance
  val_sensor_ahead = sharp3.distance();
  val_sensor_right = sharp2.distance();
  val_sensor_left = sharp1.distance();
  
  if (val_sensor_ahead < dangerous_level)
  {
    if (val_sensor_right > dangerous_level)
    {
      Serial.println("turn right");
      turn_right();
    }
    else if (val_sensor_left > dangerous_level)
    {
      Serial.println("turn left");
      turn_left();
    }
    else
    {
      Serial.println("stop");
      brake();
    }
  }
  else
  {
    Serial.println("go ahead");
    go_ahead();
  }
}

void go_ahead() {
  // Motor channel A
  digitalWrite(12, HIGH); // forward direction
  digitalWrite(9, LOW);  // disengage brake
  analogWrite(3, 200);  // speed
  
  // Motor channel B
  digitalWrite(13, HIGH);  // forward direction
  digitalWrite(8, LOW);  // disengage brake
  analogWrite(11, 200); // speed
}

void turn_left() {
  // Motor channel A
  digitalWrite(12, LOW); // backward direction
  digitalWrite(9, LOW);  // disengage brake
  analogWrite(3, 200);  // speed
  
  // Motor channel B
  digitalWrite(13, HIGH);  // forward direction
  digitalWrite(8, LOW);  // disengage brake
  analogWrite(11, 200); // speed
  
  delay(200);
  brake();
}

void turn_right() {
  // Motor channel A
  digitalWrite(12, HIGH); // forward direction
  digitalWrite(9, LOW);  // disengage brake
  analogWrite(3, 200);  // speed
  
  // Motor channel B
  digitalWrite(13, LOW);  // backward direction
  digitalWrite(8, LOW);  // disengage brake
  analogWrite(11, 200); // speed
  
  delay(200);
  brake();
}

//void turn_back(char dir) {
//  /* Turn the robot 180 degree */
//  if (dir == "left")
//  {
//    turn_left();
//    turn_left();
//  }
//  else if (dir == "right")
//  {
//    turn_right();
//    turn_right();
//  }
//}

void brake() {
  digitalWrite(9, HIGH);  // engage brake of channel A
  digitalWrite(8, HIGH);  // engage brake of channel B
}
