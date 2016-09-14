/*
  HC-SR04 Ping distance sensor:
  VCC to arduino 5v
  GND to arduino GND
  Echo to Arduino pin 7
  Trig to Arduino pin 8

  This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
  Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
  And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
  on 10 Nov 2012.
*/
#include <Servo.h>

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define servoPin 9 // Onboard LED
#define LEDPin 13 // Onboard LED

#define persionOutPin 10
#define persionInPin 11

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int ob_present = 0;
int ob_absent = 0;

Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
  pinMode(persionOutPin, OUTPUT);
  pinMode(persionInPin, OUTPUT);
  myservo.attach(servoPin);
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;

  if (distance >= maximumRange || distance <= minimumRange) {
    /* Send a negative number to computer and Turn LED ON
      to indicate "out of range" */
    distance = -1;
    //Serial.println("-1");
    digitalWrite(LEDPin, HIGH);
  }
  else {
    /* Send the distance to the computer using Serial protocol, and
      turn LED OFF to indicate successful reading. */
    //Serial.println(distance);
    digitalWrite(LEDPin, LOW);
  }

  if (distance > 10 && distance < 100) {
    if (ob_present < 100)
      ob_present += 1;
    if (ob_present > 1) {
      myservo.write(30);
      ob_absent = 0;
    }
  }
  else if (distance >= 100) {
    if (ob_absent < 100)
      ob_absent += 1;
    if (ob_absent > 3) {
            
      if (ob_present > 3){
        Serial.println("Person Check-In");
        digitalWrite(persionInPin, HIGH);
        digitalWrite(persionInPin, LOW);
      }
      else if (ob_present > 1){
        Serial.println("Person Check-Out");
        digitalWrite(persionOutPin, HIGH);
        digitalWrite(persionOutPin, LOW);
      }
        
      myservo.write(0);
      ob_present = 0;
    }
  }

  //Delay 50ms before next reading.
  delay(100);
}
