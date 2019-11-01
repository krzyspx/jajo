#include <OneWire.h>
#define ONE_WIRE_BUS 13 // 1-Wire bus Arduino pin
OneWire oneWire(ONE_WIRE_BUS);
#include <DallasTemperature.h>
DallasTemperature sensors(&oneWire);
DeviceAddress tempDeviceAddress;

String tempstr="";
int oldtemp = 0;
int temperature = 0;


void sensorT() { //wysylanie temp do APP
  int tempx10 = (((sensors.getTempCByIndex(0)) * 10)); // x 10

  sensors.setWaitForConversion(false);  // makes it async
  sensors.requestTemperatures(); // Send the command to get temperatures
  temperature = (tempx10 / 10); //temperatura z dokładnością do 1 oC
  int dziesietne = (tempx10 % 10);
  String str = String(temperature) + "." + String(dziesietne) + " ℃"; // oszczedzam 3 kB pamieci
  tempstr=str;
  Serial.println(" " + str);
 
  if (oldtemp != tempx10) {
    oldtemp = tempx10;
  Blynk.virtualWrite(V2, str);
  }
}

void dallasset() //ustawienia początkowe dla Dallas
{
  sensors.begin();// Dallas
  sensors.getAddress(tempDeviceAddress, 0);
  sensors.setResolution(tempDeviceAddress, 12);
  sensors.setWaitForConversion(false);  // makes it async
  sensors.requestTemperatures(); // Send the command to get temperatures
}


