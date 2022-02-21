#include <Servo.h>                                        //library for servo motor
Servo servo1;                                                 //create servo 1 object to control a servo
int trigPin = 9;                                                //declare the pin which we use in our project for output
int echoPin = 8;                                             //declare the pin which we use in our project for input
long distance;
long duration;
void setup()
{
servo1.attach(7);                                            //servo 1 connect in 7 no pin
 pinMode(trigPin, OUTPUT);                      //output pin number input function
 pinMode(echoPin, INPUT);                        // input pin number input function
}
void loop()
{
  ultra_sonic();
  servo1.write(90);                                       //the indicator was in 90 degree angle
  if(distance <=9)
  {
  servo1.write(270);                                      //if object distance less than or equal 9cm indicator shift
  }	//270 degree
}
void ultra_sonic()
{
  digitalWrite(trigPin, LOW);                        //This function put the trigpin low pulse
  delayMicroseconds(2);                                 //low pulse stage remain for 2 ms
  digitalWrite(trigPin, HIGH);                        //This function put the trigpin high pulse
  delayMicroseconds(10);                               //high pulse stage remain for 10 ms
  digitalWrite(trigPin, LOW);                         //This function put the trigpin low pulse
  duration = pulseIn(echoPin, HIGH);        //pulse in function detect pulse time and save it to duration
  distanceCm = duration*0.034/2;                     //distance=speed*time
  }

