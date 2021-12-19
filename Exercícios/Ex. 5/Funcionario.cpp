#include "Funcionario.h"

Funcionario::Funcionario()
	:num_Func(0), setor("")
{
	ord_base = 0;
	h_extra = 0;
	p_hora_extra = 0;
}

Funcionario::Funcionario(string nome, Data dataN, string morada, int num_Func, string setor, float ord_base, int h_extra, float p_hora_extra)
	:Pessoa(nome, dataN, morada), num_Func(num_Func), setor(setor)
{
	this->ord_base = ord_base;
	this->h_extra = h_extra;
	this->p_hora_extra = p_hora_extra;
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
