//PINS
//7,6- Right motor
//8,5- Left motor
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); 
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int state;
int flag=0;       
void stp();
void fwd();
void left();
void right();
void back();
void lift();
void setup()
{
    BT.begin(9600); 
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    pinMode(7,OUTPUT);                  
    pinMode(8,OUTPUT);                  
    pinMode(5,OUTPUT);                  
    pinMode(6,OUTPUT);     
    pinMode(3,OUTPUT);
    pinMode(10,OUTPUT);
    digitalWrite(3,HIGH);
    digitalWrite(10,HIGH);             
    Serial.begin(9600);                                         // Baud rate set to 9600bps
}
void loop() {
  /*fwd();
  delay(10000);
  stp();
  right();
  delay(10000);*/
  
    if (BT.available()){  //checking if user is giving command
    delay(10);
    char state = BT.read();
    flag=0;  
    } 
    if (state == '1')     // Checking Command from User
    {
        stp();
        if(flag == 0){
          Serial.println("Stop");
          flag=1;
       }
    }
    else if (state == '2')
    {
        fwd();
        if(flag == 0)
        {
          Serial.println("Forward");
          flag=1;
         }
    }
    else if (state == '3')
    {
        back();
        if(flag == 0)
        {
          Serial.println("Backward");
          flag=1;
        }
    }
    else if (state == '4')
    {
        left();
        if(flag == 0)
        {
          Serial.println("Left");
          flag=1;
         }
    }
   else if (state == '5')
  {
        right();
        if(flag == 0)
        {
          Serial.println("Right");
          flag=1;
         }
    }
    else if (state == '6')
  {
        lift();
        if(flag == 0)
        {
          Serial.println("Lift");
          flag=1;
         }
    }
    
}                                           //loop() ends here
void fwd()          // Forward
{
  digitalWrite(7,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
}
void back()          // Backward
{
  digitalWrite(8,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,HIGH);
}
void left()          //LEFT
{
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
}
void right()          // Right
{
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(6,HIGH);
}
void stp()            // Robot STops
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
}
void lift()
{
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
}
