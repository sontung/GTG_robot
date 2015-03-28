/*
This sketch is for testing 5 sensors at the same time.
*/
int analogPin_sensor1 = 0;
int analogPin_sensor2 = 1;
int analogPin_sensor3 = 3;
int analogPin_sensor4 = 4;
int analogPin_sensor5 = 5;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  val = analogRead(5);
  if (val > 400)
  {
    Serial.println("dont go");
  }
  else
  {
    Serial.println("go");
  }
  delay(100);
}
