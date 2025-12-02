#include<Servo.h>
Servo s1, s2, s3;
int count1,count2 = 0;
int x,y;
void setup() {
  s1.attach(4); //shoulder
  s2.attach(5); //elbow
  s3.attach(6); //claw
  pinMode(1, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(A2, INPUT); //vertical component joystick
  pinMode(A3, INPUT); //horizontal component joystick
}
//Loop program to allow joystick to move Arm in different ways
void loop() {
  x = analogRead(A3);
  y = analogRead(A2);
  if (x<250) //right
  {
    s3.write(90); //claw open
  }
  if (x>750) //left
  {
    s3.write(20); //claw closed
  }
  if (y<250) //down
  {
    s1.write(90);
    s2.write(180);
  }
  if (y>750) //up)
  {
    s1.write(180);
    s2.write(90);
  }

  if (digitalRead(0)==1){
    count2++;
    delay(10);
  }
  if (count2 == 1){//anticlockwise
    for (int i=1;i<=128;i++)
  {
    step1();
    step2();
    step3();
    step4();
  }
  }
  if (count2 == 2){//clockwise
    for (int i=1;i<=128;i++)
  {
    step4();
    step3();
    step2();
    step1();
    count2 = 0;
  }
  }   

}
void step1(){
  digitalWrite(12, 1);
  digitalWrite(13, 0);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  delay(5);
}
void step2(){
  digitalWrite(12, 0);
  digitalWrite(13, 1);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  delay(5);
}
void step3(){
  digitalWrite(12, 0);
  digitalWrite(13, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  delay(5);
}
void step4(){
  digitalWrite(12, 0);
  digitalWrite(13, 0);
  digitalWrite(14, 1);
  digitalWrite(15, 0);
  delay(5);
}

