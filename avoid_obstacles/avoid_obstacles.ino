int analogPin = 1;
int val = 0;
  
void setup() {
  // setup motor channels
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  val = analogRead(analogPin);
  if (val >= 30)
  {
    brake();
  }
  else
  {
    go_ahead();
  }
}

void go_ahead() {
  // Motor channel A
  digitalWrite(12, LOW); // forward direction
  digitalWrite(9, LOW);  // disengage brake
  analogWrite(3, 123);  // speed
  
  // Motor channel B
  digitalWrite(13, LOW);  // forward direction
  digitalWrite(8, LOW);  // disengage brake
  analogWrite(11, 123); // speed
}

void brake() {
  digitalWrite(9, HIGH);  // engage brake of channel A
  digitalWrite(8, HIGH);  // engage brake of channel B
}
