#include "Administrativo.h"

Administrativo::Administrativo()
{
	SetP_Hora_Extra(10);
}

Administrativo::Administrativo(string nome, Data dataN, string morada
	, int num_Func, string setor, float ord_base, int h_extra)
	:Funcionario(nome, dataN, morada, num_Func, setor, ord_base, h_extra, 10)
{
}

Administrativo::~Administrativo()
{
}

float Administrativo::CalculaOrdenado()
{
	float ord_final = 0.0f;
	ord_final = GetOrd_Base() + GetH_Extra() * GetP_Hora_Extra();
	return ord_final;
}
