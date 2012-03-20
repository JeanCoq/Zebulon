/* 
 * File:   Date.cpp
 * Author: bicodul
 * 
 * Created on February 8, 2012, 6:32 PM
 */

#include "Date.h"

Date::Date(int day, int month, int year, int hour, int min) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->min = min;
}


Date::Date(const Date& orig) {
    this->day = orig.day;
    this->month = orig.month;
    this->year = orig.year;
    this->hour = orig.hour;
    this->min = orig.min;
}

bool Date::isLeapYear(int y) {
    return (y%4 == 0 && y%100 != 0) || (y%400 == 0);
}

int Date::duration() const {
    int nbmin = min + hour*60 + day*60*24;
    int nbminM;
    if((month%2 == 1 && month <= 7) || (month%2 == 0 && month > 7))
        nbminM = month*31*24*60;
    else if(month == 2)
        nbminM = month*28*24*60;
    else
        nbminM = month*30*24*60;
    if(Date::isLeapYear(year)) {
        nbmin = nbmin + year*366*24*60;
        if(day == 2)
            nbminM = nbminM + 2*29*24*60;      
    }
    else
        nbmin = nbmin + year*365*24*60;
    
    return nbmin + nbminM;
}

Date::~Date() {
}

ostream& operator <<(ostream& os, const Date *d) {
    os << d->GetDay() << "/" << d->GetMonth() << "/" << d->GetYear() << " " << d->GetHour() << ":" << d->GetMin();
    return os;
}

/*Limité à min < 4h*/
Date* operator +(const Date& date, int min) {
    if(min < 4*60) {
        Date *date2 = new Date(date);
        int nbMin = date2->GetMin() + min;
        if(nbMin >= 60) {
            date2->SetMin(nbMin%60);
            date2->SetHour(date2->GetHour()+((int) nbMin/60));
        }
        else
            date2->SetMin(nbMin);
        return date2;
    }
    else return NULL;
}

bool operator==(Date const& d1, Date const& d2) {
    return  d1.GetMin() == d2.GetMin() &&
            d1.GetHour() == d2.GetHour() &&
            d1.GetDay() == d2.GetDay() &&
            d1.GetMonth() == d2.GetMonth() &&
            d1.GetYear() == d2.GetYear();
            
}
bool operator<(Date const& d1, Date const& d2) {
    return d1.duration() < d2.duration();    
}
bool operator>(Date const& d1, Date const& d2) {
    return d1.duration() < d2.duration();
}
bool operator<=(Date const& d1, Date const& d2) {
    return d1<d2 || d1==d2;
}
bool operator>=(Date const& d1, Date const& d2) {
    return d1>d2 || d1==d2;
}

