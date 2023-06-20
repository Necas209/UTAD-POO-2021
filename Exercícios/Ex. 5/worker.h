#ifndef WORKER_H
#define WORKER_H

#include "../Ex. 4/person.h"
#include <iostream>
#include <fstream>
#include <string>

class worker : public person {
private:
    int worker_id{};
    std::string sector;
    double base_salary{};
    int extra_hours{};
    double extra_hour_val{};
public:
    worker() = default;

    worker(std::string name, date birth_date, std::string address, int worker_id, std::string sector)
            : person(std::move(name), birth_date, std::move(address)),
              worker_id(worker_id), sector(std::move(sector)) {}

    worker(std::string name, date birth_date, std::string address,
           int worker_id, std::string sector, double base_salary,
           int extra_hours, double extra_hour_val)
            : person(std::move(name), birth_date, std::move(address)),
              worker_id(worker_id),
              sector(std::move(sector)),
              base_salary(base_salary),
              extra_hours(extra_hours),
              extra_hour_val(extra_hour_val) {}

    void set_sector(std::string _sector) { sector = std::move(_sector); }

    void set_extra_hours(int _extra_hours) { extra_hours = _extra_hours; }

    [[nodiscard]] int get_worker_id() const { return worker_id; }

    [[nodiscard]] std::string get_sector() const { return sector; }

    [[nodiscard]] double get_base_salary() const { return base_salary; }

    [[nodiscard]] int get_extra_hours() const { return extra_hours; }

    [[nodiscard]] double get_extra_hour_val() const { return extra_hour_val; }

    void print() override;

    void read() override;

    virtual float calculate_salary() = 0;

    friend std::ostream &operator<<(std::ostream &, const worker &);

    friend std::istream &operator>>(std::istream &, worker &);
};

#endif //WORKER_H
