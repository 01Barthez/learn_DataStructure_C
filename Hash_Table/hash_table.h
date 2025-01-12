#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Définition d'une structure pour les éléments de la table de hachage
typedef struct hash_node {
    char *key;            // Clé
    char *value;          // Valeur associée à la clé
    struct hash_node *next; // Pointeur vers le prochain élément (chaînage pour gérer les collisions)
} hash_node_t;

// Définition de la table de hachage
typedef struct hash_table {
    size_t size;         // Taille de la table
    hash_node_t **table; // Tableau de pointeurs vers des noeuds
} hash_table_t;

// Prototypes des fonctions
hash_table_t *create_table(size_t size);
void free_table(hash_table_t *ht);
unsigned long hash_function(const char *key, size_t size);
int insert(hash_table_t *ht, const char *key, const char *value);
char *search(hash_table_t *ht, const char *key);
int delete(hash_table_t *ht, const char *key);

#endif // _HASH_TABLE_H
