#include <Wire.h>
#include <DS3231.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define ONE_WIRE_BUS 3 /*-(Connect to Pin 3 )-*/
OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);
DS3231  rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

String time;
int hour;
boolean light;
double temp1;
double temp2;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  sensors.begin();
  lcd.begin(20,4);
  
  pinMode(2, OUTPUT);
// ************************** LCD Blink *****************************
  for(int i = 0; i< 3; i++){
    lcd.backlight();
    delay(100);
    lcd.noBacklight();
    delay(100);
  }
  lcd.backlight();
  lcd.clear();
}

void loop() {
  //**************************** Time keeping****************************************
  time = rtc.getTimeStr();
  Serial.println(time);
  // Converting the first two characters to an int
  char SC = time[0];
  char SC1 = time[1];
  hour=(SC-48)*10+SC1-48;

//**************************** Lights ***********************************************
    if (hour>=12 && hour<=20){
        Serial.println("Lights on");
        light = true;
    }
    else {
      Serial.println("Lights off");
      light = false;
    }
    if (light==true) digitalWrite(2, HIGH);
    else digitalWrite(2, LOW);
    
//************************************ Temperature ****************************************
sensors.requestTemperatures(); 
Serial.print("Device 1 = ");
temp1 = sensors.getTempCByIndex(0);
Serial.print(temp1);
Serial.println(" Degrees C");
Serial.print("Device 2 = ");
temp2 = sensors.getTempCByIndex(1);
Serial.print(temp2);
Serial.println(" Degrees C");

//*********************************** LCD Dsplay *************************************************
lcd.setCursor(6,0);
lcd.print(time);
// Temperature
lcd.setCursor(0,1);
lcd.print("Aquarium:");
lcd.setCursor(10,1);
lcd.print(temp1);
lcd.setCursor(0,2);
lcd.print("Resevoir:");
lcd.setCursor(10,2);
lcd.print(temp2);
// Light indicator
lcd.setCursor(0,3);
  lcd.print("The lights are");
  lcd.setCursor(15,3);
if (light == 1) {
  lcd.print("on");
}
else{ 
  lcd.print("off");
}


}
