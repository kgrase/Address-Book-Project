#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For sort
#include <fstream>
#include "addressBookType.h"


// Function to display the menu
int showMenu() {
    int choice;
    cout << "\nOnline Address Book\n";
    cout << "1 - Display all entries\n";
    cout << "2 - Display an entry by person's name\n";
    cout << "3 - Display all entries with a given birth month\n";
    cout << "4 - Display all entries with a given relationship\n";
    cout << "5 - Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;
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
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            myAddressBook.findPerson(lastName, firstName);
            break;
        }
        case 3: {
            int month;
            cout << "Enter birth month: ";
            cin >> month;
            myAddressBook.findBirthdays(month);
            break;
        }
        case 4: {
            string relationship;
            cout << "Enter relationship (Friend, Family, Business): ";
            cin >> relationship;
            myAddressBook.findRelations(relationship);
            break;
        }
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
