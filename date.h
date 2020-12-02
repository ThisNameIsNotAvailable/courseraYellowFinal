//
// Created by Alexey Valevich on 11/11/2020.
//

#pragma once

#include <iostream>

using namespace std;



class Date {
public:
    Date(int year = -1, int month = 0, int day = 0) : year_(year), month_(month), day_(day) {}
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    friend ostream& operator <<(ostream& os, const Date& d);
    friend bool operator < (const Date& d1, const Date& d2);
    friend bool operator <= (const Date& d1, const Date& d2);
    friend bool operator >= (const Date& d1, const Date& d2);
    friend bool operator > (const Date& d1, const Date& d2);
    friend bool operator != (const Date& d1, const Date& d2);
    friend bool operator ==(const Date& d1, const Date& d2);
private:
    int year_, month_, day_;
};
Date ParseDate(istream& is);
