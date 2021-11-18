#include "Conta.h"

Conta::Conta()
{
	saldo = 0;
}

Conta::Conta(Titular _titular, float _saldo, Data _data)
{
	titular = _titular;
	saldo = _saldo;
	data_abertura = _data;
}

Conta::~Conta()
{
}

void Conta::Deposito(int valor)
{
	if (valor >= 0)
		saldo += valor; // saldo = saldo + valor;
}

void Conta::Levantamento(int valor)
{
	if (saldo >= valor)
		saldo -= valor;
	else
		saldo = 0; // ou não fazer nada
}

void Conta::SaveFile(int valor)
{
	ofstream ofs;
	ofs.open("movimentosConta.txt");
	if (ofs.is_open())
	{
		if (valor >= 0)
			Deposito(valor);
		else Levantamento(valor);
		ofs << data_abertura << ';' << titular.GetNumero() << ';' << valor << ';' << endl;
		ofs.close();
	}
}

bool Conta::operator==(Conta C)
{
	return (this->titular.GetNome() == C.titular.GetNome()
		&& titular.GetMorada() == C.titular.GetMorada() && titular.GetNumero() == C.titular.GetNumero());
}

Conta Conta::operator+(Conta C)
{
	Conta temp;
	if (*this == C) // Ou, titular == C.titular
	{
		temp.titular = titular;
		temp.saldo = saldo + C.saldo;
		if (data_abertura < C.data_abertura)
		{
			temp.data_abertura = data_abertura;
		}
		else
		{
			temp.data_abertura = C.data_abertura;
		}
		return temp;
	}
	return *this;
}

ostream& operator<<(ostream& os, Conta C)
{
	C.titular.Show();
	os << "Cliente desde: " << C.data_abertura << endl;
	os << endl << "Saldo Atual: " << C.saldo << "€" << endl;
}