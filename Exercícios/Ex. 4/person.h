#ifndef PERSON_H
#define PERSON_H

#include "../Ex. 3/date.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

class person {
private:
    std::string name;
    date birth_date;
    std::string address;
public:
    person() = default;

    person(std::string name, date birth_date, std::string address)
            : name(std::move(name)), birth_date(birth_date), address(std::move(address)) {}

    virtual ~person() = default;

    void set_name(std::string &_name) { name = _name; }

    void set_birth_date(date _birth_date) { birth_date = _birth_date; }

    void set_address(std::string &_address) { address = _address; }

    std::string get_name() const { return name; }

    date get_birth_date() const { return birth_date; }

    std::string get_address() const { return address; }

    virtual bool is_younger(const person &p) const {
        return birth_date < p.birth_date;
    }

    friend bool operator==(const person &lhs, const person &rhs) {
        return lhs.name == rhs.name &&
               lhs.birth_date == rhs.birth_date &&
               lhs.address == rhs.address;
    }

    friend bool operator!=(const person &lhs, const person &rhs) {
        return !(rhs == lhs);
    }

    friend ostream &operator<<(ostream &os, const person &p) {
        os << "person{"
           << "name='" << p.name << '\''
           << ", birth_date=" << p.birth_date
           << ", address='" << p.address << '\''
           << '}';
        return os;
    }

    friend istream &operator>>(istream &is, person &p) {
        std::string input;
        std::getline(is, input);
        // Deserialize the input string
        size_t nameStart = input.find("name='") + 6;
        size_t nameEnd = input.find('\'', nameStart);
        p.name = input.substr(nameStart, nameEnd - nameStart);
        size_t birthDateStart = input.find("birth_date=") + 12;
        size_t birthDateEnd = input.find(',', birthDateStart);
        std::string bds = input.substr(birthDateStart, birthDateEnd - birthDateStart);
        std::istringstream(bds) >> p.birth_date;
        size_t addressStart = input.find("address='") + 9;
        size_t addressEnd = input.find('\'', addressStart);
        p.address = input.substr(addressStart, addressEnd - addressStart);
        return is;
    }
};

#endif //PERSON_H