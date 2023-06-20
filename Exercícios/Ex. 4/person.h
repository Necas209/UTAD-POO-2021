#ifndef PERSON_H
#define PERSON_H

#include "../Ex. 3/date.h"
#include <iostream>
#include <fstream>
#include <string>

class person {
private:
    std::string name;
    date birth_date;
    std::string address;
public:
    person() = default;

    person(std::string name, date birth_date, std::string address)
            : name(std::move(name)), birth_date(birth_date), address(std::move(address)) {}

    void set_name(std::string _name) { name = std::move(_name); }

    void set_birth_date(date _birth_date) { birth_date = _birth_date; }

    void set_address(std::string _address) { address = std::move(_address); }

    [[nodiscard]] std::string get_name() const { return name; }

    [[nodiscard]] date get_birth_date() const { return birth_date; }

    [[nodiscard]] std::string get_address() const { return address; }

    [[nodiscard]] bool is_younger(const person &p) const {
        return birth_date < p.birth_date;
    }

    virtual void print();

    virtual void read();

    friend bool operator==(const person &lhs, const person &rhs) {
        return lhs.name == rhs.name &&
               lhs.birth_date == rhs.birth_date &&
               lhs.address == rhs.address;
    }

    friend bool operator!=(const person &lhs, const person &rhs) {
        return !(rhs == lhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const person &p);

    friend std::istream &operator>>(std::istream &is, person &p);
};

#endif //PERSON_H