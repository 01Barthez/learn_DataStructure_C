#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/************************************************************************************************/

List createList() {
    return NULL;
}

/************************************************************************************************/

Bool isEmptyList(List list) {
    if (list == NULL) 
        return true;
    return false;
}

/************************************************************************************************/

int listLength (List list) {
    int count = 0;

    while (!isEmptyList(list))
    {
        ++count;
        list = list->next;
    }

    return count;
}

/************************************************************************************************/

void printList(List list){
    if(isEmptyList(list)) {
        printf("\nEmpty list, nothing to display !\n");
        return;
    }
    
    while (!isEmptyList(list))
    {
        printf("[ %d ]--", list->value);
        list = list->next;
    }

    printf("\n");
    return;
}

/************************************************************************************************/

List pushBack(List list, int x){
    listElement* element;

    element = (listElement*)malloc(sizeof(listElement));
    if(element == NULL) {
        fprintf(stderr, "Error: promblem of dynamic allocation of memory !");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = NULL;

    if (isEmptyList(list))
       return element; 

    listElement* last = list;
    while (last->next != NULL)
        last = last->next;
    
    last->next = element;

    return list;
}

/************************************************************************************************/

List pushFront(List list, int x) {
    listElement* element;

    element = (listElement*)malloc(sizeof(listElement));
    if(element == NULL) {
        fprintf(stderr, "Error: promblem of dynamic allocation of memory !");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = list;

    return element; 
}

/************************************************************************************************/

List popBack(List list) {
    // if is empty list
    if(isEmptyList(list))
        return createList();
    
    // if list just have one element
    if(list->next == NULL) {
        free(list);
        list = NULL;
        
        return createList();
    }

    listElement* previousLast = list;
    listElement* last = list;

    // find index of penultimate element
    while (last->next != NULL)
    {
        previousLast = last;
        last = last->next;
    }

    // remove last element
    previousLast->next = NULL;
    free(last);
    last = NULL;

    return list;
}

/************************************************************************************************/

List popFront(List list) {
    if(isEmptyList(list))
        return createList();

    listElement* element = list->next;

    free(list);
    list = NULL;

    return element;
}

/************************************************************************************************/

List clearList(List list) {
    while (list != NULL)
        list = popFront(list);

    return createList();
}

/************************************************************************************************/
