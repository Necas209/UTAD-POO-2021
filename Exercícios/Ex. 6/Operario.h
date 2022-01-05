#include "../Ex. 5/Funcionario.h"
#pragma once

class Operario :
    public Funcionario
{
private:
    bool f_turno;
public:
    Operario();
    Operario(string nome, Data dataN, string morada
        , int num_Func, string setor
        , float ord_base, int h_extra, bool f_turno);
    virtual ~Operario();

    // Métodos de Acesso
    void SetF_Turno(bool f) { f_turno = f; }
    bool GetF_turno(void) const { return f_turno; }

    virtual void Show(void);
    virtual void ReadK(void);
    virtual void ReadFile(ifstream& ifs);
    virtual void SaveFile(ofstream& ofs);
    virtual float CalculaOrdenado();
};

