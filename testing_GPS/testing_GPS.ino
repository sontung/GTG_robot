void setup() {
  Serial.begin(57600); 
}
void loop() {
  if (Serial.available()) {
    #if ARDUINO >= 100 //For Arduino v1.0+
    Serial.write(Serial.read());
    #else //For Arduino v0023 or earlier
    Serial.print(Serial.read(), BYTE);
    #endif
   }
}
