#include <algorithm>
#include "addressBookType.h"

void  addressBookType::addEntry(const extPersonType& person) {
    if (length < maxSize) {
        addressList[length] = person;
        length++;
    } else {
        std::cout << "Address book is full!" << std::endl;
    }
    sortEntries();
}

// Display all entries
void addressBookType::print() const {
    for (int i = 0; i < length; i++) {
            std::cout << addressList[i] << std::endl;
        }
}

// Find a person by last name
void addressBookType::findPerson(std::string lastName) const {
    for (int i = 0; i < length; i++) {
        if (addressList[i].getLastName() == lastName) {
            std::cout << addressList[i] << std::endl;
            return;
        }
    }
    std::cout << "Person not found." << std::endl;
}

// Find all birthdays in a given month
void addressBookType::findBirthdays(int month) const {
    bool found = false;
    for (int i = 0; i < length; i++) {
        if (addressList[i].getBirthMonth() == month) { // Assuming MM/DD/YYYY format
            std::cout << addressList[i] << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No birthdays found in this month." << std::endl;
    }
}

// Find all people by relationship
void addressBookType::findRelations(std::string relation) const {
    bool found = false;
    for (int i = 0; i < length; i++) {
        if (addressList[i].getRelationship() == relation) {
            std::cout << addressList[i] << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No entries with this relationship." << std::endl;
    }
}

// Sort entries by last name
void addressBookType::sortEntries() {
    sort(addressList.begin(), addressList.begin() + length, [](const extPersonType& a, const extPersonType& b) {
        return a.getLastName() < b.getLastName();
    });
    std::cout << "Entries sorted by last name." << std::endl;
}
