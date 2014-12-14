#ifndef TEMA_H
#define TEMA_H

#include "Revisor.h"

class Tema {
private:
    string titulo;
    int codigo;
    set<Revisor*> revisores;

    Tema() {}

public:
    //virtual ~Tema() { }
    Tema(string t, int cdg){
        titulo = t;
        codigo = cdg;
    }

    string getTitulo() const;

    void vinculaRevisor(Revisor* revisor);

    int getQuantidadeRevisores();

    bool contemRevisor(Revisor* revisor);
};

#endif /* TEMA_H */
