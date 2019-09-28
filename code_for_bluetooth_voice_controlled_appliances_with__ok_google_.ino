 String voice;

#define FAN 10
#define TUBELIGHT 9
#define BULB 8

void setup() 
{                                            // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(FAN, OUTPUT);
  pinMode(TUBELIGHT, OUTPUT);
  pinMode(BULB, OUTPUT);
   analogWrite(TUBELIGHT,255);                    // Since LED must be off in the beginning
   analogWrite(FAN,255);
   digitalWrite(BULB,HIGH);
}

void loop() {
 
  while (Serial.available())   //Check if there is an available byte to read
  {                            
  delay(10);                   //Delay added to make thing stable
  char c = Serial.read();      //Conduct a serial read
  if (c == '#') {break;}       //Exit the loop when the # is detected after the word
  voice += c;                  //Shorthand for voice = voice + c
  } 

  if (voice.length() > 0) {
    Serial.println(voice);
  //----------Control Multiple Pins/ LEDs----------// 

       if(voice == "tubelight")//                             
     {
     analogWrite(TUBELIGHT,0); 
     analogWrite(FAN,255);
     digitalWrite(BULB,HIGH);
     }  
  else if(voice == "green")//                              
     {
    analogWrite(TUBELIGHT,255);
    analogWrite(FAN,255);
    digitalWrite(BULB,HIGH);
     }
  else if(voice == "fan")//                              
     {
    analogWrite(TUBELIGHT,255);
    analogWrite(FAN,0);
    digitalWrite(BULB,HIGH);
     }

      else if(voice == "bulb")//                                
     {
    analogWrite(TUBELIGHT,0);
    analogWrite(FAN,255);
    digitalWrite(BULB,LOW);
     }

       else if(voice == "go")//                                
     {
    digitalWrite(BULB,HIGH);
     }
  else if(voice == "lights")//                               
     {
    analogWrite(TUBELIGHT,0);
    analogWrite(FAN,0);
    digitalWrite(BULB,LOW);
     }
   else if(voice == "good night")//                         
     {
    analogWrite(TUBELIGHT,255);
    analogWrite(FAN,255);
    digitalWrite(BULB,HIGH);
     }
  
voice="";                                                       //Reset the variable after initiating
  }}

