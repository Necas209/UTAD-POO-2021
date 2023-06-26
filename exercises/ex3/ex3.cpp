#include "date.h"
#include <iostream>
#include <fstream>

int main() {
    date date1, date2(1, 1, 1970), date3;
    std::cout << "date 3: ";
    std::cin >> date3;
    std::cout << "date 1: " << date1 << std::endl;
    std::cout << "date 2: " << date2 << std::endl;
    std::cout << "date 3: " << date3 << std::endl;
    std::ifstream ifs{"../data_input.txt"};
    if (!ifs.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
    std::ofstream ofs{"../data_output.txt"};
    if (!ofs.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(1);
    }
    date date4;
    ifs >> date4;
    ofs << date4;
    return 0;
}