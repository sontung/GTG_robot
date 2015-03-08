#include <RedBot.h>
#include <RedBotSoftwareSerial.h>


RedBotEncoder encoder = RedBotEncoder(1, 2);

void setup() {
  // put your setup code here, to run once:
  encoder.clearEnc(BOTH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial.println(encoder.getTicks(LEFT));
  delay(100);
}
