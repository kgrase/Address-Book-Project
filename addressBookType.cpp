#include "addressBookType.h"

void addressBookType::addEntry() {
    //extPersonType person("George", "Smith", 4, 30, 1994, "145 South Street, Apt. 5", "Hampton", "VA", 23554, "757-444-5555", "Friend");
    std::string firstName, lastName;
    int day, month, year, zipCode;
    std::string address, city, state, phoneNumber, relation;

    std::cin.ignore();
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter day of month: ";
    std::cin >> day;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> month;
    std::cout << "Enter Year (> 1900): ";
    std::cin >> year;
    std::cin.ignore();
    std::cout << "Enter steet address: ";
    std::getline(std::cin, address);
    std::cout << "Enter city: ";
    std::getline(std::cin, city);
    std::cout << "Enter state code: ";
    std::getline(std::cin, state);
    std::cout << "Enter zip code: ";
    std::cin >> zipCode;
    std::cin.ignore();
    std::cout << "Enter phone number (xxx-xxx-xxxx): ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter relationship (Friend, Family, Business): ";
    std::getline(std::cin, relation);
    initEntry(extPersonType(firstName, lastName, day, month, year, address, city, state, zipCode, phoneNumber, relation));
}

void addressBookType::deleteEntry(string lastName, string firstName) {
    nodeType<extPersonType> *current; //pointer to traverse the list
    current = this->first;  //start the search at the first node
    while (current != nullptr) {
        if (current->info.getName() == lastName+", "+ firstName) {
            std::string name = current->info.getName();
            this->deleteNode(current->info);
            std::cout << name << " deleted." << std::endl;
            std::cout << "----------------" << std::endl;
            return;
        }
        current = current->link;
    }
    std::cout << "Person not found." << std::endl;
}

void addressBookType::saveData(std::ofstream& dataFile) {
    if (isEmptyList()) {
        return;
    }
    
    nodeType<extPersonType> *current; //pointer to traverse the list

    current = this->first;  //start the search at the first node

    while (current != nullptr) {
        dataFile << current->info.getFirstName() + " " + current->info.getLastName() << std::endl;
        // Write date of birth
        dateType birthDate = current->info.getBirthDate();
        dataFile << birthDate.getDay() << " " << birthDate.getMonth() << " " << birthDate.getYear();
        dataFile << std::endl; // Ignore the newline after the numbers

        // Write address
        addressType address = current->info.getAddress();
        dataFile << address.getAddress() << std::endl;
        dataFile << address.getCity() << std::endl;
        dataFile << address.getState() << std::endl;

        dataFile << address.getZipcode() << std::endl;

        // Read phone number and relation
        dataFile << current->info.getPhoneNumber() << std::endl;
        dataFile << current->info.getRelationship() << std::endl;
        current = current->link;
    }
}

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
        if (current->info.getBirthDate().getMonth() == month) {
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
