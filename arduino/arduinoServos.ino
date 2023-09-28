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
  myservox.attach(10);
  myservoy.attach(11);
  
}

void loop()
{
  while(!Serial.available());
  
  byte m = Serial.readBytesUntil('\n', myData, 30);
  myData[m] = '\0';

  int x = atof(strtok(myData, ","));
  int y = atof(strtok(NULL, ","));

  Serial.print(x);
  Serial.print(y);

  myservox.write(x);
  myservoy.write(y);
  delay(15);
}