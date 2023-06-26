#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../Ex. 4/person.h"
#include <iostream>
#include <fstream>
#include <string>

class employee : public person {
protected:
    int id{};
    std::string sector;
    double base_salary{};
    int extra_hours{};
public:
    employee() = default;

    employee(std::string name, date birth_date, std::string address, int worker_id, std::string sector,
             double base_salary, int extra_hours)
            : person(std::move(name), birth_date, std::move(address)),
              id(worker_id),
              sector(std::move(sector)),
              base_salary(base_salary),
              extra_hours(extra_hours) {}

    ~employee() override = default;

    void set_sector(std::string _sector) { sector = std::move(_sector); }

    void set_base_salary(double _base_salary) { base_salary = _base_salary; }

    void set_extra_hours(int _extra_hours) { extra_hours = _extra_hours; }

    [[nodiscard]] int get_id() const { return id; }

    [[nodiscard]] std::string get_sector() const { return sector; }

    [[nodiscard]] double get_base_salary() const { return base_salary; }

    [[nodiscard]] int get_extra_hours() const { return extra_hours; }

    void print() override;

    void read() override;

    virtual double calculate_salary() = 0;

    [[nodiscard]] virtual double get_extra_hour_val() const = 0;

    friend std::ostream &operator<<(std::ostream &, const employee &);

    friend std::istream &operator>>(std::istream &, employee &);
};

#endif //EMPLOYEE_H
