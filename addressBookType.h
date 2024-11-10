#ifndef __ADDRESSBOOKTYPE_H__
#define __ADDRESSBOOKTYPE_H__

#include "extPersonType.h"
#include "orderedLinkedList.h"

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    // Initialize entries
    void initEntry(const extPersonType& person) {addEntry(person);}

    // Add a new entry
    void addEntry(const extPersonType& person) {insert(person);}

    // Display all entries
    void print() const;

    // Find a person by last name
    void findPerson(string lastName, std::string firstName) const;

    // Find all birthdays in a given month
    void findBirthdays(int month) const;

    // Find all people by relationship
    void findRelations(string relation) const;
};

#endif
