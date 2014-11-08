#include<stdio.h>

void gg(int * i){
    int j;
    if(&j>i)
        printf("stack grows upwards\n");
    else
        printf("stack grows downwards\n");

}

int main(){
    int i = 0;
    gg(&i);
}

