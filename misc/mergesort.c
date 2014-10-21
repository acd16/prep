#include<stdio.h>
#include<stdlib.h>


void merge(int *i, int low, int mid, int high){
    int j=0, m=0, n=0;
    int n1 = mid-low+1;
    int n2 = high-mid;
    int * left = malloc(n1*sizeof(int));
    int * right = malloc(n2*sizeof(int));
    printf("low %d mid %d high %d\n", low, mid, high);
    for(m=0;m<n1;m++)
        left[m] = i[low+m];
    for(n=0;n<n2;n++)
        left[m] = i[mid+m];
    m=0;n=0;
    for(m=0;m<n1;m++)
        printf("%d ", left[m]);
    printf("\n");
    for(n=0;n<n2;n++)
        printf("%d ", right[m]);
    printf("\n");
    for(j=low;j<=high;j++){
        if(left[m]<right[n]){
            i[j] = left[m];
            m++;
        }
        else{
            i[j] = right[n];
            n++;
        }
    }
}

void mergesort(int *i, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        //printf("%d %d %d\n", low, mid, high);
        mergesort(i, low, mid);
        mergesort(i, mid+1, high);
        merge(i, low, mid, high);
    }
}

void main(){
    int a[8]={8,7,6,5,4,3,2,1};
    mergesort(a, 0, 7);
    int i;
    for (i=0;i<8;i++)
        printf("%d ", a[i]);
    printf("\n");
}
