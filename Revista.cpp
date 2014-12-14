  #include "Revista.h"
    void Revista::adicionaTema(Tema* tema){
      temas.insert(tema);
    }

    void Revista::adicionaColaborador(Colaborador* colaborador){
        colaboradores.insert(colaborador);
    }

    void Revista::adicionaInconsistencia(Inconsistencia* inconsistencia){
      inconsistencias.insert(inconsistencia);
    }

    Colaborador* Revista::buscaColaborador(int codigo){
      set<Colaborador*>::iterator it;

      for(it = colaboradores.begin(); it!= colaboradores.end(); it++){
          Colaborador* c = *it;
          if (codigo == c->getCodigo())
            return c;
      }
      return NULL;
    }

    Colaborador* Revista::buscaColaborador(string nome){
      set<Colaborador*>::iterator it;

      for(it = colaboradores.begin(); it!= colaboradores.end(); it++){
          Colaborador* c = *it;
          if (nome == c->getNome())
            return c;
      }
      return NULL;
    }

    Tema* Revista::buscaTema(string titulo){
      set<Tema*>::iterator it;

      for(it = temas.begin(); it!=temas.end(); it++) {
          Tema* t = *it;
          if (titulo == t->getTitulo())
            return t;
      }
      return NULL;

    }

    void Revista::setEdicao(Edicao* e){
      edicao = e;
    }

    Edicao* Revista::getEdicao(){
      return edicao;
    }

    set<Colaborador*,ClbComp>* Revista::getColaboradores(){
        return &colaboradores;
    }

    set<Inconsistencia*,IncComp>* Revista::getInconsistencias(){
      return &inconsistencias;
    }

    int Revista::getRevisoresEnvolvidos(){
      set<Colaborador*>::iterator it;
      int qnt=0;
      for(it = colaboradores.begin(); it != colaboradores.end(); it++){
        Colaborador* c = *it;
        if(dynamic_cast<Revisor*>(c) != 0){
          Revisor* r = dynamic_cast<Revisor*>(c);
          if(r->participouDaEdicao())
            qnt++;
        }
      }
      return qnt;
    }

    double Revista::getArtigosRevisados(){
      set<Colaborador*>::iterator it;
      int qnt=0;
      for(it = colaboradores.begin(); it != colaboradores.end(); it++){
        Colaborador* c = *it;
        if(dynamic_cast<Revisor*>(c) != 0){
          Revisor* r = dynamic_cast<Revisor*>(c);
          if(r->participouDaEdicao())
            qnt+=r->getQuantidadeArtigos();
        }
      }
      return qnt;
    }
