#define LEDPIN 10 
#define BUZZER 13 
 
void setup()
{
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZER,OUTPUT); 
  
  analogWrite(LEDPIN,0); //initializing to low
  digitalWrite(BUZZER,LOW);
  
  Serial.begin(9600); 
}

void loop()
{
 
  int index=-1;int i;
  //defining array of characters and morse code in sequence. 
  char characters[]=
 {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
  'Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5',
  '6','7','8','9','.','-',',','?','\'','!','/','(',')','&',
  ':',';','=','+','-','_','@','$'
}; //character array
 
  String morse[]={ ".-", "-...", "-.-.", "-..",".", "..-.",
                       "--.","....", "..",".---", "-.-", ".-..", 
                       "--", "-.",
                 "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                 "...-", ".--", "-..-", "-.--", "--..","-----",
                 ".----", "..---", "...--", "....-", ".....",   
                 "-....", "--...", "---..", "----.",".-.-.-", 
                 "--..--", "..--..", ".----.", "-.-.--", "-..-.",
                 "-.--.", "-.--.-", ".-...", "---...", "-.-.-.",
                 "-...-",".-.-.", "-....-", "..--.-", "...-..-",
                 ".--.-." };//string array
  
   const char input=Serial.read(); //taking char input from user
    
    for(i=0;i<(sizeof(characters)/sizeof(characters[0]));i++)
    if(characters[i]==input)
      index=i;//choosing which char matches with the entered char 
      
    String code=morse[index]; //saving corresponding string
   
    for(i=0;i<code.length();i++)
    {
      if(code[i]=='.')
    {Serial.println('.');
     analogWrite(LEDPIN,225);  
     digitalWrite(BUZZER,HIGH); 
     delay(200); 
     digitalWrite(BUZZER,LOW);
     analogWrite(LEDPIN,0); 
     delay(2000); 
     
     }
      
     if(code[i]=='-')
    {Serial.println('-');
     analogWrite(LEDPIN,225); 
     digitalWrite(BUZZER,HIGH); 
     delay(600);
     digitalWrite(BUZZER,LOW);
     analogWrite(LEDPIN,0); 
     delay(2000); 
     } 
     
     }
  delay(3000);//if we type a word, then gap for each char
}