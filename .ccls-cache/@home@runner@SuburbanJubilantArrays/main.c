#include "stdio.h"
#include "stdlib.h"
#include "crypt.c"

int main(){
  FILE* src;
  FILE* dst;

  int qty;
  int bufferSize = 4096; 
  unsigned char buffer[bufferSize];

  if(!(src = fopen("source.txt", "rb"))){
    printf("File does not exist!\n");
    exit(0);
  }

  dst = fopen("ciphertext.txt", "wb");

  while((qty = fread(buffer, 1, bufferSize, src))){
    fwrite(buffer, qty, 1, dst);
  }

  fclose(dst);
  fclose(src);

  return(0);
}








