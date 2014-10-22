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
strncat(str1, str2, 50);
printf("%s\n", str1);
}

int main(){
    char str[11]="palindrome";
    char str1[11]="ndromepali";
    //strrev(str);
    ifrev(str, str1);
    printf("%s\n", str);
}
