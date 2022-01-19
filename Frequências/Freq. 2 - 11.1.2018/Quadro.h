#pragma once
#include "Empregado.h"
class Quadro :
    public Empregado
{
private:
    int N_func;
public:
    Quadro();
    Quadro(string nome
        , Relogio entrada, Relogio saida,
        int N);
    virtual ~Quadro();

    void SetNFunc(int N) { N_func = N; }
    int GetNFunc() const { return N_func; }
    
    virtual float Calculo_Ordenado_Dia();
    virtual void Show();
    friend ostream& operator<<(ostream& os, const Quadro& Q);
};

