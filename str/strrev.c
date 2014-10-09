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

int main(){
    char str[11]="this is it";
    strrev(str);
    printf("%s\n", str);
}
