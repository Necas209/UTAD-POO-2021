
#include "Funcionario.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    // 5.4
    Funcionario F1("Joca Gaio", Data(20, 9, 1987), "Rua da direita n 2", 25023, "Pintura")
            , F2("Ana Rola", Data(4, 2, 1990), "Rua da esquerda n 3", 25024, "Comercial");
    // Permitir caracteres especiais
    setlocale(LC_ALL, "");
    // 5.5
    cout << "Funcionário 1:" << endl;
    F1.Show();
    cout << "Funcionário 2:" << endl;
    F2.Show();
    // 5.6
    F1.SetMorada("Rua do meio n 4");
    F1.SetSetor("Ferragem");
    // 5.7
    Data tmp;
    tmp = F2.GetDataN();
    tmp.SetDia(23);
    F2.SetDataN(tmp);
    // 5.9
    Funcionario F3, F4;
    cout << "Funcionário 3:";
    cin >> F3;
    cout << "Funcionário 4:";
    cin >> F4;
    // 5.11

}