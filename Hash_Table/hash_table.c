#include "hash_table.h"
#include <stdlib.h>

// Fonction pour créer une table de hachage
hash_table_t *create_table(size_t size) {
    hash_table_t *ht = (hash_table_t*)malloc(sizeof(hash_table_t));
    if (!ht) {
        fprintf(stderr, "\nErreur d'allocation de mémoire pour la table\n");
        exit(EXIT_FAILURE);
    }

    ht->size = size;
    ht->table = malloc(sizeof(hash_node_t *) * size);
    if (!ht->table) {
        fprintf(stderr, "\nErreur d'allocation de mémoire pour les noeuds\n");
        free(ht);
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++) {
        ht->table[i] = NULL; // Initialisation des cases à NULL
    }

    return ht;
}

// Fonction pour libérer la mémoire de la table
void free_table(hash_table_t *ht) {
    for (size_t i = 0; i < ht->size; i++) {
        hash_node_t *node = ht->table[i];
        while (node) {
            hash_node_t *temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

// Fonction de hachage (utilisation de la méthode de hachage DJB2)
unsigned long hash_function(const char *key, size_t size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % size; // Retourne un indice dans la plage de la table
}

// Fonction pour insérer un élément dans la table
int insert(hash_table_t *ht, const char *key, const char *value) {
    unsigned long index = hash_function(key, ht->size);

    // Vérification si la clé existe déjà
    hash_node_t *node = ht->table[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            // Si la clé existe déjà, on met à jour la valeur
            free(node->value);
            node->value = strdup(value);
            return 0;
        }
        node = node->next;
    }

    // Si la clé n'existe pas, on insère un nouveau noeud
    hash_node_t *new_node = malloc(sizeof(hash_node_t));
    if (!new_node) {
        fprintf(stderr, "\nErreur d'allocation de mémoire pour le noeud\n");
        return -1;
    }

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->table[index]; // Chaînage des éléments
    ht->table[index] = new_node;

    return 0;
}

// Fonction pour rechercher une valeur par clé
char *search(hash_table_t *ht, const char *key) {
    unsigned long index = hash_function(key, ht->size);

    hash_node_t *node = ht->table[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }

    return NULL; // Clé non trouvée
}

// Fonction pour supprimer un élément par clé
int delete(hash_table_t *ht, const char *key) {
    unsigned long index = hash_function(key, ht->size);

    hash_node_t *node = ht->table[index];
    hash_node_t *prev = NULL;

    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                ht->table[index] = node->next;
            }
            free(node->key);
            free(node->value);
            free(node);
            return 0; // Suppression réussie
        }
        prev = node;
        node = node->next;
    }

    return -1; // Clé non trouvée
}
