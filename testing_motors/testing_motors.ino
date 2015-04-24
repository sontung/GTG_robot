/* This sketch if for testing to see if
the robot turn left or turn right properly */

void setup() {
  // setup motor channels
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  turn_back("left");
  delay(3000);
  turn_back("right");
  delay(3000);
}

void go_ahead() {
  // Motor channel A
  digitalWrite(12, HIGH); // forward direction
  digitalWrite(9, LOW);  // disengage brake
  analogWrite(3, 100);  // speed
  
  // Motor channel B
  digitalWrite(13, HIGH);  // forward direction
  digitalWrite(8, LOW);  // disengage brake
  analogWrite(11, 100); // speed
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

void turn_back(String dir) {
 /* Turn the robot 180 degree */
 if (dir == "left")
 {
   Serial.println("left");
   turn_left();
   turn_left();
 }
 else if (dir == "right")
 {
   Serial.println("right");
   turn_right();
   turn_right();
 }
}

void brake() {
  digitalWrite(9, HIGH);  // engage brake of channel A
  digitalWrite(8, HIGH);  // engage brake of channel B
}
