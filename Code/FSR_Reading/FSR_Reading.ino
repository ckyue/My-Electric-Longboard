int FSR = A0;
int val;
void setup()
{
  Serial.begin(9600);
  pinMode(FSR,INPUT);
  
}

void loop()
{
  val = analogRead(FSR);
  Serial.println(val);
  delay(20);
  
}
