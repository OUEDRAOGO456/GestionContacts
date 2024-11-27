#ifndef CONTACTS_H
#define CONTACTS_H

#include <vector>
#include <string>

// Structure repr�sentant un contact
struct Contact {
    std::string name;    // Nom du contact
    std::string phone;   // Num�ro de t�l�phone
    std::string email;   // Adresse email
    std::string address; // Adresse physique
};

// D�clarations des fonctions
void addContact(std::vector<Contact> &contacts);
void displayContacts(const std::vector<Contact> &contacts);
void searchContact(const std::vector<Contact> &contacts);
void editContact(std::vector<Contact> &contacts);
void deleteContact(std::vector<Contact> &contacts);
void sortContacts(std::vector<Contact> &contacts);
void saveContacts(const std::vector<Contact> &contacts);
void loadContacts(std::vector<Contact> &contacts);

#endif // CONTACTS_H
