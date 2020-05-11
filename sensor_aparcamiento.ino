#include<Servo.h>
Servo myServo;
const int ECHOgreen=13;
const int TRIGgreen=12;
const int buzz=8;
const int BLUEled=7;
const int REDled=6;
const int YELLOWled=5;
const int GREENled=4;//asigno el led a una entrada de la placa, en este caso a la numero 3 de la parte digital, si fuera a la analogica, pondría A3.
const int TRIGred=10;
const int ECHOred=9;
int duracion_red;
int distancia_red;
int distancia_green;
int duracion_green;
int angle;

void setup() {
  pinMode(TRIGred, OUTPUT);//el pin trig es receptor desde la placa
  pinMode(ECHOred, INPUT);//el pin echo actua como emisor hacia la placa
  pinMode(REDled, OUTPUT);
  pinMode(GREENled, OUTPUT);
  pinMode(YELLOWled, OUTPUT);
  pinMode(BLUEled, OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(TRIGgreen, OUTPUT);
  pinMode(ECHOgreen, INPUT);
  myServo.attach(11);
  Serial.begin(9600);//esta funcion establece la comunicación entre el arduino y el ordenador, a 9600 bytes por segundo.
}

void loop() {
 digitalWrite(buzz, LOW);
 digitalWrite(TRIGred, HIGH);//emite un pulso (manda tension al sensor)
 delay(1);//mantiene ese pulso una milesima de segundo
 digitalWrite(TRIGred, LOW);//deja de mandar tension
 digitalWrite(TRIGgreen, HIGH);
 delay(1);
 digitalWrite(TRIGgreen, LOW);
 duracion_red=pulseIn(ECHOred,HIGH);//medido en ms, devuelve un valor de tiempo, es decir, nos da el tiempo transcurrido entre la emision del pulso hasta que vuelve.
 distancia_red=duracion_red/58.2;//calcula la distancia en función de la duracion. medida en cm.
 duracion_green=pulseIn(ECHOgreen, HIGH);
 distancia_green=duracion_green/58.2;
 Serial.println(distancia_red);//funcion printline, imprime una linea.
 delay(200);//2 decimas de segundo entre impresión de una distancia y la siguiente.
  if(distancia_green<=5&&distancia_green>0)
  {
    myServo.write(180);
    delay(1000);
    myServo.write(90);
  }
 if(distancia_red<=30&&distancia_red>20)//distancia entre 20 y 10 cm
 {
  digitalWrite(GREENled,HIGH);//mandamos tensión al pin del led para que se encienda.
  digitalWrite(buzz, HIGH);
  tone(8,100,400);
  delay(400);
  digitalWrite(buzz, LOW);
  digitalWrite(GREENled, LOW);
  digitalWrite(YELLOWled,LOW);// el led amarillo se queda apagado, igual que el rojo
  digitalWrite(REDled,LOW);
  digitalWrite(BLUEled, LOW);
  
 }
 if(distancia_red<=20&&distancia_red>10)
 {
  digitalWrite(GREENled,HIGH);
  digitalWrite(YELLOWled,HIGH);
  digitalWrite(buzz, HIGH);
  tone(8,200,300);
  delay(200);
  digitalWrite(buzz, LOW);
  digitalWrite(GREENled,LOW);
  digitalWrite(YELLOWled,LOW);
  digitalWrite(REDled, LOW);
  digitalWrite(BLUEled, LOW);
 }
 if(distancia_red<=10&&distancia_red>5)
 {
  digitalWrite(GREENled,HIGH);
  digitalWrite(YELLOWled,HIGH);
  digitalWrite(REDled,HIGH);
  digitalWrite(BLUEled, LOW);
  digitalWrite(buzz, HIGH);
  tone(8,300,100);
  delay(100);
  digitalWrite(buzz, LOW);
  digitalWrite(GREENled,LOW);
  digitalWrite(YELLOWled,LOW);
  digitalWrite(REDled, LOW);
  digitalWrite(BLUEled,LOW);
 }
 if(distancia_red<=5&&distancia_red>0)
 {
  digitalWrite(GREENled,HIGH);
  digitalWrite(YELLOWled,HIGH);
  digitalWrite(REDled,HIGH);
  digitalWrite(BLUEled, HIGH);
  digitalWrite(buzz, HIGH);
  tone(8,400,0);
  delay(1);
  digitalWrite(buzz, LOW);
  delay(1);
  
  
 }
}
