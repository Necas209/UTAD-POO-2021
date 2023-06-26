#ifndef HIRED_EMPLOYEE_H
#define HIRED_EMPLOYEE_H

#include "employee.h"
#include <iostream>

class hired_employee final : public employee {
private:
    int no_days{};
public:
    hired_employee() = default;

    hired_employee(const std::string &name, const time_point &entry_time, const time_point &exit_time, int no_days)
            : employee(name, entry_time, exit_time), no_days(no_days) {}

    ~hired_employee() override = default;

    [[nodiscard]] int get_no_days() const { return no_days; }

    [[nodiscard]] double salary_per_day() const override {
        return 6.5 * hours_worked();
    }

    void print() override {
        employee::print();
        std::cout << "Number of days: " << no_days << std::endl;
    }

    void read() override {
        employee::read();
        std::cout << "Number of days: ";
        std::cin >> no_days;
        std::cin.ignore();
    }
};

#endif //HIRED_EMPLOYEE_H