#include "Servo.h"//引用伺服电机函数库
Servo servo;//创建一个伺服电机对象
void setup()
{
  servo.attach(10,1000,2000);//9号引脚输出私服电机控制信号
}
void loop()
{
   int V1 = analogRead(5);//读取来自可变电阻的模拟值（0到1023之间）
   int val = map(V1, 0, 1023, 0, 179); // 利用“map”函数缩放该值，得到伺服电机需要的角度（0到180之间）
   servo.write(val);// 设定伺服电机的位置
   delay(10);
 }
