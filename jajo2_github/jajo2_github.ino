//powinno być ok

#define BLYNK_MSG_LIMIT 0
//#define BLYNK_DEFAULT_PORT 8080
// #error "Compiles"
#include <Timers.h> //  my favorite timer 
Timers <7> akcja; //

#include <OneWire.h>
#include <DallasTemperature.h>

#include "wd.h"  //watchdog
#include "blynk.h" //obsługa BLYNKa
#include "led.h"
#include "dallas.h" // obsługa DS18b20
#include "przycisk.h" //obsługa przycisku
#include "main.h"    //program główny
#include "eeprom.h" // operacje na pamięci

void setup()
{
  wdsetup();
  ledsetup();

  if (procesor == D1MINI) {
    Serial.begin(115200);  delay(100);
    Serial.println();  Serial.println(F(__FILE__));  //BLYNK .0.6.1 Arduino IDE.cc 1.8.3
  }
  akcja.attach(0, 3000, blynk_timer); //
  akcja.attach(2, 5000, led_timer);
//  akcja.attach(3, 2000, jajomain);
  akcja.attach(3, 10000, jajomain);
  
  blynksetup(); // setup BLYNK
  klawsetup();
  jajosetup();
}
void loop()
{
  wdsetup();
  akcja.process(); // timer
  blynkakcja();    //BLYNK
  klawkakcja();
}

