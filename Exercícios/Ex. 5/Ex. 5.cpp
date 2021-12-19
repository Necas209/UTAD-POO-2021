
#include "Funcionario.h"
#include <iostream>
#include <string>       // std::getline
#include <clocale>      // setlocale

using namespace std;

void SortByDate(Funcionario* v);

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
    cout << "Funcionário 3:" << endl;
    cin >> F3;
    cout << "Funcionário 4:" << endl;
    cin >> F4;
    // 5.11
    ofstream ofs;
    string filename;
    cout << "Nome do ficheiro: ";
    getline(cin, filename);
    ofs.open(filename);
    if (ofs.is_open())
    {
        F1.SaveFile(ofs);
        ofs << endl;
        F2.SaveFile(ofs);
        ofs << endl;
        F3.SaveFile(ofs);
        ofs << endl;
        F4.SaveFile(ofs);
        ofs << endl;
        ofs.close();
    }
    else
    {
        cout << "ERRO na abertura/criação do ficheiro " << filename << endl;
        exit(1);
    }
    // 5.13
    Funcionario v[4];
    ifstream ifs;
    
    ifs.open(filename);
    if (ifs.is_open())
    {
        for (int i = 0; i < 4; i++)
        {
            v[i].ReadFile(ifs);
            ifs >> ws; // ler o '\n'
        }
        ifs.close();
    }
    else
    {
        cout << "ERRO na abertura do ficheiro " << filename << endl;
        exit(1);
    }
    
    // 5.14
    SortByDate(v);
    //for (auto& f : v) 
    //{ 
    //    f.Show(); 
    //}
    for (int i = 0; i < 4; i++) 
    { 
        v[i].Show(); 
    }
}

void SortByDate(Funcionario* v)
{
    Funcionario temp;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++)
        {
            if (v[j].GetDataN() < v[i].GetDataN()) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}