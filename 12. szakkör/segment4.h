#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class segment4
{
private:
  int A,B,C,D,E,F,G,D1,D2,D3,D4,dec;
  void init()
  {
    pinMode(A,OUTPUT); pinMode(B,OUTPUT); pinMode(C,OUTPUT); pinMode(D,OUTPUT); pinMode(E,OUTPUT); pinMode(F,OUTPUT);
    pinMode(G,OUTPUT); pinMode(D1,OUTPUT); pinMode(D2,OUTPUT); pinMode(D3,OUTPUT); pinMode(D4,OUTPUT); pinMode(dec,OUTPUT); 
  }
  void setSegments(int state)
  {
    digitalWrite(D1,state); digitalWrite(D2,state); digitalWrite(D3,state); digitalWrite(D4,state);
  }
public:
  segment4(int D1, int A, int F, int D2, int D3, int B, int E, int D, int dec, int C, int G, int D4)
  {
    this->A = A; this->B = B; this->A = A; this->C = C; this->D = D; this->E = E; this->F = F; this->G = G;
    this->D1 = D1; this->D2 = D2; this->D3 = D3; this->D4 = D4; this->dec = dec;
    init();
  }

  void setSegment(int D)
  {
    setSegments(HIGH);
    switch(D)
    {
      case 0:
      digitalWrite(D1,0);
      break;

      case 1:
      digitalWrite(D2,0);
      break;

      case 2:
      digitalWrite(D3,0);
      break;

      case 3:
      digitalWrite(D4,0);
      break;
    }
  }
  void printDigit(int digit)
  {
    switch(digit)
    {
      case 0:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,1);
      digitalWrite(E,1);
      digitalWrite(F,1);
      digitalWrite(G,0);
      break;
      case 1:
      digitalWrite(A,0);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,0);
      digitalWrite(E,0);
      digitalWrite(F,0);
      digitalWrite(G,0);
      break;
      case 2:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,0);
      digitalWrite(D,1);
      digitalWrite(E,1);
      digitalWrite(F,0);
      digitalWrite(G,1);
      break;
      case 3:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,1);
      digitalWrite(E,0);
      digitalWrite(F,0);
      digitalWrite(G,1);
      break;
      case 4:
      digitalWrite(A,0);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,0);
      digitalWrite(E,0);
      digitalWrite(F,1);
      digitalWrite(G,1);
      break;
      case 5:
      digitalWrite(A,1);
      digitalWrite(B,0);
      digitalWrite(C,1);
      digitalWrite(D,1);
      digitalWrite(E,0);
      digitalWrite(F,1);
      digitalWrite(G,1);
      break;
      case 6:
      digitalWrite(A,1);
      digitalWrite(B,0);
      digitalWrite(C,1);
      digitalWrite(D,1);
      digitalWrite(E,1);
      digitalWrite(F,1);
      digitalWrite(G,1);
      break;
      case 7:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,0);
      digitalWrite(E,0);
      digitalWrite(F,0);
      digitalWrite(G,0);
      break;
      case 8:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,1);
      digitalWrite(E,1);
      digitalWrite(F,1);
      digitalWrite(G,1);
      break;
      case 9:
      digitalWrite(A,1);
      digitalWrite(B,1);
      digitalWrite(C,1);
      digitalWrite(D,1);
      digitalWrite(E,0);
      digitalWrite(F,1);
      digitalWrite(G,1);
      break;
      case -1:
      digitalWrite(A,0);
      digitalWrite(B,0);
      digitalWrite(C,0);
      digitalWrite(D,0);
      digitalWrite(E,0);
      digitalWrite(F,0);
      digitalWrite(G,0);
      break;
    }
  }//set digit vége

  void printNumber(int number, int delayed = 2)
  {
    int digit[4];
    digit[0] = number / 1000;
    int leftover = number - digit[0]*1000;
    digit[1] = leftover / 100;
    leftover = leftover - digit[1]*100;
    digit[2] = leftover / 10;
    leftover = leftover - digit[2]*10;
    digit[3] = leftover;

    int repeats = delayed/2;

    for(int j = 0; j < repeats; j++)
      for(int i = 0; i < 4; i++)
      {
        printDigit(-1);
        setSegment(i);
        printDigit(digit[i]);
        delayMicroseconds(425);
      }
     
   }
  
};

#endif
