#include "Operario.h"

Operario::Operario()
{
	SetP_Hora_Extra(8.0f);
	f_turno = false;
}

Operario::Operario(string nome, Data dataN, string morada
	, int num_Func, string setor, float ord_base, int h_extra
	, bool f_turno)
	:Funcionario(nome, dataN, morada, num_Func, setor, ord_base, h_extra, 8.0f)
{
	this->f_turno = f_turno;
}

Operario::~Operario()
{
}

float Operario::CalculaOrdenado()
{
	float ord_final = 0.0f;
	ord_final = GetOrd_Base() + GetH_Extra() * GetP_Hora_Extra();
	if (f_turno)
	{
		ord_final += (float)(0.25 * GetOrd_Base());
	}
	return ord_final;
}

void Operario::Show(void)
{
	Funcionario::Show();
	if (f_turno)
		cout << "Faz turno? Sim" << endl;
	else
		cout << "Faz turno? Não" << endl;

	// Operador ternário de comparação ?:
	//cout << "Faz turno?" << (f_turno ? "Sim" : "Não") << endl;
}

void Operario::ReadK(void)
{
	Funcionario::ReadK();
	
	char opcao;
	cout << "Faz turno? (Y/N)";
	cin >> opcao;
	cin.ignore();

	switch (opcao)
	{
	case 'Y':
		f_turno = true;
		break;
	case 'N':
		f_turno = false;
		break;
	}
}

void Operario::ReadFile(ifstream& ifs)
{
	Funcionario::ReadFile(ifs);
	string str;
	getline(ifs, str, ';');
	if (str == "sim")
		f_turno = true;
	else
		f_turno = false;
}

void Operario::SaveFile(ofstream& ofs)
{
	Funcionario::SaveFile(ofs);
	if (f_turno == true)
		ofs << "sim;";
	else
		ofs << "nao;";
	// ?:
	// a ? b : c
	// ofs << (f_turno ? "sim" : "nao") << ';';
}
