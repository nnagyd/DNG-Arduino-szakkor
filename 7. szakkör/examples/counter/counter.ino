/*
 * Library Created by Daniel Nagy 
 * Version 1.0
 * 04/24/2020
 * 
 * Counter example
 */

#include "segment4.h"

segment4 disp = segment4(12,11,10,9,8,7,6,5,4,3,2,13);
 
void setup() {
  // put your setup code here, to run once:

}

void loop() 
{
  for(int i = 0; i < 10000; i++)
  {
    disp.printNumber(i,10);
  }
}
