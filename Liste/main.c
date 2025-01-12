#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    List myList = createList();

    // Test 1: Vérifier si la liste est vide
    printf("Test 1: Vérifier si la liste est vide\n");
    if (isEmptyList(myList)) 
        printf("La liste est vide.\n");
    else 
        printf("La liste n'est pas vide.\n");

    // Test 2: Ajouter des éléments à la liste (pushFront)
    printf("\nTest 2: Ajouter des éléments au début de la liste\n");
    myList = pushFront(myList, 10);
    myList = pushFront(myList, 20);
    myList = pushFront(myList, 30);
    printList(myList);

    // Test 3: Ajouter des éléments à la fin de la liste (pushBack)
    printf("\nTest 3: Ajouter des éléments à la fin de la liste\n");
    myList = pushBack(myList, 40);
    myList = pushBack(myList, 50);
    printList(myList);

    // Test 4: Longueur de la liste
    printf("\nTest 4: Longueur de la liste\n");
    printf("La longueur de la liste est : %d\n", listLength(myList));

    // Test 5: Supprimer un élément à la fin de la liste (popBack)
    printf("\nTest 5: Supprimer un élément à la fin de la liste\n");
    myList = popBack(myList);
    printList(myList);

    // Test 6: Supprimer un élément au début de la liste (popFront)
    printf("\nTest 6: Supprimer un élément au début de la liste\n");
    myList = popFront(myList);
    printList(myList);

    // Test 7: Effacer la liste entière
    printf("\nTest 7: Effacer la liste entière\n");
    myList = clearList(myList);
    printList(myList);

    // Test 8: Vérifier si la liste est vide après nettoyage
    printf("\nTest 8: Vérifier si la liste est vide après nettoyage\n");
    if (isEmptyList(myList)) 
        printf("La liste est vide.\n");
    else 
        printf("La liste n'est pas vide.\n");

    return 0;
}
