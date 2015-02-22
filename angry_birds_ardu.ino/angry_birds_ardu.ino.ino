const int RIGHT = 12;
const int LEFT = 11;// the pin for the LED
const int BUTTON = 7;
const int UP = 10;
const int DOWN = 9;
int speed = 1000;// the input pin where the
// pushbutton is connected
byte incomingByte = 0;
int val = 0; // val will be used to store the state
// of the input pin
int old_val = 0; // this variable stores the previous
// value of "val"
int flying = 1; // 0 stoped - 1 flying
int flipflop=0; //


void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(RIGHT, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(DOWN, OUTPUT);
  pinMode(UP, OUTPUT);// tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // and BUTTON is an input

}


void loop(){

  if (Serial.available()>0){

      incomingByte = Serial.read(); 
       val= incomingByte-'0';  
       if (val <=5) {
        speed = 1000/val;
       }
       
       if (val == 6) {
       digitalWrite(DOWN, HIGH);
       delay(2000);
        digitalWrite(DOWN, LOW);
       }
       
        if (val == 7) {
       digitalWrite(UP, HIGH);
       delay(2000);
        digitalWrite(UP, LOW);
       }
       
  }    
  
  
  if (flying == 1) {
  
      if (flipflop==1) {
          
          digitalWrite(LEFT, LOW);
          delay(250);
          digitalWrite(RIGHT, HIGH); 
          flipflop=0;
        } else {
        
        digitalWrite(RIGHT, LOW);
        delay(250);
        digitalWrite(LEFT, HIGH);
         flipflop=1;
        }
  }
    
     delay(speed);
     
   
    

}
