#include <Servo.h>
#include <Stepper.h>
#define BEEPER 12

const int SPR= 200;

Servo myservo;
Stepper mystepper(SPR, 8, 9, 10, 11);
int rudder= 0;
int sheets= 0;
int pin1 = 1;
int pin2 = 2;
byte incomingByte;
int count;
int i = 0;

void setup() {
  mystepper.setSpeed(60);
  myservo.attach(6);
  Serial.begin(9600);
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  pinMode(BEEPER, OUTPUT);
}

void loop() {

  if(digitalRead(pin1) == HIGH){
    tone(BEEPER,150,1000);
    Serial.write("Count = " + count);
    while(true){}
  }
  else if(digitalRead(pin2) == HIGH){
    tone(BEEPER,150,1000);
    Serial.write("Count = " + count);
    while(true){}
  }

  if(i = 1 && sheets>=10){
    sheets-=10;
    mystepper.step(50);
    if(sheets == 0){
      i = 0;
      count++;
    }
  }
  else if(i==0 && sheets<=290){
    sheets+=10;
    mystepper.step(-50);
    if(sheets == 300){
      i = 1;
      count++;
    }
  }
}

