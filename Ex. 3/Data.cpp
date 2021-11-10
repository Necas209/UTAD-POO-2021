#include "Data.h"

Data::Data()
{
	time_t now = time(0); // instante atual
	tm* ltm = localtime(&now); // tm -> estrutura que representa data/hora do calendário
	dia = ltm->tm_mday; // tm_mday = dia do mês
	mes = 1 + ltm->tm_mon; // tm_mon = n.º de meses desde Jan.
	ano = 1900 + ltm->tm_year; // tm_year = n.º de anos desde 1900
}

Data::Data(int dia, int mes, int ano)
	:dia(dia), mes(mes), ano(ano)
{
}

Data::~Data()
{
}

void Data::Show(void)
{
	cout << "Data: " << dia << delim << mes << delim << ano << endl;
}

void Data::Update(int dia, int mes, int ano)
{
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

bool Data::Igual(Data D)
{
	return (dia == D.dia && mes == D.mes && ano == D.ano);
}

void Data::ReadFile(ifstream& ifs)
{
	char delim;
	ifs >> dia >> delim >> mes >> delim >> ano;
}

void Data::SaveFile(ofstream& ofs)
{
	ofs << dia << delim << mes << delim << ano;
}

bool Data::operator==(const Data& D)
{
	return (dia == D.dia && mes == D.mes && ano == D.ano);
}

bool Data::operator!=(const Data& D)
{
	return !(*this == D);
}

bool Data::operator<(const Data& D)
{
	if (ano < D.ano)
		return true;
	else if (ano == D.ano && mes < D.mes)
		return true;
	else if (ano == D.ano && mes == D.mes && dia < D.dia)
		return true;
	return false;
}

bool Data::operator>(const Data& D)
{
	if (ano > D.ano)
		return true;
	else if (ano == D.ano && mes > D.mes)
		return true;
	else if (ano == D.ano && mes == D.mes && dia > D.dia)
		return true;
	return false;
}

bool Data::operator<=(const Data& D)
{
	return !(*this > D);
}

bool Data::operator>=(const Data& D)
{
	return !(*this < D);
}

ostream& operator<<(ostream& os, const Data& D)
{
	os << D.dia << Data::delim << D.mes << Data::delim << D.ano;
	return os;
}

istream& operator>>(istream& is, Data& D)
{
	char delim;
	is >> D.dia >> delim >> D.mes >> delim >> D.ano;
	return is;
}
