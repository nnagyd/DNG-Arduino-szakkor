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

   Program 01:
   Távolságmérés

   Útmutató:
   A 6-os (echo) és 7-es (trigger) PINre kötött távolságmérő szenzor jelének a beolvasása.
   Ez megadja az eltelt időt, ebből megkapható a távolság, hiszen a hangsebesség ismert

   s = 0.5*v*t
      v: hangsebesség: 340 m/s
      t: eltelt idő, mérésből
*/

//definiciok
int trigger = 7;
int echo = 6;
float ido = 0;
float tav = 0;

void setup()
{
  Serial.begin (9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  //Jel kiadása
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH); //Ultrahang kezdete
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW); //Ultrang vége

  //időmérés, azaz várakozás a jelre
  ido = pulseIn(echo, HIGH);
  tav = (ido / 2) * 0.03432;

  //eredmény feldolgozása és kiiratása
  if (tav >= 500 || tav <= 0) 
  {
    Serial.println("Nincs ertek!");
  }
  else 
  {
    Serial.print(tav);
    Serial.println(" cm");
  }

  //várakozás
  delay(1000);
}
