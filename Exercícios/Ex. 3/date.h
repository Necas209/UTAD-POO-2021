#ifndef DATA_H
#define DATA_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class date {
private:
    static const char delim = '/';
    int day;
    int month;
    int year;
public:
    date() {
        // Get current date
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        tm *ltm = localtime(&now_c);
        day = ltm->tm_mday;
        month = 1 + ltm->tm_mon;
        year = 1900 + ltm->tm_year;
    }

    date(int day, int month, int year)
            : day(day), month(month), year(year) {
    }

    friend bool operator==(const date &lhs, const date &rhs) {
        return (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year);
    }

    friend bool operator!=(const date &lhs, const date &rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const date &lhs, const date &rhs) {
        return (lhs.year < rhs.year || (lhs.year == rhs.year && lhs.month < rhs.month) ||
                (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day));
    }

    friend bool operator>(const date &lhs, const date &rhs) {
        return (lhs.year > rhs.year || (lhs.year == rhs.year && lhs.month > rhs.month) ||
                (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day > rhs.day));
    }

    friend bool operator<=(const date &lhs, const date &rhs) {
        return !(lhs > rhs);
    }

    friend bool operator>=(const date &lhs, const date &rhs) {
        return !(lhs < rhs);
    }

    date &operator++() {
        ++day;
        return *this;
    }

    date operator++(int) {
        date temp(*this);
        ++day;
        return temp;
    }

    friend ostream &operator<<(ostream &os, const date &D) {
        os << D.day << date::delim << D.month << date::delim << D.year;
        return os;
    }

    friend istream &operator>>(istream &is, date &D) {
        std::string line;
        std::getline(is, line);
        std::istringstream iss(line);
        char ch;
        iss >> D.day >> ch >> D.month >> ch >> D.year >> std::ws;
        return is;
    }
};

#endif // DATA_H