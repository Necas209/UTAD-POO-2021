// Resolução do Ex. 6

#include <iostream>
#include "Operario.h"
#include "Administrativo.h"

using namespace std;

int main()
{
    Operario O("Zé", Data(25, 12, 2003), "Rua de Cima", 7, "Recursos Humanos", 665, 12, true);
    setlocale(LC_ALL, "");
    cout << "Ordenado do " << O.GetNome() << " : " << O.CalculaOrdenado() << endl;
}