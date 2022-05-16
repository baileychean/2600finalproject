#include "stdio.h"
#include "stdlib.h"
#include "crypt.h"

int main(){ 
  FILE *src;   // source file 
  FILE *otp;   // one time pad 
  FILE *ciph;  // encrypt.txt
  FILE *ciph2; // decrypted file 
  
  char userInput[0]; 

  printf("Note: The proper names for the files are source.txt, encrypt.txt, and otp.dat.\n\n"); 
  
  // santizes user input for source 
  printf("Please enter the name of the source file: ");  
  scanf("%s", userInput);  
  
  // if string doesn't match, ask again
  while((strcmp(userInput, "source.txt") != 0)){  
    printf("Incorrect file!\n\n");
    printf("Please enter the name of the source file: ");  
    scanf("%s", userInput); 
    }
  
  //santizes user input for encrypted text
  printf("Please enter the name of the cipher file: ");  
  scanf("%s", userInput);  
  
  
  while((strcmp(userInput, "encrypt.txt") != 0)){
    printf("Incorrect file!\n\n");
    printf("Please enter the name of the cipher file: ");  
    scanf("%s", userInput); 
    }
  
  //santizes user input for one time pad 
  printf("Please enter the name of the one time pad file: ");  
  scanf("%s", userInput);  
  
  
  while((strcmp(userInput, "otp.dat") != 0)){        
    printf("Incorrect file!\n\n");
    printf("Please enter the name of the one time pad file: ");  
    scanf("%s", userInput); 
    }
 
  printf("\nGenerating encrypt.txt...");

  src = fopen("source.txt", "rb");
  otp = fopen("otp.dat", "rb");
  ciph = fopen("encrypt.txt", "wb");
  
  //ciph2 = fopen("decrypt.txt", "wb");
  
  encrypt(src, otp, ciph);
 // decrypt(ciph, otp, ciph2);
  
  fclose(ciph);
  fclose(src);
  fclose(otp);
  //fclose(ciph2);
}