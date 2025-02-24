#define SETBIT(b, k) ((0200 >> (k)) | (b))
#define CLRBIT(b, k) (~(0200 >> (k)) & (b))
#define TESTBIT(b, k) (((0200 >> (k)) & (b)) ? 1 : 0)
unsigned char nat[100000000];
#include <stdio.h>
#include <stdlib.h>

#define DEBUG
//#undef DEBUG

int main(int argc, char *argv[])
{  
  long N;
  printf("vvedite N:\n");
  scanf("%ld", &N);
  
  int i;

  for (i = 0; i < N / 8; i++)
    nat[i] = 0377; 
  
  #ifdef DEBUG
  nat[0] = 0; 
  nat[0] = SETBIT(nat[0], 4);
  nat[0] = SETBIT(nat[0], 5);
  printf("%x\n", nat[0]);
  
  for (i = 0; i < 8; i++)
    putchar(TESTBIT(nat[0], i) ? '1' : '0');
  putchar('\n');
  #endif

  nat[0] = CLRBIT(nat[0], 0);
  return 0;
}

