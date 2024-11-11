#ifndef __DATE_TYPE_H__
#define __DATE_TYPE_H__

#include <ostream>

class dateType {
   public:
   dateType() : dateType(1, 1, 1990) {}
   dateType(int m, int d, int y) {setDate(m, d, y);}

   public:
   bool checkLeapYear(int year) const;
   int isLastDayofMonth(int m, int y) const;
   int getMonth() const {return month;}
   int getDay() const {return day;}
   int getYear() const {return year;}

   void setDate(int m, int d, int y);

   public:
   friend std::ostream& operator << (std::ostream& os, const dateType& date) {
      os << date.month << "/" << date.day << "/" << date.year;
      return os;
   }

   private:
   int month;
   int day;
   int year;
};

#endif
