   ////////////////////////////////////////////////////////
  //                LinoBot v1.0                        //             
 //               By Aarav Garg                        //
////////////////////////////////////////////////////////

//I have added the possibilities of testing
//The values of analogRead could be changed for trouble shooting

//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define lefts A4 
#define rights A5 

//defining motors
AF_DCMotor motor1(4, MOTOR12_1KHZ); 
AF_DCMotor motor2(3, MOTOR12_1KHZ);

AF_DCMotor motor3(2, MOTOR34_1KHZ);
AF_DCMotor motor4(1, MOTOR34_1KHZ);

//int calibragem = 990; // 990]

void setup() {
  //setting the speed of motors
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.print("Sensor left: ");
  Serial.println(digitalRead(lefts));
  Serial.print("Sensor right: ");
  Serial.println(digitalRead(rights));
  //line detected by both
  if(digitalRead(lefts)==0 && digitalRead(rights)==0){
    //stop
    motor1.setSpeed(60);
    motor2.setSpeed(60);
    motor3.setSpeed(60);
    motor4.setSpeed(60);
    motor1.run(FORWARD);
    motor3.run(BACKWARD);
    motor2.run(FORWARD);
    motor4.run(BACKWARD);
  }
  //line detected by left sensor
  else if(digitalRead(lefts)==0 && digitalRead(rights)==1){
    //turn left
    Serial.println("turn left");
    motor1.setSpeed(60);
    motor2.setSpeed(90);
    motor3.setSpeed(90);
    motor4.setSpeed(60);
    motor1.run(BACKWARD);
    motor3.run(BACKWARD);
    motor2.run(FORWARD);
    motor4.run(FORWARD);
  
  }
  //line detected by right sensor
  else if(digitalRead(lefts)==1 && digitalRead(rights)==0){
    //turn right
    motor1.setSpeed(90);
    motor2.setSpeed(60);
    motor3.setSpeed(60);
    motor4.setSpeed(90);
    motor1.run(FORWARD);
    motor3.run(FORWARD);
    motor2.run(BACKWARD);
    motor4.run(BACKWARD);
    
    Serial.println("turn right");
  }
  //line detected by none
  else if(digitalRead(lefts)==1 && digitalRead(rights)==1){
    Serial.println("Stop");
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
  
}

