

#include <Servo.h>



Servo servo1;

int ledPin = 4;
int trigPin = 2;
int echoPin = 3;
int ledPin2 = 7;
int trigPin2 = 6;
int echoPin2 = 5;
int servoPin = 9;


void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledPin2, OUTPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(ledPin2, OUTPUT);
servo1.attach(9);
 

}

void loop(){
 
int duration, distance;
digitalWrite (trigPin, HIGH);
delayMicroseconds (1);
digitalWrite (trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2)/29.1;


int duration2, distance2;
digitalWrite (trigPin2, HIGH);
 delayMicroseconds (1);
digitalWrite (trigPin2, LOW);
duration = pulseIn(echoPin2, HIGH);
distance2 = (duration/2)/29.1;

  
if(distance<200){        //It check inner distance of dustbin
    if(distance2<50){     //It check the any one come or not near dustbin
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin,LOW);
     servo1.attach(servoPin);
        delay(1);
        servo1.write(90);  
        delay(2000);       //wait 5 seconds
        servo1.write(0);    
        delay(1000);
        servo1.detach(); 
        Serial.print("Dusbin is Open\n");

   }
  }
else{
     digitalWrite(ledPin,HIGH); 
     digitalWrite(ledPin2,LOW);
     Serial.print("Dustbin is Full\n");
    
     }

 }
  
  
