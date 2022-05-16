#include "stdio.h"
#include "crypt.h"

void encrypt(FILE* src, FILE* otp, FILE* ciph){
  int qty;
  int bufferSize = 4096;               //array length of 4096
 
  unsigned char buffer[bufferSize];    
  unsigned char bufferPad[bufferSize]; 
  
  while((qty = fread(buffer, 1, bufferSize, src))){
    fread(bufferPad, qty, 1, otp);

    for(int i = 0; i < bufferSize; i++)  //from 0-4096 
      buffer[i] ^= bufferPad[i];
    fwrite(buffer, 1, qty, ciph);
  }
}