int en1=11;
int in1=8;
int in2=7;
int f1s=13;
int f2s=12;
int f3s=4;
int f1led=10;
int f2led=9;
int f3led=6;

void setup()
{ pinMode(f1s, INPUT); //inputs for switches
  pinMode(f2s, INPUT);
  pinMode(f3s, INPUT);
 
  pinMode(f1led, OUTPUT); //output of led
  pinMode(f2led, OUTPUT);
  pinMode(f3led, OUTPUT);
 
  analogWrite(f1led,0);  //intializing the led to 0 brightness
  analogWrite(f2led,0);
  analogWrite(f3led,0);
 
  pinMode(en1, OUTPUT); //enable pin
  pinMode(in1, OUTPUT); //input pin
  pinMode(in2, OUTPUT);
 
  digitalWrite(in1,LOW); //setting the elevator at rest
  digitalWrite(in2,LOW); 
 
 
  Serial.begin(9600);
  
}



void loop()
{static int floor=1; //initial floor is 1
 int floor1=digitalRead(f1s); //switches reading the selection of floor
 int floor2=digitalRead(f2s); 
 int floor3=digitalRead(f3s); 
 
 //when 1st floor is pressed
 if((floor1== HIGH)&&(floor2==LOW)&&(floor3==LOW))
 {
  while(floor>1)
  {analogWrite(en1,225);
   digitalWrite(in1,HIGH); 
   digitalWrite(in2,LOW);
   delay(900);
   floor-=1;
  } 
  if(floor==1)
 { 
    Serial.println("`1st FLOOR");
    analogWrite(f1led,225); 
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);  //motor stops 
    delay(1000);} }
 
  //when 2nd floor is pressed
  if((floor2== HIGH)&&(floor1==LOW)&&(floor3==LOW))
 {
   while(floor<2) // if the elevator is on floor 1
 {analogWrite(en1,225);
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   floor+=1;
  delay(900); 
  }  
   while(floor>2) //if the elevator is on floor 3
  {analogWrite(en1,225);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   delay(900);
   floor-=1;
  } 
    
  if(floor==2)
  { Serial.println(" 2nd FLOOR");  
   analogWrite(f2led,225);
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);  //motor stops 
   delay(1000);} }

  if((floor3==HIGH)&&(floor1==LOW)&&(floor2==LOW))
    
  {
    while(floor<3)
  {analogWrite(en1,225);
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   floor+=1;
   delay(900);}
    
   if(floor==3)
   { Serial.println("3rd FLOOR"); 
    analogWrite(f3led,225);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW); //motor stops 
    delay(1000);}}  
   
   if(((floor1==HIGH)&&(floor2==HIGH)&&(floor3==LOW))||
      ((floor1==HIGH)&&(floor2==LOW)&&(floor3==HIGH))||
      ((floor1==LOW)&&(floor2==HIGH)&&(floor3==HIGH))||
      ((floor1==HIGH)&&(floor2==HIGH)&&(floor3==HIGH)))
   {Serial.println("PRESS A SINGLE FLOOR");
    delay(2000);}
   
  
   analogWrite(f1led,0);
   analogWrite(f2led,0);
   analogWrite(f3led,0);
  
  }
 