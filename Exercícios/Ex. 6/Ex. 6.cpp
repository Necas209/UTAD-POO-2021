// Resolução do Ex. 6

#include "GestorFunc.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    //Operario O("Zé", Data(25, 12, 2003), "Rua de Cima", 7, "Recursos Humanos", 665, 12, true);
    //cout << "Ordenado do " << O.GetNome() << " : " << O.CalculaOrdenado() << endl;

    vector<Funcionario*> V;
    
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "\t1 - Leitura do ficheiro" << endl;
        cout << "\t2 - Ordenados Funcionários" << endl;
        cout << "\t3 - Pesquisar Funcionário (por N.º)" << endl;
        cout << "\t4 - Alterar Ordenado de um funcionário (por N.º)" << endl;
        cout << "\t5 - Adicionar Funcionário" << endl;
        cout << "\t6 - Apresentar Operários que trabalham por turno" << endl;
        cout << "\t7 - Eliminar Funcionário (por N.º)" << endl;
        cout << "\t8 - Guardar Administrativos" << endl;
        cout << "\t9 - Guardar Operários" << endl;
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
            cout << "Opção inválida." << endl;
        }
        system("pause");
        system("cls");
    }
}
