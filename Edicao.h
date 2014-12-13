#ifndef EDICAO_H
#define EDICAO_H

#include "Revisor.h"
#include "Tema.h"
#include "Artigo.h"

class Edicao {
private:
  int numero;
  int volume;
  //data
  string mesAno;
  Tema* tema;
  set<Artigo*> submetidos;
  Colaborador* editorChefe;

  Edicao() {}
public:
  //Construtor
  Edicao(int v, int num, string data, Tema* t, Colaborador* c){

    volume = v;
    numero = num;
    //tratar data
    tema = t;
    editorChefe = c;
  }

  void submeterArtigo(Artigo* artigo);

  Artigo* buscaArtigo(int codigo);

  Tema& getTema() const;

  int getNumero() const;

  int getVolume() const;

  string getData() const;

  Colaborador* getEditorChefe();

  set<Artigo*>* getArtigos();

};

#endif /* EDICAO_H */
