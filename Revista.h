#ifndef REVISTA_H
#define REVISTA_H

#include "Edicao.h"
#include "Inconsistencia.h"

class Revista {
private:
    string nome;
    Edicao* edicao;
    set<Tema*> temas;
    set<Colaborador*,ClbComp> colaboradores;
    set<Inconsistencia*,IncComp> inconsistencias;

    Revista() {}

public:
  //Construtor
  Revista(string n){
    nome = n;
  }

  void adicionaTema(Tema* tema);

  void adicionaColaborador(Colaborador* colaborador);

  void adicionaInconsistencia(Inconsistencia* inconsistencia);

  Colaborador* buscaColaborador(int codigo);

  Colaborador* buscaColaborador(string nome);

  Tema* buscaTema(string titulo);

  void setEdicao(Edicao* e);

  Edicao* getEdicao();

  set<Colaborador*,ClbComp>* getColaboradores();

  set<Inconsistencia*,IncComp>* getInconsistencias();

  int getRevisoresEnvolvidos();

  double getArtigosRevisados();
};


template <class charT, charT sep>
class punct_facet: public std::numpunct<charT> {
protected:
    charT do_decimal_point() const { return sep; }
};


#endif /* REVISTA_H */
