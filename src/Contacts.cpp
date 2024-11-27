#include "Contacts.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Ajouter un contact
void addContact(vector<Contact> &contacts) {
    Contact newContact;
    cout << "Entrez le nom : ";
    getline(cin, newContact.name);
    cout << "Entrez le numero de telephone : ";
    getline(cin, newContact.phone);
    cout << "Entrez l'email : ";
    getline(cin, newContact.email);
    cout << "Entrez l'adresse : ";
    getline(cin, newContact.address);
    contacts.push_back(newContact); // Ajout dans la liste des contacts
    cout << "Contact ajoute avec succes !\n";
}

// Afficher tous les contacts
void displayContacts(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "Aucun contact a afficher.\n";
        return;
    }
    cout << "\n--- Liste des Contacts ---\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". Nom : " << contacts[i].name
             << ", Telephone : " << contacts[i].phone
             << ", Email : " << contacts[i].email
             << ", Adresse : " << contacts[i].address << "\n";
    }
}

// Rechercher un contact par nom
void searchContact(const vector<Contact> &contacts) {
    string name;
    cout << "Entrez le nom a rechercher : ";
    getline(cin, name);

    bool found = false;
    for (const auto &contact : contacts) {
        if (contact.name == name) {
            cout << "Nom : " << contact.name
                 << ", Telephone : " << contact.phone
                 << ", Email : " << contact.email
                 << ", Adresse : " << contact.address << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "Aucun contact trouve avec ce nom.\n";
}

// Modifier un contact
void editContact(vector<Contact> &contacts) {
    string name;
    cout << "Entrez le nom du contact a modifier : ";
    getline(cin, name);

    for (auto &contact : contacts) {
        if (contact.name == name) {
            cout << "Modifier le numero de telephone (actuel : " << contact.phone << ") : ";
            getline(cin, contact.phone);
            cout << "Modifier l'email (actuel : " << contact.email << ") : ";
            getline(cin, contact.email);
            cout << "Modifier l'adresse (actuelle : " << contact.address << ") : ";
            getline(cin, contact.address);
            cout << "Contact modifie avec succes !\n";
            return;
        }
    }
    cout << "Aucun contact trouve avec ce nom.\n";
}

// Supprimer un contact
void deleteContact(vector<Contact> &contacts) {
    string name;
    cout << "Entrez le nom du contact a supprimer : ";
    getline(cin, name);

    auto it = remove_if(contacts.begin(), contacts.end(),
                        [&name](const Contact &contact) { return contact.name == name; });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end()); // Suppression des contacts correspondants
        cout << "Contact supprime avec succes !\n";
    } else {
        cout << "Aucun contact trouve avec ce nom.\n";
    }
}

// Trier les contacts par nom
void sortContacts(vector<Contact> &contacts) {
    sort(contacts.begin(), contacts.end(),
         [](const Contact &a, const Contact &b) { return a.name < b.name; });
    cout << "Contacts tries par nom avec succes !\n";
}

// Sauvegarder les contacts dans un fichier
void saveContacts(const vector<Contact> &contacts) {
    ofstream file("contacts.txt");
    if (!file) {
        cerr << "Erreur lors de l'ouverture du fichier pour sauvegarde.\n";
        return;
    }

    for (const auto &contact : contacts) {
        file << contact.name << ","
             << contact.phone << ","
             << contact.email << ","
             << contact.address << "\n";
    }
    file.close();
    cout << "Contacts sauvegardes avec succes !\n";
}


// Charger les contacts depuis un fichier
void loadContacts(vector<Contact> &contacts) {
    ifstream file("contacts.txt");
    if (!file) {
        cerr << "Aucun fichier de contacts trouve. Demarrage avec une liste vide.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = 0;
        Contact contact;

        // Extraction du nom
        pos = line.find(',');
        contact.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Extraction du téléphone
        pos = line.find(',');
        contact.phone = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Extraction de l'email
        pos = line.find(',');
        contact.email = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Le reste est l'adresse
        contact.address = line;

        contacts.push_back(contact);
    }
    file.close();
    cout << "Contacts charges depuis le fichier.\n";
}

