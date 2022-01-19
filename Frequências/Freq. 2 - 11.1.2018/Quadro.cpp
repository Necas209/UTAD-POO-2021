#include "Quadro.h"

Quadro::Quadro()
{
	N_func = 0;
}

Quadro::Quadro(string nome
	, Relogio entrada, Relogio saida
	, int N)
	:Empregado(nome, entrada, saida)
{
	N_func = N;
}

Quadro::~Quadro()
{
}

float Quadro::Calculo_Ordenado_Dia()
{
	float ord = 0.0f;
	int horas;
	horas = Calcula_horasDeTrabalho();
	if (horas <= 8)
	{
		ord = 5 * horas;
	}
	else
	{
		ord = 40 + (horas - 8) * 5 * 1.25;
	}
	return ord;
}

void Quadro::Show()
{
	Empregado::Show();
}

ostream& operator<<(ostream& os, const Quadro& Q)
{
	os << (Empregado&)Q;
	// lógica
	return os;
}
