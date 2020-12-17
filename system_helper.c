#include<stdio.h>

void handle(int argc, char** argv) {

  int i;

  for(i=1; i<argc; i++) {
    printf("%s\n", argv[i]);
  }
}

void endian(void) {

  int i; //loop counter
  int size_int; //size of int, duh
  int exper; //int to hold test values 0,1,2.. in each byte
  int pow256; //powers of 256 (to get to next byte in exper)
  char* cp; //char* to point at bytes inside exper

  size_int = (int)sizeof(exper);
  printf("size of int is %d bytes\n", size_int);

  exper = 0;
  pow256 = 1;
  for (i=0; i<size_int; i++) {
    exper = exper + i*(pow256);
    pow256 = 256*pow256;
  }

  printf("when 0*256^0 + 1*256^1 + 2*256^2 + ... is in an int:\n");

  cp = (char*)&exper;
  for (i=0; i<size_int; i++) {
    printf("%d byte is %d\n", i, *(cp+i));
  }

  if (*cp == 0 && *(cp+i)==i) {
    printf("so you got little endian\n");
  }
  if (*cp == i && *(cp+i) == 0) {
    printf("so you got big endian\n");
  }
}
