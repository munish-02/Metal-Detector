const int hallPin = A0;   
const int ledPin =  13;    
int hallState = 0;         
int metal=0;
int prev =0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      
  pinMode(hallPin, INPUT);    
  pinMode(A0,INPUT); 
}
void loop(){
 Serial.println(analogRead(A0));
 hallState = digitalRead(hallPin);
  if (hallState == LOW) {     
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
  if(analogRead(A0)>prev+10)
   { 
    
    metal=0;
   }
   else 
   {
   }
   if((analogRead(A0)-prev>20)||(prev-analogRead(A0)>20))
   {
    Serial.println("Metal Detected ! ");
   }
  prev=analogRead(A0);
  delay(500);
}
