#include <LiquidCrystal.h>
LiquidCrystal lcd (4,5,8,9,10,12);
#include <Servo.h>
Servo myservo ;
int l1;
int r1;
int pos;
void setup() { 
  //left sensor output to arduno input 
  pinMode(7,INPUT); 
  //Right Sensor output to arduino input 
  pinMode(6,INPUT); 
  //output from audrino to motor drive 
  //Right motor audrino to motor Drive 
  pinMode(0,OUTPUT); 
  pinMode(1,OUTPUT); 
  //left Motor Arduino motor Drive 
  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT); 
  lcd.begin(16,2);
 lcd.setCursor(0,0); //goto first column (column 0) and first line (Line 0)

lcd.print("Swach Bharat BOT"); //Print at cursor Location

lcd.setCursor(0,1); //goto first column (column 0) and second line (line 1)

lcd.print("State="); //Print at cursor location
 myservo.attach (11);


}

  void loop() { 
    //left sensor input 
    int l1=digitalRead(7); 
    //Right Sensor Input 
    int r1=digitalRead(6); 
    if((l1==HIGH)&&(r1==HIGH)) 
    { 
        //Stop the Boot
         digitalWrite(0,LOW);
         digitalWrite(1,HIGH); 
         digitalWrite(2,LOW); 
         digitalWrite(3,HIGH);
        lcd.setCursor(6,1);
        lcd.print("going Fwd ");  
    } else if((l1==LOW)&&(r1==HIGH)) {
        //turns left
     
        digitalWrite(0,HIGH); 
        digitalWrite(1,LOW); 
        digitalWrite(2,LOW); 
        digitalWrite(3,HIGH); 
           lcd.setCursor(6,1);
           lcd.print("trng left ");
    } else if((l1==HIGH)&&(r1==LOW)) {
          //turns right
         
          digitalWrite(0,LOW); 
          digitalWrite(1,HIGH); 
          digitalWrite(2,HIGH); 
          digitalWrite(3,LOW); 
             lcd.setCursor(6,1);
             
             lcd.print("trng right");
    } else if((l1==LOW)&&(r1==LOW)) {
         
 
        digitalWrite(0,LOW);
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
      lcd.setCursor(6,1);
          lcd.print("stopping  "); 
    }
    for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 }
