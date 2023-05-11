#include <stdio.h>
char flags; // one byte storage variable

// I am not sure the best way to define these binary values in C, should the be in hex?

#define CASE0 00000000

#define CASE1 00000010

#define CASE2 00000100

#define CASE3 00001000

#define CASE4 00000110

#define CASE5 00001010

#define CASE6 00001100

#define CASE7 00001110


void main() {

  // some code to set flag

  flags = CASE1;

  // get the value of the flag

  if(flags == CASE0) {
      printf("CASE0");
  } else if(flags == CASE1) {
    printf("CASE1");
  } else if(flags == CASE2) {
    printf("CASE2");
  } else if(flags == CASE3) {
    printf("CASE3");
  } else if (flafs == CASE4) {
    printf("CASE4");
  }// and so on


}



