#include <Ticker.h> //do wachdoga

//----------------------WD
Ticker tickerOSWatch;
#define OSWATCH_RESET_TIME 30 //wd w sek
static unsigned long last_loop;
void ICACHE_RAM_ATTR osWatch(void) { //watchdog 30 sek
  unsigned long t = millis();
  unsigned long last_run = abs(t - last_loop);
  if (last_run >= (OSWATCH_RESET_TIME * 1000)) {
    // save the hit here to eeprom or to rtc memory if needed
    ESP.restart();  // normal reboot
    //ESP.reset();  // hard reset
  }
}
//----------------------WD END

void wdsetup()
{
   last_loop = millis(); //wd
}

