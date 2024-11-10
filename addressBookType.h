#ifndef __ADDRESSBOOKTYPE_H__
#define __ADDRESSBOOKTYPE_H__

#include <vector>
#include "extPersonType.h"

class addressBookType {
    public:
    // Constructor
    addressBookType(int size = 100): maxSize(size), length(0) {addressList.resize(maxSize);}

    // Initialize entries
    void initEntry(const extPersonType& person) {addEntry(person);}

    // Add a new entry
    void addEntry(const extPersonType& person);

    // Display all entries
    void print() const;

    // Find a person by last name
    void findPerson(std::string lastName) const;

    // Find all birthdays in a given month
    void findBirthdays(int month) const;

    // Find all people by relationship
    void findRelations(std::string relation) const;

    // Sort entries by last name
    void sortEntries();

    private:
    std::vector<extPersonType> addressList;
    int maxSize;
    int length;
};

#endif
