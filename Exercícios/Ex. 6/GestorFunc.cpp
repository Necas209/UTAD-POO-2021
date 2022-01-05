#include "GestorFunc.h"

void LerFuncionarios(vector<Funcionario*>& V)
{
    ifstream ifs;
    ifs.open("Funcionarios.txt");

    if (!ifs.is_open())
    {
        cout << "Erro na abertura do ficheiro \"Funcionarios.txt\"." << endl;
        exit(1);
    }

    string tipo;
    int i = 0;

    while (!ifs.eof())
    {
        getline(ifs, tipo, ':');

        if (tipo == "O")
        {
            V.push_back(new Operario);
        }
        else if (tipo == "A")
        {
            V.push_back(new Administrativo);
        }

        V[i]->ReadFile(ifs);
        ifs >> ws;
        ++i;
    }

    ifs.close();
}

int PesquisarFuncionario(vector<Funcionario*>& V)
{
    int num;
    cout << "N.º Funcionário: ";
    cin >> num;
    cin.ignore();

    for (int i = 0; i < V.size(); i++)
    {
        if (V[i]->GetNum_Func() == num)
        {
            V[i]->Show();
            return i;
        }
    }
    
    cout << "O funcionário pedido não existe." << endl;
    return -1;
}

void CalcularOrdenados(vector<Funcionario*>& V)
{
    for (auto Func : V)
    {
        cout << "Funcionário N.º " << Func->GetNum_Func() << endl;
        cout << "Ordenado: " << Func->CalculaOrdenado() << endl;
    }
}

void AlterarOrdenado(vector<Funcionario*>& V)
{
    int i = PesquisarFuncionario(V);

    if (i != -1)
    {
        float ord;
        cout << "Ordenado base: ";
        cin >> ord;
        cin.ignore();

        if (ord > 0)
        {
            V[i]->SetOrd_Base(ord);
        }
    }
}

void ApresentarTurnos(vector<Funcionario*>& V)
{
    for (auto Func : V)
    {
        Operario* O = dynamic_cast<Operario*>(Func);
        if (O != nullptr)
        {
            if (O->GetF_turno())
            {
                O->Show();
            }
        }
    }
}

void AdicionarFuncionario(vector<Funcionario*>& V)
{
    Funcionario* F;

    cout << "Tipo de funcionário:" << endl;
    cout << "\t1 - Operário" << endl;
    cout << "\t2 - Administrativo" << endl;
    
    int tipo;
    cout << "Opção: ";
    cin >> tipo;
    cin.ignore();

    switch (tipo)
    {
    case 1:
        F = new Operario;
        F->ReadK();
        V.push_back(F);
        break;
    case 2:
        F = new Administrativo;
        F->ReadK();
        V.push_back(F);
        break;
    default:
        cout << "Opção inválida." << endl;
    }
}

void EliminarFuncionario(vector<Funcionario*>& V)
{
    int i = PesquisarFuncionario(V);

    if (i != -1)
    {
        // Eliminar o objeto apontado por V[i]
        delete V[i];
        // Eliminar o apontador V[i] de V
        V.erase(V.begin() + i);
    }
}

void GuardarAdministrativos(vector<Funcionario*>& V)
{
    ofstream ofs;
    ofs.open("Administrativos.txt");

    if (ofs.is_open())
    {
        for (auto F : V)
        {
            Administrativo* A = dynamic_cast<Administrativo*>(F);
            if (A != nullptr)
            {
                A->SaveFile(ofs);
                ofs << endl;
            }
        }
        ofs.close();
    }
    else
    {
        cout << "Erro na abertura do ficheiro \"Administrativos.txt\"." << endl;
    }
}

void GuardarOperarios(vector<Funcionario*>& V)
{
    ofstream ofs;
    ofs.open("Operarios.txt");

    if (ofs.is_open())
    {
        for (auto F : V)
        {
            Operario* O = dynamic_cast<Operario*>(F);
            if (O != nullptr)
            {
                O->SaveFile(ofs);
                ofs << endl;
            }
        }
        ofs.close();
    }
    else
    {
        cout << "Erro na abertura do ficheiro \"Operarios.txt\"." << endl;
    }
}

void LibertarVetor(vector<Funcionario*>& V)
{
    for (auto& F : V)
    {
        delete F;
    }
    V.clear();
}
