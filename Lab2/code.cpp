#include <DHT.h>                // Подключение библиотеки для работы с датчиком температуры и влажности DHT11
#include <Wire.h>               // Библиотека для работы с I2C устройствами
#include <LiquidCrystal.h>      // Библиотека для управления LCD-дисплеем
#include <SFE_BMP180.h>         // Библиотека для работы с барометрическим датчиком BMP180
#include <DS3232RTC.h>          // Библиотека для работы с модулем часов реального времени DS3232

DHT dht(7, DHT11);              
SFE_BMP180 bmp180;              
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() {
	lcd.begin(16, 2);             
	dht.begin();                  
	Serial.begin(9600);           
	bmp180.begin();               
}

void loop() {
	float h = dht.readHumidity(); 
	float t = dht.readTemperature();

	double p, bmpt;               
	bmp180.startTemperature();    
	bmp180.startPressure(3);      
	bmp180.getPressure(p, bmpt);  

	lcd.setCursor(0, 0);          
	lcd.print(hour());            
	lcd.print(":");
	lcd.print(minute());
	lcd.print(":");
	lcd.print(second());
	lcd.print(" T: ");
	lcd.print(t);                 
	lcd.print("C");               

	lcd.setCursor(0, 1);          
	lcd.print("H:");
	lcd.print(h);                
	lcd.print(" P: ");
	lcd.print(p);                 
}