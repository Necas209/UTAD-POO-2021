#include "Empregado.h"

int Empregado::Calcula_horasDeTrabalho()
{
    Relogio trab = DeEntrada - DeSaida;
    return trab.getHoras();
}

ostream& operator<<(ostream& os, const Empregado& E)
{
    // TODO: insert return statement here
}
