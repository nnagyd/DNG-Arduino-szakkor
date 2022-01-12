/*
   Szakkör 4.
   Német Nemzetiségi Gimnázium 2021-2022
   Agócs Norbert és Nagy Dániel
      _____  _   _  _____
     |  __ \| \ | |/ ____|
     | |  | |  \| | |  __
     | |  | | . ` | | |_ |
     | |__| | |\  | |__| |
     |_____/|_| \_|\_____|

   Program 02:
   Tolatóradar

   Útmutató:
   Az ultrahangos szenzorral készítsünk tolatóradart. Az ultrahangos tolatóradart
   kössük be mint korábban, a LED-et tegyük a 8-as PIN-re.
   A LED villogni kezd, ha a szenzorhoz közel tesszük a kezünket (40cm)
   és minél közelebb kerülünk annál gyorsabban villog.
*/

//definiciok
int trigger=7;
int echo = 6;
int LED = 8; //!
float ido = 0, tav = 0;

void setup()
{
  Serial.begin (9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED, OUTPUT); //!
}

void loop()
{
  //jel kiadása
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH); //Ultrahang kezdete
  delayMicroseconds(10); //Várakozás
  digitalWrite(trigger, LOW); //Ultrahang vége

  //időmérés
  ido = pulseIn(echo, HIGH); //Az oda-vissza eltelt ido
  tav = (ido / 2) * 0.03432; //Távolság számolás: v = s/t
  
  //Mérési tartomány beállítása:
  if (tav >= 500 || tav <= 0) {
    Serial.println("Nincs ertek!");
  }
  else {
    Serial.print(tav);
    Serial.println(" cm");
  }
  
  //Az elozo kódhoz képest új rész: LED villogtatás
  if (tav <= 40) 
  {
    digitalWrite(LED, HIGH);
    delay(tav * 8); //A távolság függvényében változik
    digitalWrite(LED, LOW);
    delay(tav * 8);
  }
}
