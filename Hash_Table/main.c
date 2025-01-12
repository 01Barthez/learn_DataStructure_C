#include "hash_table.h"

int main() {
    // Création de la table de hachage
    hash_table_t *ht = create_table(10);
    if (!ht) {
        return -1;
    }

    // Insertion de données
    insert(ht, "name", "John Doe");
    insert(ht, "email", "john@example.com");

    // Recherche d'une valeur
    char *name = search(ht, "name");
    if (name) {
        printf("Nom: %s\n", name);
    } else {
        printf("Clé 'name' non trouvée\n");
    }

    // Suppression d'une clé
    if (delete(ht, "email") == 0) {
        printf("Clé 'email' supprimée\n");
    }

    // Libération de la mémoire
    free_table(ht);
    return 0;
}
