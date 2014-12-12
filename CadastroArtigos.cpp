#include "CadastroArtigos.h"

CadastroArtigos::CadastroArtigos(char* entrada, Revista& revista){

  ifstream inf(entrada);

  /*if (!inf) {
  cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
  exit(1);
  }*/


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
    (revista.getEdicao()).submeterArtigo(artigo);

    if(contato.empty()){
  // Se o campo contato estiver vazio, quer dizer quer o artigo só possui um autor e ele é o contato
      contato = autores;
    } else {
      contato_int = atoi(contato.c_str());

      istringstream ss(autores);
      cout << "Autores: " << endl;
      while(getline(ss,cell,',')){
        // Para cada autor lido do artigo
       int autor_int = atoi(cell.c_str());
       Colaborador* c = revista.buscaColaborador(autor_int);

       if(c == NULL){ // Checar se é instância de autor (ainda não consegui achar fazer isso)
          // Cria o stream para o texto da inconsistência e o transforma em string
          ostringstream texto_inconsistencia_stream;
          texto_inconsistencia_stream << "O código " << codigo_int << " associado ao artigo " << "\"" << titulo << "\"" << " não corresponde a um autor cadastrado.";
          // Converte o texto para string
          string texto_inconsistencia = texto_inconsistencia_stream.str();

          // Constrói inconsistência e adiciona ao conjunto
          Inconsistencia i = Inconsistencia(texto_inconsistencia,6);
          revista.adicionaInconsistencia(i);
       } else {
          Autor* autor = dynamic_cast<Autor*>(c); // INCOMPATIBILIDADE DE PONTEIROS E/OU REFERÊNCIAS!!!1111!!!111!!1
          artigo.vinculaAutor(autor);
       }

       cout << autor_int << endl;
  // Adiciona os autores à lista de autores
     }
   }

  /* CONSTRUIR OBJETO AQUI */
   cout << "Contato: " << contato_int << endl;


   cout << "---" << endl;
 }
}
