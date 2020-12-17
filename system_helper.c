#include<stdio.h>

/**
*just print the command line args for now
*/
void handle(int argc, char** argv) {

  int i;

  for(i=1; i<argc; i++) {
    printf("%s\n", argv[i]);
  }
}


/**
*define int test.  use char* cp to point to address
*&test so cp can pointer arithmetic to every byte in
*test.  Use this to see if test is big/little endian
*/
void endian(void) {

  int i; //loop counter
  int size_int; //size of int, duh
  int test; //int to hold test values 0,1,2.. in each byte
  int pow256; //powers of 256 (to get to next byte in test)
  char* cp; //char* to point at bytes inside test

  size_int = (int)sizeof(test);
  printf("size of int is %d bytes\n", size_int);

  test = 0;
  pow256 = 1;
  /**
  *put 0 .. <size of int> into
  *<least sig byte> .. <most sig byte>
  *respectively.
  */
  for (i=0; i<size_int; i++) {
    test = test + i*(pow256);
    pow256 = 256*pow256;
  }

  printf("When 0*256^0 + 1*256^1 + 2*256^2 + ... is in an int:\n");

  cp = (char*)&test;
  for (i=0; i<size_int; i++) {
    printf("the %dth byte is %d\n", i, *(cp+i));
  }

  if (*cp == 0 && *(cp+i)==i) {
    printf("... so you got little endian\n");
  }
  if (*cp == i && *(cp+i) == 0) {
    printf("... so you got big endian\n");
  }
}
