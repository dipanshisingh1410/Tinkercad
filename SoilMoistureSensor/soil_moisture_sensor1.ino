#include <Servo.h>
#define servopin 5
#define sensorpin 5
Servo servo;
void setup()
{ Serial.begin(9600);
  servo.attach(servopin);
}

void loop()
{ int level; 
 level= analogRead(sensorpin);
 
 if((level<=674)&&(level>=337))
 {servo.write(30);
  Serial.println("LOW LEVEL");
  Serial.println(level);
  delay(5000);
 }
 
 if((level<337))
 {servo.write(90);
  Serial.println("VERY LOW");
  Serial.println(level);
  delay(5000);}

  if((level>674))
  {Serial.println("NO NEED TO IRRIGATE");
   Serial.println(level);
   servo.write(0);
   delay(1000);
  }
 
   }
