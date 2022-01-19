// Freq. 2 - 2017.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Contratado.h"
#include "Quadro.h"
#include <iostream>

#define N 50

int main()
{
    // 7.
    Empregado* V[N];
    for (int i = 0; i < N; i++)
    {
        //
        if (1) // Quadro
        {
            V[i] = new Quadro;
        }
        else { // Contratado
            V[i] = new Contratado;
        }
        V[i]->ReadK();
    }
    // 8.
    for (auto& E : V)
    {
        cout << "Ordenado de" << E->getNome() 
            << " : " << E->Calculo_Ordenado_Dia() << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
