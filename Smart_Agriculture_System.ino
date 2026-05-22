#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include<DHT.h>
DHT dht(4, DHT11);
int Rain = A1;
int soil = A0;
int relay = 5;
int rain, mois, value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //value = map(rain, 0, 1023, 0, 100);
  pinMode(Rain, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(soil, INPUT);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("      SMART     ");
  lcd.setCursor(0, 1);
  lcd.print("  AGRICULTURE  ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  // value = map(rain, 0, 1023, 100, 0);
    float t = dht.readTemperature();
  float h = dht.readHumidity();
  rain = analogRead(Rain);
  mois = analogRead(soil);
  rain = map(rain, 0, 1023, 100, 0);
  mois = map(mois, 0, 1023, 100, 0);
  value=digitalRead(relay);
  lcd.setCursor(0, 0);
  lcd.print("T=");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("S=");
  lcd.print(mois);
  lcd.print("%");
  lcd.setCursor(9, 0);
  lcd.print("R=");
  lcd.print(value);
  lcd.print("cm  ");
  lcd.setCursor(7, 1);
  lcd.print("Motor=");
  // lcd.print(mois);
  // lcd.print("%");
  if (mois < 15){
    digitalWrite(relay, LOW);
    lcd.setCursor(13, 1);
  lcd.print("ON ");
  }
  if(mois > 90){
    digitalWrite(relay, HIGH);
    lcd.setCursor(13, 1);
  lcd.print("OFF");
  }
  delay(2000);
}
