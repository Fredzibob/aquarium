#include <DS3231.h>
DS3231  rtc(SDA, SCL);

String time;
int hour = 1212; 

void setup() {
  Serial.begin(115200);
  rtc.begin();
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(TUESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(21, 10, 10);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(21, 06, 2016);   // Set the date to January 1st, 2014

}

void loop() {
  // Send current temperature
  //Serial.println(rtc.getTemp());
  // Send Day-of-Week
  //Serial.print(rtc.getDOWStr());
  //Serial.print(" ");
  // Send date
  //Serial.print(rtc.getDateStr());
  //Serial.print(" -- ");
  // Send time
  time = rtc.getTimeStr();
  Serial.println(time);
  // Wait one second before repeating :)
  delay (1000);

  char SC = time[0];
  char SC1 = time[1];
  hour=(SC-48)*10+SC1-48;

    if (hour>=12 && hour<=20) Serial.println("Lights on");
  else Serial.println("Lights off");

}
