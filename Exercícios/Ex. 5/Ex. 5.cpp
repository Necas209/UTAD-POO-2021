
#include "Funcionario.h"
#include <iostream>

using namespace std;

int main()
{
    // 5.4
    Funcionario F1("Joca Gaio", Data(20, 9, 1987), "Rua da direita n 2", 25023, "Pintura"),
        F2("Ana Rola", Data(4, 2, 1990), "Rua da esquerda n 3", 25024, "Comercial");

    // 5.5
    cout << "Funcionario 1:" << endl;
    F1.Show();
    cout << "Funcionario 2:" << endl;
    F2.Show();
}