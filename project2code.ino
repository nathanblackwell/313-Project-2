#include <Servo.h>

Servo myservo;


  // Pins.
const int trigPin = 11;  
const int echoPin = 12;
const int ledPin = 13;
const int buttonPin = 2;

// Variables.  
  long duration;
  float distance;
  unsigned long currentTime;
  unsigned long previousTime = 0;
  int timerLength = 2000;
  int buttonState = 0;
  int previousbuttonState = 0;
  
void setup() {
  myservo.attach(9);

  // I/O.
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

}

void loop() {
currentTime = micros();

buttonState = digitalRead(buttonPin);

    // Low for 2 ms.
  digitalWrite(trigPin, LOW);

  // High for 10 ms.
if (currentTime - previousTime >= 2) {
  digitalWrite(trigPin, HIGH);
}

// Ultrasonic code.
if (currentTime - previousTime >= 12) {
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
}
  
// Distance.
  distance = duration * 0.034 / 2;

// Serial monitor.
  Serial.print("Distance: ");
  Serial.println(distance);

// Detection.
  int minimum = 6;

// If/else.
  if (distance < minimum) {
      myservo.write(20);
  delay(1000);
  myservo.write(0);
  delay(1000);
  myservo.write(20);
  delay(1000);
  } else {
    myservo.write(0);
    } 
    if (buttonState != previousbuttonState){
    if (buttonState = HIGH){
      Serial.println("button pressed");
      digitalWrite(ledPin, HIGH);
    }else{
      Serial.println("button released");
      digitalWrite(ledPin, LOW);
    }
  } 
  previousbuttonState = buttonState;
 
  // Timer reset.
  previousTime = currentTime;
}
