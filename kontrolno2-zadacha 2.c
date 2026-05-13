#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
void md5(char *str, char *output){
unsigned char digest[16];
MD5((unsigned char*)str, strlen(str), digest);
for (int i = 0; i<16; i++){
sprintf(&output[i*2], "%02x", digest[i]);
}
}
int main(){
char target [] = "81dc9bdb52d04dc20036dbd8313ed055";
char text [20];
char hash[33];
for (int pin = 0; pin<=9999; pin ++){
sprintf(text, "%04d", pin);
md5(text,hash);
if(strcmp(hash, target)==0){
printf("PIN found: %s\n",text);
}
}
return 0;
}
