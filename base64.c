#include <stdio.h>
#include <stdlib.h>

int numero_caratteri(char* s);
char* left_shift(char* s,int n);
int calculate_bitwise_operand(int n);

int main(int argc, char* argv[]) {
   if(argc != 2) {
      printf("Due argomenti sono richiesti.\n");
      exit(1);
   }

   char base64map[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z',             // 0–25
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z',             // 26–51
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9',             // 52–61
    '+', '/'              // 62–63
   };


   char * target = argv[1];
   float numero_gruppi_dec = numero_caratteri(target) * 8 / 6.0;
   int numero_gruppi = numero_gruppi_dec !=((int)numero_gruppi_dec)/1.0 ? (int) numero_gruppi_dec + 1 : (int) numero_gruppi_dec;

   int multiplo_dei_gruppi = 4;
   int numero_zeri = 0;
   if((numero_gruppi+1)%multiplo_dei_gruppi==0) {
      numero_zeri = 1;
      numero_gruppi+=1;
   }
   if((numero_gruppi+2)%multiplo_dei_gruppi==0) {
      numero_zeri = 2;
      numero_gruppi+=2;
   }

   if((numero_gruppi+3)%multiplo_dei_gruppi==0) {
      numero_zeri = 3;
      numero_gruppi+=3;
   }

   printf("numero gruppi: %d\n",numero_gruppi);
   printf("%d zeri\n",numero_zeri);

   unsigned char gruppi[numero_gruppi];
   int bitwise_operand = calculate_bitwise_operand(6);
   for(int i = 0; i < numero_gruppi; i++) {
      gruppi[i] = (target[0] & bitwise_operand) >> 2;
      printf("numero del gruppo %d: %d\n",i,gruppi[i]);
      left_shift(target, 6);
   }

   char base64[numero_gruppi+1];

   int j;
   for(j = 0; j < numero_gruppi-numero_zeri;j++) {
      base64[j] = base64map[gruppi[j]];
   }

   for(int i = 0; i< numero_zeri;i++){
      base64[j++] = '=';
   }

   base64[numero_gruppi] = 0;
   printf("%s\n",base64);

   return 0;
}

int numero_caratteri(char* s) {
   int i;
   for(i = 0; s[i];i++);
   return i;
}

int calculate_bitwise_operand(int n) {
   //calcola numero binario per l operazione di bitwise, in base a n (es. n = 6 -> 11111100)
   int value = 0;
   int start = 7;
   for(int i = 0; i < n;i++) {
      value += 1 << start--;
   }
   return value;
}

char* left_shift(char *s,int n) {
   s[0] = s[0] << n;

   int bitwise_operand = calculate_bitwise_operand(n);

   for(int i =1; s[i];i++) {
      int k = (s[i] & bitwise_operand) >> (8-n);
      //printf("s[i-1]: %d,k:%d\n",s[i-1],k);
      s[i-1] = s[i-1] | k;
      //printf("bitwise or: %d\n",s[i-1]);
      s[i] = s[i]<<n;
   }
}