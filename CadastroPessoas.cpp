#include "CadastroPessoas.h"

CadastroPessoas::CadastroPessoas(const char* entrada, Revista* revista){
	string linha;

	string codigo;
	int codigo_int;

	string nome;
	string email;
	string senha;
	string instituicao;
	string endereco;
	string tipo;

	ifstream inf(entrada);

 	getline(inf, linha);

  	while (getline(inf, linha)) {

  		stringstream lineStream(linha);
    	getline(lineStream,codigo,';');
    	codigo_int = atoi(codigo.c_str()); // Converte o código para inteiro

    	getline(lineStream,nome,';');
    	getline(lineStream,email,';');
    	getline(lineStream,senha,';');
    	getline(lineStream,instituicao,';');
    	getline(lineStream,endereco,';');
    	getline(lineStream,tipo,';');

    	if(tipo == "A"){
    		Autor* autor = new Autor(nome,email,endereco,senha,codigo_int);
            autor->vinculaInstituicao(instituicao);
            revista->adicionaColaborador(autor);
    	} else if(tipo == "R"){
    		Revisor* revisor = new Revisor(nome,email,endereco,senha,codigo_int);
    		revisor->vinculaInstituicao(instituicao);
    		revista->adicionaColaborador(revisor);
    	} else {
    		// Trata a inconsistencia #5: Colaborador cadastrado não é de um tipo válido
    		Colaborador* colaborador = new Colaborador(nome,email,endereco,senha,codigo_int);
    		revista->adicionaColaborador(colaborador);

    		ostringstream texto_inconsistencia_stream;
    		string texto_inconsistencia;

    		texto_inconsistencia_stream << "O tipo de " << "\"" << colaborador->getNome() + "\"" << " não é um tipo válido.";
      		// Converte o texto para string
      		texto_inconsistencia = texto_inconsistencia_stream.str();

      		// Constrói inconsistência e adiciona ao conjunto de inconsistencias em revista
      		Inconsistencia* i = new Inconsistencia(texto_inconsistencia,5);
            revista->adicionaInconsistencia(i);
    	}
  	}


}