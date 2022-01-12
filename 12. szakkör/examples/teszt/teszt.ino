/*
 * Library Created by Daniel Nagy 
 * Version 1.0
 * 04/24/2020
 * 
 * Test example
 */

#include "segment4.h"

segment4 disp = segment4(13,11,10,9,8,7,6,5,4,3,2);
 
void setup() {
  // put your setup code here, to run once:

}

void loop() 
{
  for(int j = 0; j < 4; j++)
  {
   for(int i = 0; i < 10; i++)
    {
      disp.setSegment(j);
      disp.printDigit(i);
      delay(100);
    }
  }
}
