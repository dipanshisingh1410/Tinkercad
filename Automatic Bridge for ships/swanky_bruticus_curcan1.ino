int red=13; 
int green= 12; 
int en1=8; 
int en2=2; 
int in1=6; 
int in2=5; 
int in3=11; 
int in4=10; 
int height=7; 
int distance=4;   

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT); 
  
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT); 
  
  Serial.begin(9600);  
  analogWrite(in1,0); 
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,0); 
  digitalWrite(red,LOW);
  digitalWrite(in1,LOW); 
  digitalWrite(en1,HIGH); 
  digitalWrite(en2,HIGH);
    
}

void loop()
{ 
  pinMode(height, OUTPUT);
  digitalWrite(height, LOW);
  delayMicroseconds(2);
  digitalWrite(height, HIGH);
  delayMicroseconds(10);
  digitalWrite(height, LOW);
 
  pinMode(height, INPUT);
  long time = pulseIn(height,HIGH); 
  //calculating height with the vertical sensor. 
  float dis=time*0.0167; 
  {Serial.println("height:"); 
   Serial.println(dis,2); } 
   delay(2000); 
  
   pinMode(distance, OUTPUT);
  digitalWrite(distance, LOW);
  delayMicroseconds(2);
  digitalWrite(distance, HIGH);
  delayMicroseconds(10);
  digitalWrite(distance, LOW); 
  
   pinMode(distance, INPUT);
   long time2= pulseIn(distance,HIGH); 
  //calculating distance with horizontal sensor. 
  float dis2=time2*0.0167; 
  { Serial.println("distance:"); 
   Serial.println(dis2,2);}
     delay(2000); 
 
 
  if(dis2<=20)
  {
   
    Serial.println("Bridge is opening"); 
    delay(2000); 
    
    if (dis<=10) 
   {
    unsigned long startTime = millis();
    while (millis() - startTime <= 5000UL)
    {digitalWrite(red,HIGH);
    analogWrite(in1,0); 
    analogWrite(in2,68);
    analogWrite(in4,0); 
     analogWrite(in3,68);} } 
    
   
    if (dis>10&&dis<=20) 
   {unsigned long startTime = millis();
    while (millis() - startTime <= 5000UL)
    {digitalWrite(red,HIGH);
    analogWrite(in1,0); 
    analogWrite(in2,148);
    analogWrite(in4,0); 
     analogWrite(in3,148);}}
 
   
    if (dis>20) 
   {unsigned long startTime = millis();
    while (millis() - startTime <= 5000UL)
    { digitalWrite(red,HIGH);
    analogWrite(in1,0); 
    analogWrite(in2,225);
    analogWrite(in4,0); 
     analogWrite(in3,225);}}  
    
    digitalWrite(red,LOW); 
  
   // assuming it reaches an accurate height in 5sec 
   
   // now we need to stop the bridge there till the ship passes
   // assuming the sloest ship takes 5sec.  
    {Serial.println("Motion siezed"); 
     analogWrite(in1,0); 
     analogWrite(in2,0);
     analogWrite(in4,0); 
     analogWrite(in3,0);} 
    delay(5000); 
    // green light should turn on immediatly
 
    Serial.println("Ship has left");
    delay(2000);
    
   // bringing the bridge back to its position 
    
    if (dis<=10)
   {unsigned long startTime = millis();
    while (millis() - startTime <= 5000UL)
    { digitalWrite(green,HIGH);
    analogWrite(in2,0); 
    analogWrite(in1,68);
    analogWrite(in3,0); 
     analogWrite(in4,68);} }
   
  
    if (dis>10&&dis<=20) 
   {unsigned long startTime = millis();
    while (millis() - startTime <= 5000UL)
    {digitalWrite(green,HIGH);
    analogWrite(in2,0); 
    analogWrite(in1,148);
    analogWrite(in3,0); 
     analogWrite(in4,148);}}
   

    if (dis>20) 
   {unsigned long startTime = millis();
    while (millis() - startTime <= 5000UL)
    { digitalWrite(green,HIGH);
    analogWrite(in2,0); 
    analogWrite(in1,225);
    analogWrite(in3,0); 
     analogWrite(in4,225);} }
    
    digitalWrite(green,HIGH);
  
    analogWrite(in1,0); 
    analogWrite(in2,0);
    analogWrite(in4,0); 
    analogWrite(in3,0);
    
    
  }  
    
  
}