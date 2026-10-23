#include <Servo.h> 
 
#define RIGHT_HAND_PIN  9 
#define LEFT_HAND_PIN   10 
#define HEAD_PIN        11 
 
Servo servoRightHand; 
Servo servoLeftHand; 
Servo servoHead; 
 
void setup() { 
  Serial.begin(9600); 
   
  servoRightHand.attach(RIGHT_HAND_PIN); 
  servoLeftHand.attach(LEFT_HAND_PIN); 
  servoHead.attach(HEAD_PIN); 
 
  // Shuru mein rest position 
  servoRightHand.write(90); 
  servoLeftHand.write(90); 
  servoHead.write(90); 
 
  Serial.println("Servo Training Mode ON!"); 
  Serial.println("Ek number bhejo (0-180) → Teeno servos us angle pe jayenge"); 
  Serial.println("Example: 0 bhejo → fully forward (agar mounting aisi hai)"); 
  Serial.println("Example: 45 bhejo → thoda up/forward"); 
  Serial.println("Example: 180 bhejo → opposite direction"); 
} 
 
void loop() { 
  if (Serial.available() > 0) { 
    String input = Serial.readStringUntil('\n'); 
    input.trim(); 
     
    if (input.length() > 0) { 
      int angle = input.toInt(); 
       
      if (angle >= 0 && angle <= 180) { 
        servoRightHand.write(angle); 
        servoLeftHand.write(angle); 
        servoHead.write(angle); 
         
        Serial.print("Servos set to: "); 
        Serial.print(angle); 
        Serial.println(" degrees"); 
      } else { 

        Serial.println("Galat angle! Sirf 0 se 180 tak bhejo."); 
      } 
    } 
  } 
}