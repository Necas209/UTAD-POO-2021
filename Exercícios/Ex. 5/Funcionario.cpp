#include "Funcionario.h"

Funcionario::Funcionario()
	:num_Func(0), setor("")
{
}

Funcionario::Funcionario(string nome, Data dataN, string morada, int num_Func, string setor)
	:Pessoa(nome, dataN, morada), num_Func(num_Func), setor(setor)
{
}

Funcionario::~Funcionario()
{
}

void Funcionario::Show(void)
{
	Pessoa::Show();
	cout << "Numero: " << num_Func << endl;
	cout << "Setor: " << setor << endl;
}

void Funcionario::ReadFile(ifstream& ifs)
{
	Pessoa::ReadFile(ifs);
	ifs >> num_Func;
	ifs.ignore(); // ignorar ';'
	getline(ifs, setor, ';');
}

void Funcionario::SaveFile(ofstream& ofs)
{
	Pessoa::SaveFile(ofs);
	ofs << num_Func << ';';
	ofs << setor << ';';
}

ostream& operator<<(ostream& os, const Funcionario& F)
{
	os << (Pessoa&)F;
	os << "Setor: " << F.setor << endl;
	os << "Numero: " << F.num_Func << endl;
	return os;
}

istream& operator>>(istream& is, Funcionario& F)
{
	is >> (Pessoa&)F;
	cout << "Setor: ";
	getline(is, F.setor);
	cout << "Numero: ";
	is >> F.num_Func;
	is.ignore();
	return is;
}
