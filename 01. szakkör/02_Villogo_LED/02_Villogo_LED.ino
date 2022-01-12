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
 * Program 02:
 * Villogó LED
 * 
 * Útmutató:
 * A 2-es pinre kössünk LED-et ellenállással. A LED villogni fog miután
 * ezt a kódot feltöltjük az Arduinora
 */

int LED = 2;

void setup()
{
  pinMode(LED, OUTPUT); //beállítja a LED pint (2-es) kimenetre
}

void loop()
{
  digitalWrite(LED, HIGH); //kiad 5V-ot a 2-es pinen
  delay(1000);
  digitalWrite(LED, LOW); //kikapcsolja a 2-es pinen az áramot
  delay(1000);
}
