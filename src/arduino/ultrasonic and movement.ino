#include <Arduino.h>
#include "Freenove_4WD_Car_For_ESP32.h"

#define OBSTACLE_DISTANCE      30
#define OBSTACLE_DISTANCE_LOW  15
int distance[4];     //Storage of ultrasonic data

String entradaSerial = "";
bool entradaCompleta = false;

void setup() {
  Ultrasonic_Setup();//Initialize the ultrasonic module
  PCA9685_Setup();   //PCA9685 chip initializes
  Serial.begin(115200);
  Serial.println("the bluetooth device is ready to pair");
  Servo_1_Angle(105);//Set servo 1 Angle
}

void loop()
{
  get_distance(1);//Get multiple Angle distance data
  if (distance[1] > OBSTACLE_DISTANCE)//There is no obstacle within 40cm of the front of the car
  {
    if (distance[0] >= distance[2] && distance[2] < OBSTACLE_DISTANCE_LOW) {    //There is an obstacle on the right
      Motor_Move(-1500, -1500, -1500, -1500);
      delay(1200);
      Servo_1_Angle(85);
      Motor_Move(2500, 2500, 2500, 2500);
      delay(1200);
      Servo_1_Angle(105);
    }                                   
    else if (distance[0] < distance[2] && distance[0] < OBSTACLE_DISTANCE_LOW) { //There is an obstacle on the left
      Motor_Move(-1500, -1500, -1500, -1500);
      delay(1200);
      Servo_1_Angle(85);
      Motor_Move(2500, 2500, 2500, 2500);
      delay(1200);
      Servo_1_Angle(105);                      
    }            
    else                                                                      //There are no obstacles around
      Motor_Move(2500, 2500, 2500, 2500);                                                                         
    delay(20);
  }

  else if (distance[1] < OBSTACLE_DISTANCE)  //There is an obstacle ahead
  {
    Motor_Move(0, 0, 0, 0);                  //Stop the car to judge the situation
    get_distance(2);
    if (distance[1] < OBSTACLE_DISTANCE_LOW) //The car got too close to the obstacle
    {
      Motor_Move(-1900, -1900, -1900, -1900);
      }
    else if (distance[0] < distance[2]) {     //There is also an obstacle on the left
      Motor_Move(-1500, -1500, -2000, -2000);
      delay(1200);
      Servo_1_Angle(85);
      Motor_Move(2500, 2500, 2500, 2500);
      delay(1200);
      Motor_Move(0, 0, 0, 0);
      Servo_1_Angle(105); 
      delay(250);         
    }
    else if (distance[0] > distance[2]) {     //There is also an obstacle on the right
     Motor_Move(-1500, -1500, -2000, -2000);
     delay(1200);
     Servo_1_Angle(85);
     Motor_Move(2500, 2500, 2500, 2500);
     delay(1200);
     Motor_Move(0, 0, 0, 0);
     Servo_1_Angle(105); 
     delay(250);         
    }
  }

  if (entradaCompleta) {
    if (entradaSerial == "izq\n") {
      delay(250);
      Serial.print("hola");
      // Mandamos escribir el angulo deseado del giro.
     // delay(3000);
 /*     Servo_1_Angle(85);
      Motor_Move(2200, 2200, 2200, 2200);
      delay(900);
      Servo_1_Angle(105); 
      delay(250); */
      Servo_1_Angle(85);
      Motor_Move(3000, 3000, 3000, 3000);
      delay(900);
      Motor_Move(0, 0, 0, 0);
      Servo_1_Angle(105); 
      delay(250); 
    }
    else if (entradaSerial == "der\n") { 
      delay(250);
      Serial.print("holaa");
      // Mandamos escribir el angulo deseado del giro.
     // delay(3000);
      Servo_1_Angle(125);
      Motor_Move(3000, 3000, 3000, 3000);
      delay(900);
      Servo_1_Angle(105); 
      Motor_Move(0, 0, 0, 0);
      delay(250);
    }
    else { // Cualquier otro dato recibido
      Serial.println("El dato recibido es lol");
    }
    entradaSerial = "";
    entradaCompleta = false;
  }

}

void get_distance(int car_mode)
{
  int add_angle=30;
  if(car_mode==1)
    add_angle=0;
  else
    add_angle=30;
    
  delay(100);
  distance[0] = Get_Sonar();//Get the data on the left

  delay(100);
  distance[1] = Get_Sonar();//Get the data in the middle

  delay(100);
  distance[2] = Get_Sonar();//Get the data on the right

  delay(100);
  distance[1] = Get_Sonar();//Get the data in the middle
}

void serialEvent() {
  while (Serial.available()) {
    // Obtener bytes de entrada:
    char inChar = (char)Serial.read();
    // Agregar al String de entrada:
    entradaSerial += inChar;
    // Para saber si el string está completo, se detendrá al recibir
    // el caracter de retorno de línea ENTER \n
    if (inChar == '\n') {
      entradaCompleta = true;
    }
  }
}
