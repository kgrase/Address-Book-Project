#include "extPersonType.h"

#include <iostream>

void extPersonType::setRelationship(std::string status) {
    if(status == "Family" || status == "Friend" || status == "Business")
        relationship = status;
    else
        relationship = "";
}

std::ostream& operator << (std::ostream& os, const extPersonType& person) {
    os << static_cast<const personType&>(person) << std::endl;
    os << person.birthdate << std::endl;
    os << person.address << std::endl;
    if(person.relationship != "")
        os << "Relationship: " << person.relationship;
    return os;
}

bool extPersonType::operator >= (const extPersonType& other) const {
    return this->getName() >= other.getName();
}

bool extPersonType::operator != (const extPersonType& other) const {
    return this->getName() != other.getName();
}

bool extPersonType::operator == (const extPersonType& other) const {
    return this->getName() == other.getName();
}

