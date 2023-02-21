#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct A{

    int a;

};

typedef struct A a;

int main(){

    a a1 = {2};
    //struct
    a *aptr;
    aptr = (a *)malloc(sizeof(a));
    printf("%p", aptr);

    // integer
    int *i;
    i = (int *)malloc(sizeof(int));

    //char
    char *c;
    c = (char *)malloc(sizeof(char));

    free(aptr);
    free(i);
    free(c);
    return 0;
}