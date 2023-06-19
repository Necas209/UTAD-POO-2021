#include "date.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    date date1, date2(1, 1, 1970), date3;
    cout << "date 3: ";
    cin >> date3;
    cout << "date 1: " << date1 << endl;
    cout << "date 2: " << date2 << endl;
    cout << "date 3: " << date3 << endl;
    ifstream ifs{"../data_input.txt"};
    if (!ifs.is_open()) {
        std::cerr << "Error opening file" << endl;
        exit(1);
    }
    ofstream ofs{"../data_output.txt"};
    if (!ofs.is_open()) {
        std::cerr << "Error opening file" << endl;
        exit(1);
    }
    date date4;
    ifs >> date4;
    ofs << date4;
    return 0;
}