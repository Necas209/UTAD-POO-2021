#include "Pessoa.h"
// biblioteca que contém a função setlocale
#include <clocale> 

using namespace std;

int main()
{
    Pessoa p1("Jonas Culatra", Data(20, 9, 1987), "Rua da direita no. 2")
         , p2("Joni Rato", Data(4, 2, 1990), "Rua da esquerda no. 3"), p3, p4;
    // permite caracteres especiais (acentos, cedilhas)
    setlocale(LC_ALL, "");
    
    // c)
    p1.Show();
    p2.Show();
    
    // d)
    string morada;
    cout << "Morada P2: ";
    getline(cin, morada);
    p2.SetMorada(morada);
    
    // e)
    Data data;
    cout << "Data P2: ";
    cin >> data;
    p2.SetDataN(data);
    // f)
    cin.ignore();
    p3.ReadK();
    
    // g)
    cout << "Pessoa 4: " << endl;
    cin >> p4;
    cout << "Pessoa 4: " << p4 << endl;
    
    // h)
    if (p3 == p4)
        cout << "As pessoas 3 e 4 são iguais." << endl;
    
    // i)
    p1.MaisNovo(p2);
    
    // j)
    string filename;
    ofstream ofs;
    cout << "Nome do ficheiro: ";
    getline(cin, filename);
    ofs.open(filename);
    if (!ofs.is_open())
    {
        cout << "ERRO na abertura do ficheiro." << endl;
        exit(1);
    }
    p1.SaveFile(ofs);
    ofs << endl;
    p2.SaveFile(ofs);
    ofs << endl;
    p3.SaveFile(ofs);
    ofs << endl;
    p4.SaveFile(ofs);
    ofs.close();
    
    // l)
    int i = 0;
    Pessoa vec[4];
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        cout << "ERRO na abertura do ficheiro." << endl;
        exit(1);
    }
    while (!ifs.eof())
    {
        vec[i].ReadFile(ifs);
        ifs >> ws;
        i++;
    }
    ifs.close();
    
    // m)
    
    for (i = 0; i < 4; i++)
    {
        if (vec[i].GetDataN().GetAno() < 1990)
        {
            vec[i].Show();
        }
    }
}