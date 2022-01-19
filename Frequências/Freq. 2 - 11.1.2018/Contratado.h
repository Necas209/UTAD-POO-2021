#pragma once
#include "Empregado.h"
class Contratado :
    public Empregado
{
private:
    int N_dias;
public:
    Contratado();
    Contratado(string nome,
        Relogio ent, Relogio saida,
        int dias);
    virtual ~Contratado();

    void SetNDias(int dias) { N_dias = dias; }
    int GetNDias() const { return N_dias; }

    virtual float Calculo_Ordenado_Dia();
};

