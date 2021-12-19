#include "Operario.h"

Operario::Operario()
{
	SetP_Hora_Extra(8);
	f_turno = false;
}

Operario::Operario(string nome, Data dataN, string morada
	, int num_Func, string setor, float ord_base, int h_extra
	, bool f_turno)
	:Funcionario(nome, dataN, morada, num_Func, setor, ord_base, h_extra, 8)
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
		ord_final += 0.25 * GetOrd_Base();
	}
	return ord_final;
}
