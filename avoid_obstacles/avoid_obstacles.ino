int analogPin_sensor1 = 0;
int sensor1 = 0;
int analogPin_sensor2 = 1;
int sensor2 = 0;
int analogPin_sensor3 = 2;
int sensor3 = 0;
int analogPin_sensor4 = 3;
int sensor4 = 0;
int analogPin_sensor5 = 5;
int sensor5 = 0;
  
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
  sensor1 = analogRead(analogPin_sensor1);
  sensor2 = analogRead(analogPin_sensor2);
  sensor3 = analogRead(analogPin_sensor3);
  sensor4 = analogRead(analogPin_sensor4);
  sensor5 = analogRead(analogPin_sensor5);
  
  Serial.println(sensor1);
  
  if (sensor1 >= 30)
  {
    if (sensor4 <= 150)
    {
      turn_right();
    }
    else if (sensor5 <= 150)
    {
      turn_left();
    }
    else
    {
      brake();
    }
  }
  else
  {
    go_ahead();
  }
}

void go_ahead() {
  /* Drive two motors in forward direction, that means the
  robot's moving forward */
  
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
  /* Drive the robot to the the left just one quarter of the
  circle */
  
  // Motor channel A
  digitalWrite(12, LOW); // backward direction
  digitalWrite(9, LOW);  // disengage brake
  analogWrite(3, 100);  // speed
  
  // Motor channel B
  digitalWrite(13, HIGH);  // forward direction
  digitalWrite(8, LOW);  // disengage brake
  analogWrite(11, 100); // speed
  
  delay(100);
  brake();
  delay(100);
}

void turn_right() {
  /* Drive the robot to the the right just one quarter of the
  circle */
  
  // Motor channel A
  digitalWrite(12, HIGH); // forward direction
  digitalWrite(9, LOW);  // disengage brake
  analogWrite(3, 100);  // speed
  
  // Motor channel B
  digitalWrite(13, LOW);  // backward direction
  digitalWrite(8, LOW);  // disengage brake
  analogWrite(11, 100); // speed
  
  delay(100);
  brake();
  delay(100);
}

void brake() {
  /* Stop both motors */
  
  digitalWrite(9, HIGH);  // engage brake of channel A
  digitalWrite(8, HIGH);  // engage brake of channel B
}
