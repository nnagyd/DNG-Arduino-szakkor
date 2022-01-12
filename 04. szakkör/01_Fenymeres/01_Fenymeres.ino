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
   Fénymérés

   Útmutató:
   A fényszenzort kössük az A0 PIN-re, a szenzor legyen egy ellenállással sorosan
   kapcsolva. Kössünk egy LED-et a D2 pinre. Ha sötét van a LED automatikusan
   bekapcsol.
*/

//mit hova kötöttünk
int LED = 2;
int SENSOR = 0;

void setup() //egyszer fut le
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() //folyamatosan fut
{
  int feny;
  feny = analogRead(SENSOR); //mérés
  Serial.println(feny);
  delay(10);

  //a feladat a 880 átírása úgy, hogy a kód jól működjön
  //ez a szám függ a használt szenzortól, a hőmérséklettől, a használt ellenállástól
  if(feny > 880) //ha sötét van
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
}
