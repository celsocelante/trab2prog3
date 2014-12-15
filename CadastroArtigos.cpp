#include "CadastroArtigos.h"

CadastroArtigos::CadastroArtigos(const char* entrada, Revista* revista){

  string cell, linha;
  string codigo;
  int codigo_int;

  string titulo;
  string autores;

  int autor_int;

  string contato;
  int contato_int;

  ifstream inf(entrada);

  getline(inf, linha);

  while (getline(inf, linha)) {

    stringstream lineStream(linha);

    getline(lineStream,codigo,';');
    // Converte o string lido para inteiro
    codigo_int = atoi(codigo.c_str());

    getline(lineStream,titulo,';');

    getline(lineStream,autores,';');

    getline(lineStream,contato,';');

    // Constrói o objeto Artigo
    Artigo* artigo = new Artigo(codigo_int,titulo);
    // Submete artigo à edição da revista
    revista->getEdicao()->submeterArtigo(artigo);

    // Cria o stream para o texto da inconsistência e o transforma em string
    ostringstream texto_inconsistencia_stream;
    string texto_inconsistencia;


    // Se artigo possuir mais de um autor, vincula cada um desses autores ao artigo
    istringstream ss(autores);
    while(getline(ss,cell,',')){
     int autor_int = atoi(cell.c_str());
     Colaborador* c = revista->buscaColaborador(autor_int);

     if(c == NULL || !(dynamic_cast<Autor*>(c) != 0)){ // Checa se é instancia de autor
      // Trata a inconsistencia #6: autor não corresponde a um autor no cadastro de pessoas

      texto_inconsistencia_stream << "O código " << autor_int << " associado ao artigo " << "\"" << titulo << "\"" << " não corresponde a um autor cadastrado.";
      // Converte o texto para string
      texto_inconsistencia = texto_inconsistencia_stream.str();

      // Constrói inconsistência e adiciona ao conjunto
      Inconsistencia* i = new Inconsistencia(texto_inconsistencia,6);
      revista->adicionaInconsistencia(i);
     }
     else{
        Autor* autor = dynamic_cast<Autor*>(c); // Typecast de Colaborador para Autor
        artigo->vinculaAutor(autor);
        artigo->setContato(autor);
     }

   }

   if(autores.length()!=4){//Há mais de um autor
      contato_int = atoi(contato.c_str());
      Colaborador* c = revista->buscaColaborador(contato_int);
      if(c == NULL || !(dynamic_cast<Autor*>(c) != 0)){
        texto_inconsistencia_stream.str("");
        // Trata a inconsistência #6: autor não corresponde a um autor no cadastro de pessoas
        texto_inconsistencia_stream << "O código " << contato_int << " associado ao artigo " << "\"" << titulo << "\"" << " não corresponde a um autor cadastrado.";
        // Converte o texto para string
        texto_inconsistencia = texto_inconsistencia_stream.str();

        // Constrói inconsistência e adiciona ao conjunto
        Inconsistencia* i = new Inconsistencia(texto_inconsistencia,6);
        revista->adicionaInconsistencia(i);
      }
      else{
        Autor* contato_ref = dynamic_cast<Autor*>(c); // Typecast de Colaborador para Autor
        if(artigo->contemAutor(contato_ref)){
          // Seta o autor como contato
          artigo->setContato(contato_ref);
        } else {
          texto_inconsistencia_stream.str("");
          // Trata a inconsistência #7: código de contato não está entre os autores do artigo
          texto_inconsistencia_stream << "O autor " << "\"" << contato_ref->getNome() << "\"" << " informado como autor de contato não corresponde a um dos autores do artigo" << "\"" << titulo << "\".";
          // Converte o texto para string
          texto_inconsistencia = texto_inconsistencia_stream.str();

          // Constrói inconsistência e adiciona ao conjunto
          Inconsistencia* i = new Inconsistencia(texto_inconsistencia,7);
          revista->adicionaInconsistencia(i);
        }


      }
   }
 }


}
