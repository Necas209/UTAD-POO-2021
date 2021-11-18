#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	int dia, mes, ano;
	Data d1, d2(1, 1, 1970), d3, d4;
	ifstream ifs;
	ofstream ofs;
	// Apresentação das datas d1 e d2 usando o método Show
	d1.Show();
	d2.Show();
	// Atualização da data d1 a partir do teclado e usando setters
	cout << "Data 1:" << endl;
	cout << "Dia: ";
	cin >> dia;
	cout << "Mes: ";
	cin >> mes;
	cout << "Ano: ";
	cin >> ano;
	d1.SetDia(dia);
	d1.SetMes(mes);
	d1.SetAno(ano);
	// Atualização da data d2 usando o método Update
	d2.Update(18, 10, 2021);
	// Leitura da data d3 a partir do teclado, usando a sobrecarga do operador '>>'
	cout << "Data 3: ";
	cin >> d3;
	// Apresentação das datas, usando a sobrecarga do operador '<<'
	cout << "Data 1: " << d1 << endl;
	cout << "Data 2: " << d2 << endl;
	cout << "Data 3: " << d3 << endl;
	// Leitura e escrita nos ficheiros, usando ReadFile e SaveFile
	ifs.open("data_input.txt");
	if (!ifs.is_open())
	{
		cout << "Erro na abertura do ficheiro." << endl;
		exit(1);
	}
	d4.ReadFile(ifs);
	ifs.close();

	ofs.open("data_output.txt");
	if (!ofs.is_open())
	{
		cout << "Erro na abertura/criacao do ficheiro." << endl;
		exit(1);
	}
	d4.SaveFile(ofs);
	ofs.close();
	return 0;

	//
	cout << d4.GetDia() << d4.GetMes() << d4.GetAno();
	cout << d4 << d1;
}