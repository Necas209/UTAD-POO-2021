#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "administrator.h"
#include "worker.h"
#include <iostream>
#include <vector>

typedef std::unique_ptr<employee> employee_ptr;
typedef std::vector<employee_ptr>::iterator iterator;

class employee_manager final {
private:
    std::vector<employee_ptr> employees;
public:
    employee_manager() = default;

    ~employee_manager() = default;

    void add_employee(employee_ptr &&employee) {
        employees.push_back(std::move(employee));
    }

    void remove_by_id(int id) {
        auto e = find_by_id(id);
        if (e == employees.end()) return;
        employees.erase(e);
    }

    void remove_all() { employees.clear(); }

    iterator end() { return employees.end(); }

    void print_salaries() {
        for (auto &e: employees) {
            std::cout << "Employee with ID " << e->get_id()
                      << " has a salary of " << e->calculate_salary() << std::endl;
        }
    }

    iterator find_by_id(int id) {
        return std::ranges::find_if(employees, [&id](const auto &e) {
            return e->get_id() == id;
        });
    }

    void change_base_salary(int id, double salary) {
        auto e = find_by_id(id);
        if (e == employees.end() || salary < 0.0) return;
        (*e)->set_base_salary(salary);
    }

    void show_shifts();

    void read_file(const std::string &filename = "employees.txt");

    void save_file(const std::string &filename = "employees.txt");

    void save_administrators(const std::string &filename = "administrators.txt");

    void save_workers(const std::string &filename = "workers.txt");
};

#endif //EMPLOYEE_MANAGER_H