#include "addressType.h"
#include <iostream>

addressType::addressType(std::string streetAddress, std::string city, std::string state, int zipcode) {
    this->streetAddress = streetAddress;
    this->City = city;
    this->State = state;
    this->zipcode = zipcode;
}

void addressType::setCity(std::string city) {
    this->City = city;
}

void addressType::setState(std::string state) {
    if (state.length() == 2) {
        this->State = state;
    }
    else {
        std::cout << "State length exceeded with more than two chracters !" << std::endl;
        std::cout << "Only Two character Allowed !" << std::endl;
        std::cout << "setting default value XX....... " << std::endl;
        this->State = "XX";
    }
}

void addressType::setZipcode(int zip) {
    if (zip >= 11111 && zip <= 99999) {
        this->zipcode = zip;
    }
    else {
        std::cout << "Zipcode length should between 11111 and 99999 !" << std::endl;
        std::cout << "setting default value 10000....... " << std::endl;
        this->zipcode = 10000;
    }
}

void addressType::setAddress(std::string address) {
    this->streetAddress = address;
}

std::ostream& operator << (std::ostream& os, const addressType& address) {
    os << address.streetAddress << std::endl;
    os << address.City << ", ";
    os << address.State<<" ";
    os << address.zipcode<<" ";
    return os;
}
