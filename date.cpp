//
// Created by Alexey Valevich on 11/11/2020.
//

#include "date.h"

#include <tuple>

int Date::getYear() const {
    return year_;
}

int Date::getMonth() const {
    return month_;
}

int Date::getDay() const {
    return day_;
}

bool operator ==(const Date& d1, const Date& d2) {
    return make_tuple(d1.year_, d1.month_, d1.day_) == make_tuple(d2.year_, d2.month_, d2.day_);
}

bool operator < (const Date& d1, const Date& d2) {
    return make_tuple(d1.year_, d1.month_, d1.day_) < make_tuple(d2.year_, d2.month_, d2.day_);
}

bool operator <= (const Date& d1, const Date& d2) {
    return make_tuple(d1.year_, d1.month_, d1.day_) <= make_tuple(d2.year_, d2.month_, d2.day_);
}

bool operator > (const Date& d1, const Date& d2) {
    return make_tuple(d1.year_, d1.month_, d1.day_) > make_tuple(d2.year_, d2.month_, d2.day_);
}

bool operator >= (const Date& d1, const Date& d2) {
    return make_tuple(d1.year_, d1.month_, d1.day_) >= make_tuple(d2.year_, d2.month_, d2.day_);
}

bool operator != (const Date& d1, const Date& d2) {
    return make_tuple(d1.year_, d1.month_, d1.day_) != make_tuple(d2.year_, d2.month_, d2.day_);
}

Date ParseDate(istream& is) {
    string date;
    is >> date;
    while (date == " ") {
        is >> date;
    }
    int year = atoi(date.substr(0, date.find('-')).c_str());
    date = date.substr(date.find('-') + 1);
    int month = atoi(date.substr(0, date.find('-')).c_str());
    date = date.substr( date.find('-') + 1);
    int day = atoi(date.c_str());
    return {year, month, day};
}

ostream& operator <<(ostream& os, const Date& d) {
    if(d.year_ < 10) {
        os << 0 << 0 << 0 << d.year_ << "-";
    }else if(d.year_ < 100) {
        os << 0 << 0 << d.year_ << "-";
    }else if(d.year_ < 1000) {
        os << 0 << d.year_ << "-";
    }else
        os << d.year_ << "-";

    if(d.month_ < 10) {
        os << 0 << d.month_ << "-";
    }else
        os << d.month_ << "-";

    if(d.day_ < 10) {
        os << 0 << d.day_;
    }else
        os << d.day_;

    return os;

}