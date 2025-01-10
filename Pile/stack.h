#ifndef _STACK_H
#define _STACK_H

    // Boolean type
    typedef enum
    {
        false = 0, // 0
        true // 1 
    } Bool;

    // Stack Definition
    typedef struct stackElement
    {
        int value;
        struct stackElement* next;
    } stackElement, *Stack;

    // Function Prototypes
    Stack createStack(void);
    Bool isEmptyStack(Stack stack);
    Stack pushStack(Stack stack, int value);
    void printStack(Stack stack);
    Stack popStack(Stack stack);
    int topStack(Stack stack);
    int sizeOfStack(Stack stack);
    void searchStack(Stack stack, int value);
    Stack sortStack(Stack stack);
    Stack clearStack(Stack stack);
#endif // !_STACK_H