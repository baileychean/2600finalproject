#include "stdio.h"
#include "stdlib.h"
#include "crypt.c"

int main(){
  FILE* src;
  FILE* dst;

  int qty;
  int bufferSize = 4096; 
  //char userInput[0]; 
  unsigned char buffer[bufferSize];

  //printf("Please enter the name of the source file: ");  
  //scanf("%s", userInput);  
  
  //if((userInput == "source.txt"))
  //{
  //  printf("%s", userInput);
  //}
    
    
  
  if(!(src = fopen("source.txt", "rb"))){
    printf("File does not exist!\n");
    exit(-1);
  }

  dst = fopen("ciphertext.txt", "wb");

  while((qty = fread(buffer, 1, bufferSize, src))){
    fwrite(buffer, qty, 1, dst);
  }

  fclose(dst);
  fclose(src);

  return(0);








  
}








