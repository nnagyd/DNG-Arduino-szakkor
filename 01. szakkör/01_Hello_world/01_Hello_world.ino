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
 * Program 01:
 * Hello world
 * 
 * Útmutató:
 * A "Tools" menü alatt nyissuk meg a "Serial Monitor"-t
 * és ott látjuk meg az eredményt
 */

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("Hello world");
  delay(10000); //10000ms = 10s várakozás
}
