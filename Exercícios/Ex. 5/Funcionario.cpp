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
	is.ignore();
	cout << "Setor: ";
	getline(is, F.setor);
	cout << "Numero: ";
	is >> F.num_Func;
	return is;
}
