#include <DS3231.h>
DS3231  rtc(SDA, SCL);

String time;
int hour;
boolean light;



void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(2, OUTPUT);
}

void loop() {
  // Get time
  time = rtc.getTimeStr();
  Serial.println(time);
  // Wait one second before repeating
  delay (1000);
  // Converting the first two characters to an int
  char SC = time[0];
  char SC1 = time[1];
  hour=(SC-48)*10+SC1-48;

//Light period
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

}
