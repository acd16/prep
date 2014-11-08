#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define max(x,y) (((x)>(y))?(x):(y))

typedef struct tree{
    int value;
    struct tree * left;
    struct tree * right;
}leaf;

typedef struct list{
    leaf * point;
    struct list* next;
}node;
