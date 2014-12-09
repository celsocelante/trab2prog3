#include "Revista.h"

  void Revista::adicionaTema(Tema& tema){
    temas.insert(&tema);
  }

  void Revista::adicionaColaborador(Colaborador& colaborador){
      colaboradores.insert(&colaborador);
  }

  //Método para adicionar inconsistencia

  Colaborador* Revista::buscaColaborador(int codigo){
    set<Colaborador*>::iterator it;

    for(it = colaboradores.begin(); it!= colaboradores.end(); it++{
        if (codigo == it->getCodigo())
          return it;
    }
    return NULL;
  }

  Colaborador* Revista::buscaColaborador(string nome){
    set<Colaborador*>::iterator it;

    for(it = colaboradores.begin(); it!= colaboradores.end(); it++{
        if (nome == it->getNome())
          return it;
    }
    return NULL;
  }

  Tema* Revista::buscaTema(string titulo){
    set<Tema*>::iterator it;

    for(it = temas.begin(); it!=temas.end(); it++) {
        if (titulo == it->getTitulo())
          return it;
    }
    return NULL;

  }

  void Revista::setEdicao(Edicao& e){
    edicao = &e;
  }

  Edicao& Revista::getEdicao() const{
    return *edicao;
  }

  set<Colaborador*>& Revista::getColaboradores() const{
      return colaboradores;
  }

  //Metodo para retornar inconsistencias

  int Revista::getRevisoresEnvolvidos();

  double Revista::getArtigosRevisados();
