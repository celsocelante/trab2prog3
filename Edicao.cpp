  #include "Edicao.h"

    Edicao::Edicao(int v, int num, string data, Tema* t, Colaborador* c){

      volume = v;
      numero = num;
      tema = t;
      editorChefe = c;

      //Trata a data
      string cell;
      stringstream lineStream(data);
      getline(lineStream,cell,'/');
      getline(lineStream,cell,'/');

      int mes_int = atoi(cell.c_str());
      string meses[12] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};

      ostringstream data_stream;
      data_stream << meses[mes_int-1];

      getline(lineStream,cell,'/');

      data_stream << " de " << cell;

      mesAno = data_stream.str();
    }

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

    void Edicao::ordenaSubmetidos(){
      set<Artigo*>::iterator it;
      for(it=submetidos.begin();it!=submetidos.end();it++){
          Artigo* a = *it;
          submetidosOrdenados.insert(a);
      }
    }

    Tema* Edicao::getTema(){
        return tema;
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


    set<Artigo*,ArtComp>* Edicao::getArtigosOrdenados(){
        return &submetidosOrdenados;
    }
