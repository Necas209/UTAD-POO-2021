#include <iostream>
#include <clocale>
#include "Gestor_Func.h"

using namespace std;

// Ex. 8.3
int main(int argc, char* argv[])
{
	ofstream ofs;
	ifstream ifs;
	Gestor_Func gestor;
	setlocale(LC_ALL, "pt-PT");
	// a)
	ifs.open("Funcionarios.txt");
	if (ifs.is_open())
	{
		gestor.ReadFile(ifs);
		ifs.close();
		// b)
		gestor.ShowFunc();
		// c)
		gestor.AddFunc(new Operario("Zeca Estacionancio", Data(1, 1, 1985), "Rua A n.º 9"
			, 25050, "Pintura", 1100, 15, false));
		gestor.AddFunc(new Administrativo("Adrusila Lopes", Data(6, 6, 1996), "Rua E n.º 6"
			, 25051, "Recursos Humanos", 900, 0));
		// d)
		gestor.RemoveFunc("Joca Gaio");
		// e)
		ofs.open("Funcionarios.txt");
		if (ofs.is_open())
		{
			gestor.SaveFile(ofs);
			ofs.close();
		}
		else 
		{
			cout << "Erro na abertura do ficheiro." << endl;
			exit(-1);
		}
	}
	else
	{
		cout << "Erro na leitura do ficheiro." << endl;
		exit(-1);
	}
	return 0;
}