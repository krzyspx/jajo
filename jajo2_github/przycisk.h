#include "OneButton.h"

#define klaw1 0        //przycisk SONOFF
#define klaw2 5

OneButton myklaw1(klaw1, true);

byte stan_programu = 0; // wskaźnik stanu programu
int  gstime = 0;
void updateled(int t);
void jajomain();

void myclick1() { // przełącznik stanu programu
  gstime = 0;
  if (stan_programu > 0) {
    stan_programu++;
    jajomain();
  }
  //  Serial.println("single");
  //  Serial.println(stan_programu);
} // click1

void mydoubleclick1() {     //zał/wył GS
  if (stan_programu == 0) stan_programu = 1; else  stan_programu = 0;
  jajomain();
  //  Serial.println("duble");

} // doubleclick1

void mylongPressStart1() {   // zmiany stanu programu wył>zał>tem>czas
  // Serial.println("long");
  stan_programu = 0;
  gstime = 0;
  jajomain();
  // Serial.println(stan_programu);

} // longPressStart1

void mylongPress1() {

} // longPress1

void mylongPressStop1() {

} // longPressStop1

void klawsetup()
{
  myklaw1.setDebounceTicks(100); // opóźnienie na drganie styków domyśle 50 msek
  myklaw1.setClickTicks(700); // opóźnienie po którym jest click domyślne 600 msek
  myklaw1.setPressTicks(1200);

  myklaw1.attachClick(myclick1);
  myklaw1.attachDoubleClick(mydoubleclick1);
  myklaw1.attachLongPressStart(mylongPressStart1);
  myklaw1.attachLongPressStop(mylongPressStop1);
  myklaw1.attachDuringLongPress(mylongPress1);

}

void klawkakcja() {
  myklaw1.tick();
}
