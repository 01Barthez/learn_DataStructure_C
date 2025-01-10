#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

/************************************************************************************************/

Stack createStack(void) {
  return NULL;
}

/************************************************************************************************/

Bool isEmptyStack(Stack stack) {
    if(stack == NULL)
        return true;
    return false;
}

/************************************************************************************************/

Stack pushStack(Stack stack, int value) {
    stackElement* element;
    element = malloc(sizeof(*element));

    if(element == NULL) {
        fprintf(stderr, "Failed of dynamic memory allocation !\n");
        exit(EXIT_FAILURE);
    }

    element->value = value;
    element->next = stack;

    return element;
}

/************************************************************************************************/

void printStack(Stack stack) {
    if(isEmptyStack(stack)){
        printf("Empty stack, nothing to print !");
        return;
    }

    while (!isEmptyStack(stack))
    {
        printf("[%d]\n", stack->value);
        stack = stack->next;
    }
}

/************************************************************************************************/

Stack popStack(Stack stack) {
    stackElement* element;

    if(isEmptyStack(stack))
        return createStack();

    element = stack->next;
    free(stack);

    return element;
}

/************************************************************************************************/

int topStack(Stack stack) {
    stackElement* element;
    int firstElement = 0;

    if(isEmptyStack(stack))
        return 0;

    element = stack;

    return stack->value;
}

/************************************************************************************************/

int sizeOfStack(Stack stack){
    int size = 0;

    while (!isEmptyStack(stack))
    {
        size++;
        stack = stack->next;
    }

    return size;
}

/************************************************************************************************/

void searchStack(Stack stack, int value) {
    int position = 1;

    while(!isEmptyStack(stack)) {
        if(stack->value == value) {
            printf("Element %d found at position %d\n", value, position);
            return;
        };

        stack = stack->next;
        position++;
    }
    
    printf("Element %d not found in the stack...\n", value);
    return;
}

/************************************************************************************************/

Stack sortStack(Stack stack){
    Stack sortedStack = createStack();

    while (!isEmptyStack(stack)) {
        int temp = stack->value;
        stack = popStack(stack);

        while (!isEmptyStack(sortedStack) && sortedStack->value < temp) {
            stack = pushStack(stack, sortedStack->value);
            sortedStack = popStack(sortedStack);
        }

        sortedStack = pushStack(sortedStack, temp);
    }

    return sortedStack;
}

/************************************************************************************************/

Stack clearStack(Stack stack) {
    stackElement* element;

    if(isEmptyStack(stack))
        return createStack();

    element = stack->next;
    free(stack);

    return clearStack(element);
}

/************************************************************************************************/
