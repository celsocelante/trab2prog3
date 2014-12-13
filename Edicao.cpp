  #include "Edicao.h"
    void Edicao::submeterArtigo(Artigo* artigo){
        submetidos.insert(artigo);
    }

    Artigo* Edicao::buscaArtigo(int codigo){
        set<Artigo*>::iterator it;

        for(it = submetidos.begin(); it != submetidos.end(); it++){
            Artigo* a = *it;
            if (a->getCodigo() == codigo)
              return a;
        }
        return NULL;
    }

    Tema& Edicao::getTema() const{
        return *tema;
    }

    int Edicao::getNumero() const{
        return numero;
    }

    int Edicao::getVolume() const{
        return volume;
    }

    string Edicao::getData() const{
        return mesAno;
    }

    Colaborador* Edicao::getEditorChefe(){
        return editorChefe;
    }

    set<Artigo*>* Edicao::getArtigos(){
        return &submetidos;
    }
