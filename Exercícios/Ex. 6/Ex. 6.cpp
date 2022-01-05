// Resolução do Ex. 6

#include <iostream>
#include "Operario.h"
#include "Administrativo.h"
#include <vector>

using namespace std;

void LerFuncionarios(Funcionario**& V);

int main()
{
    //Operario O("Zé", Data(25, 12, 2003), "Rua de Cima", 7, "Recursos Humanos", 665, 12, true);
    setlocale(LC_ALL, "");
    //cout << "Ordenado do " << O.GetNome() << " : " << O.CalculaOrdenado() << endl;
    Funcionario** V = nullptr;

    while (true)
    {
        int opcao;
        cout << "Menu:" << endl;
        cout << "\t1 - Leitura do ficheiro" << endl;
        cout << "\t2 - Ordenados Funcionários" << endl;
        cout << "\t3 - Pesquisar Funcionário" << endl;
        cout << "\t4 - Alterar Ordenado de um funcionário" << endl;
        cout << "\t5 - Adicionar Funcionário" << endl;
        cout << "\t6 - Apresentar Operários que trabalham por turno" << endl;
        cout << "\t7 - Eliminar Funcionário" << endl;
        cout << "\t8 - Guardar Administrativos" << endl;
        cout << "\t9 - Guardar Operários" << endl;
        cout << "\t 0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            LerFuncionarios(V);
            for (int i=0; i<3; i++)
            {
                V[i]->Show();
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
        }
    }
}

void LerFuncionarios(Funcionario**& V)
{
    ifstream ifs;
    ifs.open("Funcionarios.txt");

    if (!ifs.is_open())
    {
        cout << "Erro na abertura do ficheiro." << endl;
        exit(1);
    }

    int n = 0;
    while (ifs.eof() == false)
    {
        if (ifs.get() == '\n')
            ++n;
    }

    ifs.clear();
    ifs.seekg(0, ios::beg);

    V = new Funcionario * [n];
    
    string tipo;

    for (int i = 0; i < n; i++)
    {
        getline(ifs, tipo, ':');

        if (tipo == "O")
        {
            V[i] = new Operario();
        }
        else if (tipo == "A")
        {
            V[i] = new Administrativo();
        }

        V[i]->ReadFile(ifs);
        ifs >> ws;
    }
}