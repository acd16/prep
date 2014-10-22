#include <stdio.h>
#include <string.h>

void swap(char * s, char *d){
    char t;
    t = *s;
    *s = *d;
    *d = t;
}

void strrev(char * str){
    int i=0;
    int len = strlen(str);
    for(i=0;i<len/2;i++){
        swap(&str[i], &str[len-i-1]);
    }
}

void ifrev(char * str1, char *str2){
char check[50] = {0};
if(strlen(str1) != strlen(str2))
    return;
strncat(check, str1, 50);
strncat(check, str1, 50);
printf("%s %s\n", check, str2);
if(strstr(check, str2))
    printf("it is a rotation\n");
}

int main(){
    char str[11]="palindrome";
    char str1[11]="ndrpmepali";
    //strrev(str);
    ifrev(str, str1);
}
