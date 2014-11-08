#include <stdio.h>
#include <stdlib.h>

int intcmp(const void * i, const void *j){
    int a = *(int*)i;
    int b = *(int*)j;
    return a-b;
}

int main(){
    int a[5] = {3,4,1,7,6};
    qsort(a, 5, sizeof(int), intcmp);
    printf("%d\n", a[0]);
}

