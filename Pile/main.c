#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main() {
    Stack myStack = createStack();
    int size = 0;
    int firstElement = -1;

    // Check empty stack
    printf("\n*****************************************************\n");
    if(isEmptyStack(myStack))
        printf("La pile est vide ! \n");
    else 
        printf("La pile n'est pas vide !\n");

    // print the first element of stack
    printf("\n*****************************************************\n");
    firstElement = topStack(myStack);
    printf("First Element: %d\n", firstElement);

    // Print size of stack
    printf("\n*****************************************************\n");
    size = sizeOfStack(myStack);
    printf("Size of stack is: %d\n", size);

    // Push element into stack
    printf("\n*****************************************************\n");
    myStack = pushStack(myStack, 8);
    myStack = pushStack(myStack, 21);
    myStack = pushStack(myStack, 100);
    myStack = pushStack(myStack, 65);
    myStack = pushStack(myStack, 87);

    // print stack 
    printStack(myStack);

    // print size of stack
    printf("\n*****************************************************\n");
    size = sizeOfStack(myStack);
    printf("Size of stack is: %d\n", size);

    // pop stack element 
    printf("\n*****************************************************\n");
    myStack = popStack(myStack);
    printStack(myStack);

    // print the first element of stack
    printf("\n*****************************************************\n");
    firstElement = topStack(myStack);
    printf("FirstElement: %d\n", firstElement);
    
    // Print size of stack
    printf("\n*****************************************************\n");
    size = sizeOfStack(myStack);
    printf("Size of stack is: %d\n", size);

    // Search an Element in the stack
    printf("\n*****************************************************\n");
    searchStack(myStack, 25);

    printf("\n*****************************************************\n");
    searchStack(myStack, 100);

    // Sort element ascending
    printf("\n*****************************************************\n");
    myStack = sortStack(myStack);
    printStack(myStack);

    // Clean stack
    printf("\n*****************************************************\n");
    myStack = clearStack(myStack);

    return 0;
}
