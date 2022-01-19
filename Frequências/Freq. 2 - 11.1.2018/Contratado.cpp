#include "Contratado.h"

Contratado::Contratado()
{
	N_dias = 0;
}

Contratado::Contratado(string nome, 
	Relogio ent, Relogio saida, 
	int dias)
	:Empregado(nome, ent, saida)
{
	N_dias = dias;
}

Contratado::~Contratado()
{
}

float Contratado::Calculo_Ordenado_Dia()
{
	float ord = 0.0f;
	int horas = Calcula_horasDeTrabalho();
	ord = 6.5 * horas;
	return ord;
}
