#include <Servo.h>

char myData[30] = {0};

int x;
int y;

Servo myservox;
Servo myservoy;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(1);
  
}

void loop()
{
  while(!Serial.available());

  Serial.print(analogRead(A0));
  delay(15);
}