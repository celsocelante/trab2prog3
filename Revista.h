#ifndef REVISTA_H
#define REVISTA_H

#include "Edicao.h"
#include "Inconsistencia.h"

class Revista {
private:
    string nome;
    Edicao* edicao;
    set<Tema*> temas;
    set<Colaborador*> colaboradores;
    set<Inconsistencia*> inconsistencias;

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

  void setEdicao(Edicao& e);

  Edicao& getEdicao() const;

  set<Colaborador*> getColaboradores() const;

  set<Inconsistencia*> getInconsistencias() const;

  int getRevisoresEnvolvidos();

  double getArtigosRevisados();
};

#endif /* REVISTA_H */
