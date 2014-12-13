#include "CadastroArtigos.h"

CadastroArtigos::CadastroArtigos(char* entrada, Revista& revista){

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
    Artigo artigo = Artigo(codigo_int,titulo);

    // Submete artigo à edição da revista
    revista.getEdicao().submeterArtigo(artigo);

    // Se o campo contato estiver vazio, quer dizer quer o artigo só possui um autor e ele é o contato
    if(contato.empty())
      contato = autores;

    contato_int = atoi(contato.c_str());

    // Busca no conjunto de colaboradores
    Colaborador* c = revista.buscaColaborador(contato_int);

    // Cria o stream para o texto da inconsistência e o transforma em string
    ostringstream texto_inconsistencia_stream;
    string texto_inconsistencia;

    istringstream ss(autores);
    while(getline(ss,cell,',')){
      // Para cada autor lido do artigo
     int autor_int = atoi(cell.c_str());
     c = revista.buscaColaborador(autor_int);

     if(c == NULL || dynamic_cast<Autor*>(c) != 0){ // Checa se é instância de autor
      // Trata a inconsistencia #6: autor não corresponde a um autor no cadastro de pessoas
      texto_inconsistencia_stream << "O código " << codigo_int << " associado ao artigo " << "\"" << titulo << "\"" << " não corresponde a um autor cadastrado.";
      // Converte o texto para string
      texto_inconsistencia = texto_inconsistencia_stream.str();

      // Constrói inconsistência e adiciona ao conjunto
      Inconsistencia i = Inconsistencia(texto_inconsistencia,6);
      revista.adicionaInconsistencia(i);
     } else {
        Autor* autor = dynamic_cast<Autor*>(c); // Typecast de Colaborador para Autor
        artigo.vinculaAutor(autor);
     }

     cout << autor_int << endl;
  // Adiciona os autores à lista de autores
   }

   if(c == NULL || dynamic_cast<Autor*>(c) != 0){
      // Trata a inconsistência #6: autor não corresponde a um autor no cadastro de pessoas
      texto_inconsistencia_stream << "O código " << codigo_int << " associado ao artigo " << "\"" << titulo << "\"" << " não corresponde a um autor cadastrado.";
      // Converte o texto para string
      texto_inconsistencia = texto_inconsistencia_stream.str();

      // Constrói inconsistência e adiciona ao conjunto
      Inconsistencia i = Inconsistencia(texto_inconsistencia,6);
      revista.adicionaInconsistencia(i);
    } else {
      Autor* contato_ref = dynamic_cast<Autor*>(c); // Typecast de Colaborador para Autor
      if(artigo.contemAutor(contato_ref)){
        // Seta o autor como contato
        artigo.setContato(contato_ref);
      } else {
        // Trata a inconsistência #7: código de contato não está entre os autores do artigo
        texto_inconsistencia_stream << "O contato " << contato_ref->getNome() << " informado como autor de contato não corresponde a um dos autores do artigo.";

        // CONSERTAR TEXTO DE INCONSISTÊNCIA!!111

        // Converte o texto para string
        texto_inconsistencia = texto_inconsistencia_stream.str();

        // Constrói inconsistência e adiciona ao conjunto
        Inconsistencia i = Inconsistencia(texto_inconsistencia,7);
        revista.adicionaInconsistencia(i);
      }
    }


 }
}