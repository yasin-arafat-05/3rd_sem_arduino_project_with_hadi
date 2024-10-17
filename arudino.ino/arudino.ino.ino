#include <Servo.h>

Servo myServo;
int servoPin = 9;   // Pin for the servo motor
int speakerPin = 8; // Pin for the speaker

void setup() {
  myServo.attach(servoPin);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("OPEN")) {
      myServo.write(90); // Rotate servo to open the door
      delay(10000);      // Keep it open for 10 seconds
      myServo.write(0);  // Close the door

      // Announce the user's name
      String name = command.substring(5); // Get the name after "OPEN "
      announceName(name);
    }
  }
}

void announceName(String name) {
  // Simple tone generation for the speaker
  for (int i = 0; i < name.length(); i++) {
    tone(speakerPin, 1000); // Play tone
    delay(500);             // Duration of the tone
    noTone(speakerPin);     // Stop tone
    delay(100);             // Short pause between tones
  }
}
