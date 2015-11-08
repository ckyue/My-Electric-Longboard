#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
int analogPin = A0;     // potentiometer wiper (middle terminal) connected to analog pin 3
int readin = 0;           // variable to store the value read
int sendto = 0;
int motor = 10;

void setup()
{
  Serial.begin(9600);          //  setup serial
  pinMode(analogPin,INPUT);
  myservo.attach(motor,1000,2000);//号引脚输出私服电机控制信号

}

void loop()
{
  readin = analogRead(analogPin);    // read the input pin
  //Serial.println(readin);             // debug value
  sendto = map(readin, 0, 1023, 0, 150); // 利用“map”函数缩放该值，得到伺服电机需要的角度（0到180之间）
  myservo.write(sendto);                  // sets the servo position according to the scaled value 
  Serial.println(sendto);             // debug value
  delay(50);

  
}
