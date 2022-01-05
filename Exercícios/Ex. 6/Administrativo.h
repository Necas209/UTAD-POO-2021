#include "../Ex. 5/Funcionario.h"
#pragma once

class Administrativo :
    public Funcionario
{
public:
    Administrativo();
    Administrativo(string nome, Data dataN, string morada
        , int num_Func, string setor
        , float ord_base, int h_extra);
    virtual ~Administrativo();

    virtual void Show(void);
    virtual void ReadK(void);
    virtual void ReadFile(ifstream& ifs);
    virtual void SaveFile(ofstream& ofs);
    virtual float CalculaOrdenado();
};

