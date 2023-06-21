#include "employee_manager.h"
#include <iostream>
#include <string>

int read_id() {
    int id;
    std::cout << "Employee ID: ";
    std::cin >> id;
    std::cin.ignore();
    return id;
}

int main() {
    employee_manager mgr;
    while (true) {
        std::cout << "Employee manager" << std::endl;
        std::cout << "\t1 - Read from file" << std::endl;
        std::cout << "\t2 - Print salaries" << std::endl;
        std::cout << "\t3 - Find employee (by ID)" << std::endl;
        std::cout << "\t4 - Change base salary (by ID)" << std::endl;
        std::cout << "\t5 - Add employee" << std::endl;
        std::cout << "\t6 - Remove employee (by ID)" << std::endl;
        std::cout << "\t7 - Show shifts" << std::endl;
        std::cout << "\t8 - Save administrators" << std::endl;
        std::cout << "\t9 - Save workers" << std::endl;
        std::cout << "\t10 - Save all" << std::endl;
        std::cout << "\t11 - Remove all" << std::endl;
        std::cout << "\t0 - Exit" << std::endl;
        int option;
        std::cout << "Option: ";
        std::cin >> option;
        std::cin.ignore();
        int id;
        std::string file_name;
        iterator employee_it;
        employee_ptr e;
        switch (option) {
            case 1:
                std::cout << "File name (by default, \"employees.txt\"): ";
                std::getline(std::cin, file_name);
                if (file_name.empty()) {
                    mgr.read_file();
                } else {
                    mgr.read_file(file_name);
                }
                break;
            case 2:
                mgr.print_salaries();
                break;
            case 3:
                id = read_id();
                employee_it = mgr.find_by_id(id);
                if (employee_it != mgr.end()) {
                    std::cout << "Employee found: " << **employee_it << std::endl;
                } else {
                    std::cout << "Employee not found." << std::endl;
                }
                break;
            case 4:
                id = read_id();
                double salary;
                std::cout << "New salary: ";
                std::cin >> salary;
                std::cin.ignore();
                mgr.change_base_salary(id, salary);
                break;
            case 5:
                std::cout << "Employee type:" << std::endl;
                std::cout << "\t1 - Worker" << std::endl;
                std::cout << "\t2 - Administrator" << std::endl;
                int type;
                std::cout << "Option: ";
                std::cin >> type;
                std::cin.ignore();
                switch (type) {
                    case 1:
                        e = std::make_unique<worker>();
                        break;
                    case 2:
                        e = std::make_unique<administrator>();
                        break;
                    default:
                        std::cout << "Invalid option." << std::endl;
                        continue;
                }
                e->read();
                mgr.add_employee(std::move(e));
                break;
            case 6:
                id = read_id();
                mgr.remove_by_id(id);
                break;
            case 7:
                mgr.show_shifts();
                break;
            case 8:
                std::cout << "File name (by default, \"administrators.txt\"): ";
                std::getline(std::cin, file_name);
                if (file_name.empty()) {
                    mgr.save_administrators();
                } else {
                    mgr.save_administrators(file_name);
                }
                break;
            case 9:
                std::cout << "File name (by default, \"workers.txt\"): ";
                std::getline(std::cin, file_name);
                if (file_name.empty()) {
                    mgr.save_workers();
                } else {
                    mgr.save_workers(file_name);
                }
                break;
            case 10:
                std::cout << "File name (by default, \"employees.txt\"): ";
                std::getline(std::cin, file_name);
                if (file_name.empty()) {
                    mgr.save_file();
                } else {
                    mgr.save_file(file_name);
                }
                break;
            case 11:
                mgr.remove_all();
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                exit(0);
            default:
                std::cout << "Invalid option." << std::endl;
        }
        system("pause");
        system("cls");
    }
}
