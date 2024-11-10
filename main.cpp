#include <iostream>
#include <string>
#include <fstream>
#include "addressBookType.h"


// Function to display the menu
int showMenu() {
    int choice;
    std::cout << "\nOnline Address Book\n";
    std::cout << "1 - Display all entries\n";
    std::cout << "2 - Display an entry by person's name\n";
    std::cout << "3 - Display all entries with a given birth month\n";
    std::cout << "4 - Display all entries with a given relationship\n";
    std::cout << "5 - Quit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int main() {
    
    addressBookType myAddressBook; // Create an address book with max size 100

    std::ifstream dataFile("AddressBookData 2.txt");
    if (!dataFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string firstName, lastName;
    int day, month, year, zipCode;
    std::string address, city, state, phoneNumber, relation;

    while (dataFile) {
        // Read name
        if (!std::getline(dataFile, firstName, ' ') || !std::getline(dataFile, lastName)) {
            break; // End of file or read error
        }

        // Read date of birth
        dataFile >> day >> month >> year;
        dataFile.ignore(); // Ignore the newline after the numbers

        // Read address
        std::getline(dataFile, address);
        std::getline(dataFile, city);
        std::getline(dataFile, state);

        dataFile >> zipCode;
        dataFile.ignore(); // Ignore the newline after the numbers

        // Read phone number and relation
        std::getline(dataFile, phoneNumber);
        std::getline(dataFile, relation);

        myAddressBook.initEntry(extPersonType(firstName, lastName, day, month, year, address, city, state, zipCode, phoneNumber, relation));
    }

    dataFile.close(); // Close the file

    std::string line;
    while (std::getline(dataFile, line)) { // Read each line
        std::cout << line << std::endl; // Print the line to console
    }

    dataFile.close(); // Close the file

    int choice;
    do {
        choice = showMenu();
        switch (choice) {
        case 1:
            myAddressBook.print();
            break;
        case 2: {
            std::string lastName;
            std::string firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            myAddressBook.findPerson(lastName);
            break;
        }
        case 3: {
            int month;
            std::cout << "Enter birth month: ";
            std::cin >> month;
            myAddressBook.findBirthdays(month);
            break;
        }
        case 4: {
            std::string relationship;
            std::cout << "Enter relationship (Friend, Family, Business): ";
            std::cin >> relationship;
            myAddressBook.findRelations(relationship);
            break;
        }
        case 5:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
