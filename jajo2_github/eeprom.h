#include <EEPROM.h>

#define memory 100


void save_data () { //zapisz dane do flash

  EEPROM.begin(1024);
  EEPROM.put(memory, timeon1);
  EEPROM.put((memory + 10), timeoff);
  EEPROM.put((memory + 20), timeon2);
  //    EEPROM.put(memory, dane2);
  EEPROM.end(); //  EEPROM.commit();
}

void read_data() { // odczyt z flash

  EEPROM.begin(1024);
  EEPROM.get(memory, timeon1);
  EEPROM.get((memory + 10), timeoff);
  EEPROM.get((memory + 20), timeon2);
  //  EEPROM.get(memory, dane2);
  EEPROM.end(); //  EEPROM.commit();
}
