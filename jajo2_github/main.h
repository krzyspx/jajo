int timeon1 = 6; //czas zał
int timeon2 = 9; //czas zał
int timeoff = 12; //czas wył

byte flagaled = 0;

void save_data ();
void read_data ();
void jajomain();

void GSon() {
  // Serial.print("GS  on  ");   Serial.println(stan_programu);
  digitalWrite(led_green, HIGH); //przekaźnik on

}
void GSoff() {
  //  Serial.print("GS  off  ");   Serial.println(stan_programu);
  digitalWrite(led_green, LOW);

}

void jajosetup()
{
  read_data();
  Blynk.virtualWrite(V22, timeon1);
  Blynk.setProperty(V22, "color", _YELLOW);
  Blynk.virtualWrite(V23, timeoff);
  Blynk.setProperty(V23, "color", _BLUE);
  Blynk.virtualWrite(V24, timeon2);
  Blynk.setProperty(V24, "color", _RED);
  Blynk.setProperty(V21, "color", _MAGENTA);
}

BLYNK_WRITE(V19) {    //vprzycis załączenia jajo
  int i = param.asInt();
  if (i) {
    stan_programu++;
    gstime = 0;
    jajomain();
  }
}

BLYNK_WRITE(V22) {     //nowe wartości czasów
  timeon1 = param.asInt();
  save_data ();
}
BLYNK_WRITE(V23) {
  timeoff = param.asInt();
  save_data ();
}
BLYNK_WRITE(V24) {
  timeon2 = param.asInt();
  save_data ();
}
void jajomain() // główna procedura jajo
{
  //  Serial.print("gstime  ");    Serial.println(gstime);
  Blynk.setProperty(V20, "offLabel", String(gstime));
  Blynk.virtualWrite(V21, gstime);

  switch (stan_programu) {
    case 1: {
        GSon();
        Blynk.setProperty(V19, "offLabel", "Warm");
        Blynk.setProperty(V19, "color", _YELLOW);
        akcja.updateInterval(2, 500);
        gstime++;
        if (gstime >= timeon1) {
          gstime = 0;
          stan_programu = 2;
        }
      } break;
    case 2: {
        GSoff();
        Blynk.setProperty(V19, "offLabel", "Wait");
        Blynk.setProperty(V19, "color", _BLUE);
        akcja.updateInterval(2, 1000);
        gstime++;
        if (gstime >= timeoff) {
          gstime = 0;
          stan_programu = 3;
        }
      } break;

    case 3: {
        GSon();
        Blynk.setProperty(V19, "offLabel", "Boil");
        Blynk.setProperty(V19, "color", _RED); //LED
        akcja.updateInterval(2, 2000);
        gstime++;
        if (gstime >= timeon2) {
          gstime = 0;
          stan_programu = 0;
        }
      } break;

    default:
      {
        GSoff();
        stan_programu = 0;
        Blynk.setProperty(V19, "color", _GREEN); //LED
        Blynk.setProperty(V19, "offLabel", "OFF");
        akcja.updateInterval(2, 5000);
      } break;
  }
}


