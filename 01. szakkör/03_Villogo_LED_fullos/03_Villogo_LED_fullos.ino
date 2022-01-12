/*
 * Szakkör 1.
 * Német Nemzetiségi Gimnázium 2021-2022
 * Agócs Norbert és Nagy Dániel
 *    _____  _   _  _____ 
 *   |  __ \| \ | |/ ____|
 *   | |  | |  \| | |  __ 
 *   | |  | | . ` | | |_ |
 *   | |__| | |\  | |__| |
 *   |_____/|_| \_|\_____|
 * 
 * Program 03:
 * Villogó LED minden extrával
 * 
 * Útmutató:
 * A 2-es pinre kössünk LED-et ellenállással. A LED villogni fog miután
 * ezt a kódot feltöltjük az Arduinora. Állítsuk át a "varakozas" változót
 * és figyeljük meg a hatását! Nyissuk meg a "Serial monitor"-t a
 * Ctrl+Shift+M kombinációval.
 */

int LED = 2;
float varakozas = 0.3; //0.3 másodpercet vár
int varakozas_ms = varakozas * 1000; //0.3*1000 = 300 ms

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT); //beállítja a LED pint (2-es) kimenetre
}

void loop()
{
  Serial.println("BE");
  digitalWrite(LED, HIGH); //kiad 5V-ot a 2-es pinen
  delay(varakozas_ms);
  Serial.println("KI");
  digitalWrite(LED, LOW); //kikapcsolja a 2-es pinen az áramot
  delay(varakozas_ms);
}
