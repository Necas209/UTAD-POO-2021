#include "worker.h"

void worker::print() {
    person::print();
    std::cout << "Worker ID: " << worker_id << std::endl;
    std::cout << "Sector: " << sector << std::endl;
    std::cout << "Base salary: " << base_salary << std::endl;
    std::cout << "Extra hours: " << extra_hours << std::endl;
}

void worker::read() {
    person::read();
    std::cout << "Worker ID: ";
    std::cin >> worker_id;
    std::cin.ignore();
    std::cout << "Sector: ";
    getline(std::cin, sector);
    std::cout << "Base salary: ";
    std::cin >> base_salary;
    std::cin.ignore();
    std::cout << "Extra hours: ";
    std::cin >> extra_hours;
    std::cin.ignore();
}

std::ostream &operator<<(std::ostream &os, const worker &w) {
    os << "worker{"
       << "person=" << (person &) w
       << ", worker_id=" << w.worker_id
       << ", sector='" << w.sector << '\''
       << ", base_salary=" << w.base_salary
       << ", extra_hours=" << w.extra_hours
       << ", extra_hour_val=" << w.extra_hour_val
       << '}';
    return os;
}

std::istream &operator>>(std::istream &is, worker &w) {
    // Read the entire line containing the worker object
    std::string input;
    std::getline(is, input);
    // Find the position of the person part within the input string
    size_t personStart = input.find("person=") + 7;
    size_t personEnd = input.find("},", personStart) + 1;
    // Extract the person part substring
    std::string personPart = input.substr(personStart, personEnd - personStart);
    // Deserialize the person part into the base class object
    std::istringstream personStream(personPart);
    personStream >> static_cast<person &>(w);
    // Find the position of the worker-specific part within the input string
    // Worker ID
    size_t workerIdStart = input.find("worker_id=", personEnd) + 10;
    size_t workerIdEnd = input.find(',', workerIdStart);
    w.worker_id = std::stoi(input.substr(workerIdStart, workerIdEnd - workerIdStart));
    // Sector
    size_t sectorStart = input.find("sector='", workerIdEnd) + 8;
    size_t sectorEnd = input.find('\'', sectorStart);
    w.sector = input.substr(sectorStart, sectorEnd - sectorStart);
    // Base salary
    size_t baseSalaryStart = input.find("base_salary=", sectorEnd) + 12;
    size_t baseSalaryEnd = input.find(',', baseSalaryStart);
    w.base_salary = std::stod(input.substr(baseSalaryStart, baseSalaryEnd - baseSalaryStart));
    // Extra hours
    size_t extraHoursStart = input.find("extra_hours=", baseSalaryEnd) + 12;
    size_t extraHoursEnd = input.find(',', extraHoursStart);
    w.extra_hours = std::stoi(input.substr(extraHoursStart, extraHoursEnd - extraHoursStart));
    // Extra hour value
    size_t extraHourValStart = input.find("extra_hour_val=", extraHoursEnd) + 15;
    size_t extraHourValEnd = input.find('}', extraHourValStart);
    w.extra_hour_val = std::stod(input.substr(extraHourValStart, extraHourValEnd - extraHourValStart));
    return is;
}

