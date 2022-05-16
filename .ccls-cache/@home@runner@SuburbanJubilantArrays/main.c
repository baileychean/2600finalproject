#include "stdio.h"
#include "stdlib.h"
#include "crypt.c"

int main(){
  FILE* src;
  FILE* dst;
  FILE* otp;
  
  int qty;
  int bufferSize = 4096; 
  char userInput[0]; 
  unsigned char buffer[bufferSize];
  unsigned char bufferPad[bufferSize];
/*
  printf("Please enter the name of the source file: ");  
  scanf("%s", userInput);  
  
  //closes if incorrect input file 
  if(!(strcmp(userInput, "source.txt") == 0)){
    printf("Incorrect input file!");
    return (0);
    }  
  */
  if(!(src = fopen("source.txt", "rb"))){
    printf("File does not exist!\n");
    exit(-1);
  }
  
  dst = fopen("ciphertext.txt", "wb");
  otp = fopen("otp.dat", "rb");
  
  while((qty = fread(buffer, 1, bufferSize, src))){
    fread(bufferPad, qty, 1, otp);

    for(int i = 0; i < bufferSize; i++)
      buffer[i] ^= bufferPad[i];
    fwrite(buffer, 1, qty, dst);
  }

  fclose(dst);
  fclose(src);

  return(0);
}








