#include "Edicao.h"


  void Edicao::submeterArtigo(Artigo& artigo){
      submetidos.insert(&artigo);
  }

  Artigo* Edicao::buscaArtigo(int codigo){
      set<Artigo*>::iterator it;

      for(it = submetidos.begin(); it != submetidos.end(); it++){
          if (it->getCodigo() == codigo)
            return it;
      }
      return NULL;
  }

  Tema& Edicao::getTema() const{
      return *tema;
  }

  int Edicao::getNumero(){
      return numero;
  }

  int Edicao::getVolume(){
      return volume;
  }

  string Edicao::getData(){
      return mesAno;
  }

  Colaborador& Edicao::getEditorChefe() const{
      return *editorChefe;
  }

  set<Artigo*>& Edicao::getArtigos(){
      return submetidos;
  }
