/*
Dino Chrome game automation with ArduinoUno
Created by arduiNote 
25.08.2022
*/



#include <Servo.h>

Servo myservo;                // create servo object to control the servo


int ServoValue = 100;         // position needs to be calibrated for your servo (between 0 and 180)
int SensorThreshold = 40;     // threshold needs to be calibrated for your sensor

void setup() {

  Serial.begin(9600);      // initialize serial communication at 9600 bits per second:
  myservo.attach(9);      // attaches the servo on pin 9 to the servo object
}


void loop() {

  int sensorValue = analogRead(A0);
  
  if(sensorValue > SensorThreshold){                // check if a obstacle is coming , if it is move servo forward and backward to press the button
    
     delay(400);  
      
     myservo.write(ServoValue+10);                  // sets the servo position according to the scaled value
     
     delay(100);  
     
     myservo.write(ServoValue);                    // sets the servo position according to the scaled value
     
     delay(50);  
     
    }

  Serial.println(sensorValue);
  delay(1);      
}
