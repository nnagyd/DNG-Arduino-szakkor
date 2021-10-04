/*
 * Szakkör 3.
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
 * Számolás
 * 
 * Útmutató:
 * Minden gombnyomásra az Arduino számol egyet. Ennek megfelelően változik
 * a LED állapota. A gomb legyen a 2-es PIN-en, a LED az 5-ös pinen.
 */

int GOMB = 2;
int LED = 5;
int szamlalo = 0;

void setup() 
{
  Serial.begin(9600); //soros kommunikáció indítása
  
  //PIN-ek beállítása
  pinMode(GOMB,INPUT); //A gomb bemenet
  pinMode(LED,OUTPUT); //A LED  kimenet
}

void loop() 
{
  if(digitalRead(GOMB) == HIGH) //a gombot megnyomtuk
  {
    //A számláló növelése eggyel
    szamlalo++;

    //Kiiratás a soros monitorra. Mi a különbség ezek között?
    Serial.print("Szamlalo: "); 
    Serial.println(szamlalo);

    //LED átállítása
    digitalWrite(LED, szamlalo % 2); // %2 = 1 ha páratlan és %2 = 0 ha páros. Ez nekünk tökéletes!
    //Hogy lehet megoldani, hogy minden 5.-ra villanjon fel?
    //Hogy lehet megoldani, hogy ne sose világítson?
    //Hogy lehet megoldani, hogy párosra világítson és páratlanra ne?
    //Írjuk meg a % operátor nélkül, az állapotot tároljuk egy változóban!

    //Várakozás
    delay(500);
    //Mi történik ha ez nincsen itt?
  }
  //Kössünk be mégegy LEDet, ami akkor világít amikor a másik nem! Tehát a két LED ellentetésen világít.
  //Kössünk be mégegy gombot, amivel lefelé lehet számolni!
}
