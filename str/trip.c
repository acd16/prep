#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void foo(char * str, char *** out){
    char * beg = str;
    char * temp = str;
    int len=0, i=0, j=0;
    *out = malloc(3*sizeof(char*));
    char ** gg = *out;
    while(*temp){
        printf("temp %c\n", *temp);
        if(*temp == ' '){
            len = (int)(temp-beg);
            gg[j] = malloc(len+1);
            for(i=0;i<len;i++)
            {
                printf("beg val %c\n", *(beg+i));
                gg[j][i] = *(beg+i);
            }
            gg[j][i] = '\0';
            beg = temp+1;
            j++;
        }
        temp++;
    }
    if(beg != temp){
        printf("temp %c\n", *temp);
        len = (int)(temp-beg);
        gg[j] = malloc(len+1);
        for(i=0;i<len;i++)
        {
            printf("beg val %c\n", *(beg+i));
            gg[j][i] = *(beg+i);
        }
        gg[j][i] = '\0';
    }
}

int main(){
    char *s  = malloc(12);
    char ** tok = NULL;
    strcpy(s, "this is it");
    printf("%s\n", s);
    foo(s, &tok);
    printf("im done\n");
    printf("GG %s\n", tok[0]);
    printf("GG %s\n", tok[1]);
    printf("GG %s\n", tok[2]);
}
