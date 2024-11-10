#ifndef __PERSON_TYPE_H__
#define __PERSON_TYPE_H__

#include <iostream>
#include <string>

class personType {
    public:
    personType() : personType("", "") {}
    personType(std::string nameFirst, std::string nameLast): firstName{nameFirst}, lastName{nameLast} {}

    public:
    void setFirstName(std::string nameFirst) {this->firstName = nameFirst;}
    void setLastName(std::string nameLast) {this->lastName = nameLast;}

    public:
    std::string getFirstName() const {return this->firstName;}
    std::string getLastName() const {return this->lastName;}
    std::string getName() const {return this->lastName + ", " + this->firstName;}

    public:
    friend std::ostream& operator << (std::ostream& os, const personType& person) {
        os << person.firstName << " " << person.lastName;
        return os;
    }

    private:
    std::string firstName;
    std::string lastName;
};

#endif
