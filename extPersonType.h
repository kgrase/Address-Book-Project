#ifndef __EXTPERSON_TYPE_H__
#define __EXTPERSON_TYPE_H__

#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>

class extPersonType: public personType
{
    public:
    extPersonType():
        personType(),
        birthdate(),
        address(),
        phoneNumber{""},
        relationship{""}
        {}
    extPersonType(std::string nameF, std::string nameL,
        int birthDay, int birthMonth, int birthYear,
        std::string street, std::string city, std::string state, int zip,
        std::string phone,
        std::string status):
            personType(nameF, nameL),
            birthdate(birthMonth, birthDay, birthYear),
            address(street, city, state, zip),
            phoneNumber{phone} {
            setRelationship(status);
        }

    public:
    void setPhoneNumber(std::string phone) {this->phoneNumber = phone;}
    void setRelationship(std::string status);

    public:
    std::string getPhoneNumber() const {return phoneNumber;}
    std::string getRelationship() const {return relationship;}
    int getBirthMonth() const {return this->birthdate.getMonth();}

    public:
    bool operator >= (const extPersonType& other) const;
    bool operator != (const extPersonType& other) const;
    bool operator == (const extPersonType& other) const;

    public:
    friend std::ostream& operator << (std::ostream& os, const extPersonType& person);

    private:
    dateType birthdate;
    addressType address;
    std::string phoneNumber;
    std::string relationship;
};

#endif
