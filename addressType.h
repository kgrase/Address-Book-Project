// addressType.h

#ifndef __ADDRESS_TYPE_H__
#define __ADDRESS_TYPE_H__

#include <ostream>
#include <string>

class addressType {
    public:
    addressType() : addressType("", "", "XX", 10000) {}
    addressType(std::string streetAddress, std::string city, std::string state, int zipcode);

    /* setters */
    public:
    void setStreetAddress(std::string streetAddress);
    void setCity(std::string city);
    void setState(std::string state);
    void setZipcode(int zipcode);
    void setAddress(std::string address);
    /* end setters */

    public:
    friend std::ostream& operator << (std::ostream& os, const addressType& address);

    private:
    std::string streetAddress;
    std::string City;
    std::string State;
    int zipcode;
};

#endif // __ADDRESS_TYPE_H__