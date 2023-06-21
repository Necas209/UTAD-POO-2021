#ifndef DATA_H
#define DATA_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class date final {
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
        tm ltm{};
        localtime_s(&ltm, &now_c);
        day = ltm.tm_mday;
        month = 1 + ltm.tm_mon;
        year = 1900 + ltm.tm_year;
    }

    date(int day, int month, int year)
            : day(day), month(month), year(year) {
    }

    ~date() = default;

    [[nodiscard]] int get_day() const { return day; }

    [[nodiscard]] int get_month() const { return month; }

    [[nodiscard]] int get_year() const { return year; }

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

    friend std::ostream &operator<<(std::ostream &os, const date &dt) {
        os << dt.day << date::delim << dt.month << date::delim << dt.year;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, date &dt) {
        char ch;
        is >> dt.day >> ch >> dt.month >> ch >> dt.year;
        return is;
    }
};

#endif // DATA_H