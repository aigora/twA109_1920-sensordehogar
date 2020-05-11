#include <Adafruit_ADXL343.h>



#include <LiquidCrystal.h>


#include<DHT.h>
int temp, humedad;
const int SENSOR=2;
const int v0=3;
const int RS=4;
const int E=5;
const int D4=6;
const int D5=7;
const int D6=8;
const int D7=9;
const int LEDG=10;
const int LEDB=12;
const int LEDY=11;

DHT dht(SENSOR, DHT11);
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  analogWrite(v0,0);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDY, OUTPUT);
} 

void loop() {
  humedad=dht.readHumidity();
  temp=dht.readTemperature();
  Serial.print("temperatura: ");
  Serial.print(temp);
  Serial.println("C");
  Serial.print("humedad: ");
  Serial.print(humedad);
  Serial.println("%");
  delay(1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("humedad ");
  lcd.print(humedad);
  lcd.print("%");
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDY, LOW);
 
  if(temp>25)
  {
    digitalWrite(LEDG, HIGH);
    
  }
  if (humedad<43)
  {
    digitalWrite(LEDY, HIGH);
    delay(500);
    digitalWrite(LEDY, LOW);
    delay(500);
    
  }
  else
  {
    digitalWrite(LEDB, HIGH);
  }
  
  

}
