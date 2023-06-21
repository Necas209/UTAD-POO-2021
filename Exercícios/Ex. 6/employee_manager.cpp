#include "employee_manager.h"
#include <algorithm>

void employee_manager::read_file(const std::string &filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file \"" << filename << "\"." << std::endl;
        exit(1);
    }
    while (true) {
        auto c = ifs.peek();
        if (c == EOF) break;
        std::unique_ptr<worker> w;
        std::unique_ptr<administrator> a;
        switch (c) {
            case 'w':
                w = std::make_unique<worker>();
                ifs >> *w >> std::ws;
                employees.push_back(std::move(w));
                break;
            case 'a':
                a = std::make_unique<administrator>();
                ifs >> *a >> std::ws;
                employees.push_back(std::move(a));
                break;
            default:
                throw std::exception("Invalid employee type.");
        }
    }
}

void employee_manager::show_shifts() {
    for (auto &e: employees) {
        auto w = dynamic_cast<worker *>(e.get());
        if (w == nullptr) continue;
        if (w->get_works_shift()) {
            std::cout << "Employee with ID " << w->get_id() << " works shifts." << std::endl;
        }
    }
}

void employee_manager::save_administrators(const std::string &filename) {
    std::ofstream ofs{filename};
    if (!ofs.is_open()) {
        std::cerr << "Error opening file \"" << filename << "\"." << std::endl;
        exit(1);
    }
    for (auto &employee: employees) {
        auto a = dynamic_cast<administrator *>(employee.get());
        if (a == nullptr) continue;
        ofs << *a << std::endl;
    }
}

void employee_manager::save_workers(const std::string &filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error opening file \"" << filename << "\"." << std::endl;
        exit(1);
    }
    for (auto &e: employees) {
        auto w = dynamic_cast<worker *>(e.get());
        if (w == nullptr) continue;
        ofs << *w << std::endl;
    }
}

void employee_manager::save_file(const std::string &filename) {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error opening file \"" << filename << "\"." << std::endl;
        exit(1);
    }
    for (auto &e: employees) {
        auto w = dynamic_cast<worker *>(e.get());
        if (w != nullptr) {
            ofs << *w << std::endl;
            continue;
        }
        auto a = dynamic_cast<administrator *>(e.get());
        if (a != nullptr) {
            ofs << *a << std::endl;
        }
    }
}
