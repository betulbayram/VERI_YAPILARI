#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
    int data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(){

    StackNodePtr stackPtr = NULL;
    unsigned int choice;
    int value;

    instructions();
    printf("%s", "? ");
    scanf("%u", &choice);

    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            printf("%s", "Enter an integer: ");
            scanf("%d", &value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;
        case 2:
            if(!isEmpty(stackPtr)){
                printf("The popped value is %d.\n", pop(&stackPtr));
            }
            printStack(stackPtr);
            break;
        default:
            puts("Invalid choice.\n");
            instructions();
            break;
        }

        printf("%s", "? ");
        scanf("%u", &choice);

    }
    
    puts("End of run");

    return 0;
}

void instructions(void){

    puts("Enter choice:\n"
    "1 to push a value on the stack\n"
    "2 to pop a value off the stack\n"
    "3 to end program");

}

void push(StackNodePtr *topPtr, int info){
    StackNodePtr newPtr;

    newPtr = malloc(sizeof(StackNode));

    if(newPtr != NULL){
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else{
        printf("%d not interested. No memory available.\n", info);
    }
}

int pop(StackNodePtr *topPtr){
    StackNodePtr tempPtr;
    int popValue;

    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}


int isEmpty(StackNodePtr topPtr){
    
    return topPtr == NULL;

}

void printStack(StackNodePtr currentPtr){

    if(currentPtr == NULL){
        puts("The stack is empty.\n");
    }
    else{
        puts("The stack is: ");

        while(currentPtr != NULL){
            printf("%d -->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }

}

