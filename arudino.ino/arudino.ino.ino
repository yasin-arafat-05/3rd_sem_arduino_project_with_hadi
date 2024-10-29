#include<Servo.h>

Servo myServo;
int servoPin = 9;  
int led_person_detected_pin  = 8;
int led_person_wrong_pin = 7;

void setup() {
  myServo.attach(servoPin);
  myServo.write(70);
  pinMode(led_person_detected_pin,OUTPUT);
  pinMode(led_person_wrong_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("OPEN")) {
      myServo.write(150); 
      digitalWrite(led_person_detected_pin,HIGH);
      delay(10000);     
      myServo.write(70);
      digitalWrite(led_person_detected_pin,LOW);
    }

    if(command.startsWith("Wrong")){
      digitalWrite(led_person_wrong_pin,HIGH);
      delay(100);
      digitalWrite(led_person_wrong_pin,LOW);
    }
  }
}
