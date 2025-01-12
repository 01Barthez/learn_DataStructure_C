#ifndef _LIST_H
#define _LIST_H

    // Boolean type
    typedef enum Bool
    {
        false = 0,
        true
    } Bool;

    // Data Structure : List
    typedef struct listElement
    {
        int value;
        struct listElement* next;
    } listElement, *List;

    // Prototype definition
    List createList(void);
    Bool isEmptyList(List list);
    int listLength (List list);
    void printList(List list);
    List pushBack(List list, int x);
    List pushFront(List list, int x);
    List popBack(List list);
    List popFront(List list);
    List clearList(List list);
#endif //! _LIST_H
