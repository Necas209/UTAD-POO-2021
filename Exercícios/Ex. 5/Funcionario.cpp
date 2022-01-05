#include "Funcionario.h"

Funcionario::Funcionario()
	:num_Func(0), setor(""), ord_base(0.0f), h_extra(0.0f), p_hora_extra(0.0f)
{
}

Funcionario::Funcionario(string nome, Data dataN, string morada
	, int num_Func, string setor, float ord_base, int h_extra, float p_hora_extra)
	:Pessoa(nome, dataN, morada)
	, num_Func(num_Func), setor(setor), ord_base(ord_base), h_extra(h_extra), p_hora_extra(p_hora_extra)
{
}

Funcionario::~Funcionario()
{
}

void Funcionario::Show(void)
{
	Pessoa::Show();
	cout << "Número: " << num_Func << endl;
	cout << "Setor: " << setor << endl;
	cout << "Ordenado base: " << ord_base << endl;
	cout << "N.º horas extra: " << h_extra << endl;
}

void Funcionario::ReadK(void)
{
	Pessoa::ReadK();
	
	cout << "Número: ";
	cin >> num_Func;
	cin.ignore();
	
	cout << "Setor: ";
	getline(cin, setor);
	
	cout << "Ordenado base: ";
	cin >> ord_base;
	cin.ignore();

	cout << "N.º horas extra: ";
	cin >> h_extra;
	cin.ignore();
}

void Funcionario::ReadFile(ifstream& ifs)
{
	Pessoa::ReadFile(ifs);

	ifs >> num_Func;
	ifs.ignore(); // ignorar ';'

	getline(ifs, setor, ';');

	ifs >> ord_base;
	ifs.ignore(); // ignorar ';'

	ifs >> h_extra;
	ifs.ignore(); // ignorar ';'
}

void Funcionario::SaveFile(ofstream& ofs)
{
	Pessoa::SaveFile(ofs);
	ofs << num_Func << ';';
	ofs << setor << ';';
	ofs << ord_base << ';';
	ofs << h_extra << ';';
}

ostream& operator<<(ostream& os, const Funcionario& F)
{
	os << (Pessoa&)F;
	os << "Setor: " << F.setor << endl;
	os << "Número: " << F.num_Func << endl;
	os << "Ordenado base: " << F.ord_base << endl;
	os << "N.º horas extra: " << F.h_extra << endl;
	return os;
}

istream& operator>>(istream& is, Funcionario& F)
{
	is >> (Pessoa&)F;

	cout << "Setor: ";
	getline(is, F.setor);

	cout << "Número: ";
	is >> F.num_Func;
	is.ignore();

	cout << "Ordenado base: ";
	is >> F.ord_base;
	is.ignore();

	cout << "N.º horas extra: ";
	is >> F.h_extra;
	is.ignore();

	return is;
}
