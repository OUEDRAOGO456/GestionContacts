#include <iostream>
#include "Contacts.h"

using namespace std;

int main() {
    vector<Contact> contacts; // Liste des contacts
    loadContacts(contacts);  // Chargement initial des contacts depuis le fichier

    int choice;
    do {

        // Menu principal
        cout << "\n--- Gestionnaire de Contacts ---\n\n";
        cout << "1. Ajouter un contact\n";
        cout << "2. Afficher tous les contacts\n";
        cout << "3. Rechercher un contact\n";
        cout << "4. Modifier un contact\n";
        cout << "5. Supprimer un contact\n";
        cout << "6. Trier les contacts par nom\n";
        cout << "7. Sauvegarder les contacts\n";
        cout << "8. Quitter\n\n";
        cout << "Choisissez une option : ";
        cin >> choice;
        cin.ignore(); // Ignorer les retours à la ligne résiduels

        // Gestion des options
        switch (choice) {
            case 1: addContact(contacts); break;
            case 2: displayContacts(contacts); break;
            case 3: searchContact(contacts); break;
            case 4: editContact(contacts); break;
            case 5: deleteContact(contacts); break;
            case 6: sortContacts(contacts); break;
            case 7: saveContacts(contacts); break;
            case 8: saveContacts(contacts); cout << "Au revoir!\n"; break;
            default: cout << "Option invalide. Réessayez.\n";
        }
    } while (choice != 8);

    return 0;
}
