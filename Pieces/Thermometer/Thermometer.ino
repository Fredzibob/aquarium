#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 3 /*-(Connect to Pin 2 )-*/
OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);
double temp1;
double temp2;


void setup(){
Serial.begin(115200);
sensors.begin();
}


void loop(){
// Send the command to get temperatures
sensors.requestTemperatures(); 

Serial.print("Device 1 = ");
temp1 = sensors.getTempCByIndex(0);
Serial.print(temp1);
Serial.println(" Degrees C");
Serial.print("Device 2 = ");
temp2 = sensors.getTempCByIndex(1);
Serial.print(temp2);
Serial.println(" Degrees C");
delay(1000);

}/* --(end main loop )-- */

/* ( THE END ) */
