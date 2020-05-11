#include<Servo.h>
Servo myServo;
const int ECHOgreen=13;//parte echo del sensor de ultrasonido conectado al pin 13
const int TRIGgreen=12;//parte trig del sensor de ultrasonido conectado al pin 12
const int ECHOorange=3;
const int TRIGorange=2;
int angle;
int distancia_green;
int duracion_green;
int distancia_orange;
int duracion_orange;
void setup() {
  
  pinMode(TRIGgreen, OUTPUT);
  pinMode(ECHOgreen, INPUT);
  pinMode(TRIGorange, OUTPUT);
  pinMode(ECHOorange, INPUT);
  myServo.attach(11);//servo conectado al pin 11
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGgreen, HIGH);
  delay(1);
  digitalWrite(TRIGgreen, LOW);
  digitalWrite(TRIGorange, HIGH);
  delay(1);
  digitalWrite(TRIGorange, LOW);
  duracion_green=pulseIn(ECHOgreen, HIGH);
  distancia_green=duracion_green/58.2;
  duracion_orange=pulseIn(ECHOorange, HIGH);
  distancia_orange=duracion_orange/58.2;
  
  if(distancia_green<=5&&distancia_green>0&&distancia_orange>5)
  {
    myServo.write(180);
    delay(100);
  }
  if(distancia_orange<=5&&distancia_orange>0&&distancia_green>5)
  {
    myServo.write(180);
    delay(100);
  }
 if(distancia_orange>5&&distancia_green>5||distancia green<5&&distancia_orange<5)//se podría incluir para lo ultimo que los servos leyesen distancias mayores que 0 para evitar imprecisiones.
 //pero para hacer el if mas sencillo no lo añadimos, ya que el caso de distancia<0 es muy concreto.
 {
  myServo.write(90);
  delay(100);
 }
 
}
