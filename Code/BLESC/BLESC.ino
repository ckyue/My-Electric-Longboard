#include <Servo.h>

Servo esc1;
int spd;

void setup()
{
  esc1.attach(6);
  delay(10);
  esc1.writeMicroseconds(1500);
  delay(2000);
  
}

void loop()
{
  spd = Serial.read();
  esc1.writeMicroseconds(spd);
  
}

