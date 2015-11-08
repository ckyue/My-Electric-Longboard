#include <Servo.h>


Servo powerServo; 
int motorPin = 10; //arduino 上只能是3 5 6 9 10 11这几个 
// the setup routine runs once when you press reset:
void setup() { 

powerServo.attach(motorPin);
/*
min (optional): the pulse width, in microseconds, corresponding to the minimum (0-degree) angle on the servo (defaults to 544)
max (optional): the pulse width, in microseconds, corresponding to the maximum (180-degree) angle on the servo (defaults to 2400)
*/
Serial.begin(9600);
}
int ctrlPower = -1;


// the loop routine runs over and over again forever:
void loop() {

a:
if(Serial.available())
{
ctrlPower = Serial.read();
//there are sth wrong... arduino can only receive only 1 byte..
Serial.print("read a data: ");
Serial.println(ctrlPower);

}
if(ctrlPower == -1 )
goto a; //其实也可以某认为0，这样是为了调试方便
/*
这里需要注意一点，如果把ctrlPower弄成-1他就不会再发送了，这样电调就认为它和遥控器断开了！这样会导致电调无法启动。
*/


double T = 2000; // 一个周期的微秒值 
long t0 = micros(); //记录begin的时间 

//ctrlPower从串口读取，0~200分别对应高电平脉宽0.9ms～2.1ms 
double len = 1000 * (0.9 + ctrlPower * (2.1 - 0.9) / 200.0); //len = 0.9*1000 ~ 2.1*1000

for(int i = 0; i < 4; i++)
powerServo.writeMicroseconds(len); //这样会同时控制4个电调同时输出一样的电位

//may be we can do something here??
int leftMs = (int) (t0 + T - micros()); 
Serial.print("I'm idle when : ");
Serial.println(leftMs, 4);

//everything done...
/*
我原先的想法是在这可以做其他事情，但是考虑到如果事情没做完，但是时间到了，或者发生啥阻塞了，那不废废了？所以还是这个还是不行的。只能是先试验试验，转转电机。必须得用定时器。
*/
delayMicroseconds(leftMs);
}


