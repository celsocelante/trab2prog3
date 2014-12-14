#ifndef EDICAO_H
#define EDICAO_H

#include "Revisor.h"
#include "Tema.h"
#include "Artigo.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

class Edicao {
private:
  int numero;
  int volume;
  string mesAno;
  Tema* tema;
  set<Artigo*> submetidos;
  set<Artigo*,ArtComp> submetidosOrdenados;
  Colaborador* editorChefe;


  Edicao() {}
public:
  //Construtor
  Edicao(int v, int num, string data, Tema* t, Colaborador* c);

  void submeterArtigo(Artigo* artigo);

  Artigo* buscaArtigo(int codigo);

  void ordenaSubmetidos();

  Tema* getTema();

  int getNumero() const;

  int getVolume() const;

  string getData() const;

  Colaborador* getEditorChefe();

  set<Artigo*>* getArtigos();

  set<Artigo*,ArtComp>* getArtigosOrdenados();

};

#endif /* EDICAO_H */
