#include "dateType.h"
#include <iostream>

bool dateType::checkLeapYear(int year) const {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    else {
        return false;
    }
}

int dateType::isLastDayofMonth(int m, int y) const {
    if (m == 2) {
        bool check = checkLeapYear(y);
        if(check == true) {
            m = 29;
            return m;
        }
        else {
            return 28;
        }
    }
    else if (m == 4 || 6 || 9 || 11) {
        return 30;
    }
    else {
        return 31;
    }
}

void dateType::setDate(int m, int d, int y) {
    if (y >= 1900) {
        year = y;
    }
    else {
        std::cout << "Invlaid Year setting to default value 1900 !" << std::endl;
        year = 1900;
    }

    if (m >= 1 && m <= 12) {
        month = m;
    }
    else {
        std::cout << "Invlaid Month setting to default value 1 !" << std::endl;
        month = 1;
    }

    int isLastday = isLastDayofMonth(m, y);

    if (d >= 1 && d <= isLastday) {
        day = d;
    }
    else {
        std::cout << "Invlaid Date Setting to default value 1 !" << std::endl;
        day = 1;
    }
}
