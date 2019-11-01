
#define led_blue 13
#define led_red 13     //led SONOFF
#define led_bialy 12
#define led_green 12   //przekaźnik

void ledsetup() {
  pinMode(led_red, OUTPUT); //LED na module
  digitalWrite(led_red, HIGH);
  pinMode(led_green, OUTPUT); //LED na module
  digitalWrite(led_green, LOW);
}

//BLYNK_WRITE(V10) {
//  if (param.asInt()) akcja.updateInterval(2, 500); else akcja.updateInterval(2, 2000);
//}

int flaga_led = 0;
void led_timer()
{
  flaga_led = !flaga_led;
  digitalWrite(led_red, flaga_led);
}
