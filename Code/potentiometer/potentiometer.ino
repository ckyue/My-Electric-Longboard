#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

void setup() 
{ 
  myservo.attach(9,1000,2000);  // attaches the servo on pin 9 to the servo object 
  delay(2500);
  myservo.writeMicroseconds(1500);
  delay(2000);
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 999, 2001);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 


