#include<stdlib.h>
#include<stdio.h>
struct Yapi{

    int veri;
    struct yapi *p;

};

//typedef struct yapi Yapi;
int main(){

    struct Yapi y = {3};

    // void * malloc(size_t(boyut));

    char *c;
    c = (char *)malloc(sizeof(char));
    return 0;
}