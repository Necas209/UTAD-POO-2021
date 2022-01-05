// Resolu��o do Ex. 6

#include "GestorFunc.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    //Operario O("Z�", Data(25, 12, 2003), "Rua de Cima", 7, "Recursos Humanos", 665, 12, true);
    //cout << "Ordenado do " << O.GetNome() << " : " << O.CalculaOrdenado() << endl;

    vector<Funcionario*> V;
    
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "\t1 - Leitura do ficheiro" << endl;
        cout << "\t2 - Ordenados Funcion�rios" << endl;
        cout << "\t3 - Pesquisar Funcion�rio (por N.�)" << endl;
        cout << "\t4 - Alterar Ordenado de um funcion�rio (por N.�)" << endl;
        cout << "\t5 - Adicionar Funcion�rio" << endl;
        cout << "\t6 - Apresentar Oper�rios que trabalham por turno" << endl;
        cout << "\t7 - Eliminar Funcion�rio (por N.�)" << endl;
        cout << "\t8 - Guardar Administrativos" << endl;
        cout << "\t9 - Guardar Oper�rios" << endl;
        cout << "\t0 - Sair" << endl;
        
        int opcao = 0;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            LerFuncionarios(V);
            break;
        case 2:
            CalcularOrdenados(V);
            break;
        case 3:
            PesquisarFuncionario(V);
            break;
        case 4:
            AlterarOrdenado(V);
            break;
        case 5:
            AdicionarFuncionario(V);
            break;
        case 6:
            ApresentarTurnos(V);
            break;
        case 7:
            EliminarFuncionario(V);
            break;
        case 8:
            GuardarAdministrativos(V);
            break;
        case 9:
            GuardarOperarios(V);
            break;
        case 0:
            LibertarVetor(V);
            exit(0);
            break;
        default:
            cout << "Op��o inv�lida." << endl;
        }
        system("pause");
        system("cls");
    }
}
