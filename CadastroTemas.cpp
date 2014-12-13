#include "CadastroTemas.h"

CadastroTemas::CadastroTemas(const char* entrada, Revista* revista){
	string linha;
  string cell;

	string codigo;
  string nome;
  string revisores;
	int codigo_int;

	ifstream inf(entrada);

 	getline(inf, linha);

	while (getline(inf, linha)) {  

    stringstream lineStream(linha);

    getline(lineStream,codigo,';');
    // Converte o string lido para inteiro
    codigo_int = atoi(codigo.c_str());

    getline(lineStream,nome,';');
    getline(lineStream,revisores,';');

    // Constrói o objeto Tema
    Tema* tema = new Tema(nome,codigo_int);
    // Submete tema à edição da revista
    revista->adicionaTema(tema);

    // Cria o stream para o texto da inconsistência e o transforma em string
    ostringstream texto_inconsistencia_stream;
    string texto_inconsistencia;

    istringstream ss(revisores);
    while(getline(ss,cell,',')){
     //Vincula cada revisor do tema lido do arquivo
     int autor_int = atoi(cell.c_str());
     Colaborador* c = revista->buscaColaborador(autor_int);

     if(c == NULL || dynamic_cast<Autor*>(c) != 0){ 
      //Trata inconsistencia #3: nao ha revisor correspondente a este codigo no cadastro de pessoas
      texto_inconsistencia_stream << "O código " << codigo_int << " associado ao tema " << "\"" << nome << "\"" << " não corresponde a um revisor cadastrado.";
      // Converte o texto para string
      texto_inconsistencia = texto_inconsistencia_stream.str();

      // Constrói inconsistência e adiciona ao conjunto
      Inconsistencia* i = new Inconsistencia(texto_inconsistencia,3);
      revista->adicionaInconsistencia(i);
     } else {
        Revisor* revisor = dynamic_cast<Revisor*>(c); // Typecast de Colaborador para Autor
        tema->vinculaRevisor(revisor);
     }
    }
    if(tema->getQuantidadeRevisores() < 3){
      //Trata inconsistencia #4: tema com menos de 3 revisores
      texto_inconsistencia_stream << "O tema " << "\'"<< nome << "\'" << " possui apenas " << tema->getQuantidadeRevisores() << ". São necessários no minimo 3.";
      // Converte o texto para string
      texto_inconsistencia = texto_inconsistencia_stream.str();
      //Adiciona inconsistencia ao conjunto de inconsistencias da revista
      Inconsistencia* i = new Inconsistencia(texto_inconsistencia,4);
      revista->adicionaInconsistencia(i);
    }
  }
}