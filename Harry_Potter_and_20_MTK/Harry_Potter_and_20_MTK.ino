#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo_shoot;
int motor1 = 5;  // motor left
int motor2 = 6;   //motor right
char bl_state;
int state = 0;
void setup() {
  servo_shoot.attach(3);  // (servo shoot pin 3)
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600);
}

void servo(){
  if (state == 1){
    servo_shoot.write(90);
    state = 0;
  }
  else {
    servo_shoot.write(0);
    state = 1;
  }
}
void stop(){
  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
}

void loop() {

  if (Serial.available() > 0) {
    bl_state = Serial.read();

    if (bl_state == 'F') {  //Forward
      analogWrite(motor1, 255);
      analogWrite(motor2, -255);
      delay(70);
      stop();      
    }
    if (bl_state == 'B') {  //Backward
      analogWrite(motor1, -255);
      analogWrite(motor2, 255);
      delay(70);
      stop();
    }
    if (bl_state == 'R') {   //Right
      analogWrite(motor1, 255);
      analogWrite(motor2, 255);
      delay(70);
      stop();
    }
    if (bl_state == 'L') {  //Left
      analogWrite(motor1, -255);
      analogWrite(motor2, -255);
      delay(70);
      stop();
    }
    if (bl_state == 'S') {   // shoot
      servo();
      }
 }
}
