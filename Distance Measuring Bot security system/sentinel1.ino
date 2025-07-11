#include<Servo.h>

Servo servo_ele; 
Servo servo_azi;

int m1_in1=5; 
int m1_in2=6;
int m2_in1=9; 
int m2_in2=10; 
int en1=4; 
int en2=7; 
int a=13; 
int b=12; 
int c=11; 
int d=8; 
int sensor_front=A1; 
int sensor_back=A2; 
int buzzer=A3;  
int servo_elevation=2; 
int servo_azimuth=3; 
int power=A0; 
int caution_red=A5; 
int caution_yellow=A4;

void setup()
{ Serial.begin(9600); 
  pinMode(m1_in1, OUTPUT);
  pinMode(m1_in2, OUTPUT);
  pinMode(m2_in1, OUTPUT);
  pinMode(m2_in2, OUTPUT);
  pinMode(en1,OUTPUT); 
  pinMode(en2,OUTPUT); 
  pinMode(a,INPUT); 
  pinMode(b,INPUT);
  pinMode(c,INPUT);
  pinMode(d,INPUT); 
  pinMode(buzzer,OUTPUT);
  pinMode(caution_red,OUTPUT);
  pinMode(caution_yellow,OUTPUT);
  servo_ele.attach(servo_elevation); 
  servo_azi.attach(servo_azimuth);
  digitalWrite(caution_yellow,LOW); 
  digitalWrite(caution_red,LOW);  
  
  digitalWrite(en1,HIGH); 
  digitalWrite(en2,HIGH);  
  
  digitalWrite(buzzer,LOW); 
}

void loop()
{ //voltage analysis
  int value=analogRead(power); 
  float percentage=(value/1023.0)*100.0; 
  Serial.println("Voltage %="); 
  Serial.println(percentage);
  
  if(percentage<=10)
  batterylow(); 
  
  else if(percentage>10)
  {//yellow light will glow of not
   digitalWrite(caution_red,LOW);
    
   if(percentage<=30)
   {digitalWrite(caution_yellow,HIGH); } 
    
   //distance measurement 
  pinMode(sensor_front, OUTPUT);
  digitalWrite(sensor_front, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor_front, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor_front, LOW);
 
  pinMode(sensor_front, INPUT);
  long time = pulseIn(sensor_front,HIGH); 
  //calculating height with the vertical sensor. 
  float dis=time*0.0167; 
  {Serial.println("front distance:"); 
   Serial.println(dis,2); } 
   delay(2000); 
  
   pinMode(sensor_back, OUTPUT);
  digitalWrite(sensor_back, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor_back, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor_back, LOW); 
  
   pinMode(sensor_back, INPUT);
   long time2= pulseIn(sensor_back,HIGH); 
  //calculating distance with horizontal sensor. 
  float dis2=time2*0.0167; 
  { Serial.println("back distance:"); 
   Serial.println(dis2,2);}
     delay(2000);  
  
  if(dis<=30||dis2<=30)
  { Serial.println("DEFENCE MODE"); 
    delay(2000);
  digitalWrite(buzzer,HIGH); 
   digitalWrite(m1_in1,LOW); 
  digitalWrite(m1_in2,LOW); 
  digitalWrite(m2_in1,LOW); 
  digitalWrite(m2_in2,LOW);
   
  if (dis>dis2)
  {servo_azi.write(100+2.5*dis);
   servo_ele.write(random(0,180));
   delay(1000); 
  }
  if(dis<dis2)
  {servo_azi.write(50-dis2);
   servo_ele.write(random(0,180));
   delay(1000); 
  } 
  if(dis==dis2)
  {servo_azi.write(30);
   servo_ele.write(random(0,180));
   delay(1000); 
  } 
  }   
 
  
 if(dis>30&&dis2>30)
  { digitalWrite(buzzer,LOW); 
   servo_azi.write(0); 
   servo_ele.write(0);
 int a_state=digitalRead(a); 
 int b_state=digitalRead(b); 
 int c_state=digitalRead(c); 
 int d_state=digitalRead(d); 
 
 if(a_state==LOW&&b_state==LOW&&c_state==LOW&&d_state==LOW)
 {digitalWrite(m1_in1,LOW); 
  digitalWrite(m1_in2,LOW); 
  digitalWrite(m2_in1,LOW); 
  digitalWrite(m2_in2,LOW);
 } 
 
 else 
 {if(a_state==HIGH)
 { 
  digitalWrite(m1_in1,HIGH); 
  digitalWrite(m1_in2,LOW); 
  digitalWrite(m2_in1,LOW); 
  digitalWrite(m2_in2,HIGH);
  Serial.print("FORWARD"); 
  delay(2000);
 }
 if(b_state==HIGH)
 {digitalWrite(m1_in1,LOW); 
  digitalWrite(m1_in2,HIGH); 
  digitalWrite(m2_in1,HIGH); 
  digitalWrite(m2_in2,LOW);
  Serial.print("BACKWARD"); 
  delay(2000);
 } 
 if(c_state==HIGH)
 {digitalWrite(m1_in1,LOW); 
  digitalWrite(m1_in2,LOW); 
  digitalWrite(m2_in1,LOW); 
  digitalWrite(m2_in2,HIGH);
  Serial.print("CLOCKWISE"); 
  delay(2000);
 }  
 if(d_state==HIGH)
 {digitalWrite(m1_in1,HIGH); 
  digitalWrite(m1_in2,LOW); 
  digitalWrite(m2_in1,LOW); 
  digitalWrite(m2_in2,LOW);
  Serial.print("ANTICLOCKWISE"); 
  delay(2000);
 } } 
  }}
}
void batterylow() 
  {digitalWrite(m1_in1,LOW); 
   digitalWrite(m1_in2,LOW); 
   digitalWrite(m2_in1,LOW); 
   digitalWrite(m2_in2,LOW);
   digitalWrite(buzzer,LOW); 
   digitalWrite(caution_red,HIGH);
   digitalWrite(caution_yellow,LOW);}
