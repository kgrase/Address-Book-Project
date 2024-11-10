#include "addressBookType.h"

// Display all entries
void addressBookType::print() const {
    if (isEmptyList()) {
        cout << "Address book is empty." << std::endl;
        return;
    }
    
    nodeType<extPersonType> *current; //pointer to traverse the list

    current = this->first;  //start the search at the first node

    while (current != nullptr) {
        std::cout << current->info << std::endl;
        std::cout << "----------------" << std::endl;
        current = current->link;
    }
}

// Find a person by last name
void addressBookType::findPerson(std::string lastName, std::string firstName) const {
    bool found = false;
    nodeType<extPersonType> *current; //pointer to traverse the list
    current = this->first;  //start the search at the first node
    while (current != nullptr) {
        if (current->info.getName() == lastName+", "+ firstName) {
            std::cout << current->info << std::endl;
            std::cout << "----------------" << std::endl;
            found = true;
        }
        current = current->link;
    }
    if (!found)
        std::cout << "Person not found." << std::endl;
}

// Find all birthdays in a given month
void addressBookType::findBirthdays(int month) const {
    bool found = false;
    nodeType<extPersonType> *current; //pointer to traverse the list
    current = this->first;  //start the search at the first node
    while (current != nullptr) {
        if (current->info.getBirthMonth() == month) {
            std::cout << current->info << std::endl;
            std::cout << "----------------" << std::endl;
            found = true;
        }
        current = current->link;
    }
    if (!found)
        cout << "No birthdays found in this month." << std::endl;
}

// Find all people by relationship
void addressBookType::findRelations(std::string relation) const {
    bool found = false;
    nodeType<extPersonType> *current; //pointer to traverse the list
    current = this->first;  //start the search at the first node
    while (current != nullptr) {
        if (current->info.getRelationship() == relation) {
            std::cout << current->info << std::endl;
            std::cout << "----------------" << std::endl;
            found = true;
        }
        current = current->link;
    }
    if (!found) {
        cout << "No entries with this relationship." << std::endl;
    }
}
