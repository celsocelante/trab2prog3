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
      //cout << linha << endl;
    	getline(lineStream,codigo,';');
    	codigo_int = atoi(codigo.c_str()); // Converte o código para inteiro

    	getline(lineStream,nome,';');
    	getline(lineStream,email,';');
    	getline(lineStream,senha,';');
    	getline(lineStream,instituicao,';');
    	getline(lineStream,endereco,';');
    	getline(lineStream,tipo,';');
        cout << nome << endl;

    	if(tipo == "A"){
    		Autor autor = Autor(nome,email,endereco,senha,codigo_int);
        autor.vinculaInstituicao(instituicao);
        revista->adicionaColaborador(&autor);
        
        //Autor autor2 = Autor("marcos","asda","sdweew","sadas",12);
        //revista->adicionaColaborador(&autor2);
        
        //cout << revista->buscaColaborador(12)->getNome() << endl;

    	} else if(tipo == "R"){
    		Revisor revisor = Revisor(nome,email,endereco,senha,codigo_int);
    		revisor.vinculaInstituicao(instituicao);
    		revista->adicionaColaborador(&revisor);
    	} else {
    		// Trata a inconsistencia #5: Colaborador cadastrado não é de um tipo válido
    		Colaborador colaborador = Colaborador(nome,email,endereco,senha,codigo_int);
    		revista->adicionaColaborador(&colaborador);

    		ostringstream texto_inconsistencia_stream;
    		string texto_inconsistencia;

    		texto_inconsistencia_stream << "O tipo de " << "\"" << colaborador.getNome() + "\"" << " não é um tipo válido.";
      		// Converte o texto para string
      		texto_inconsistencia = texto_inconsistencia_stream.str();

      		// Constrói inconsistência e adiciona ao conjunto de inconsistencias em revista
      		Inconsistencia i = Inconsistencia(texto_inconsistencia,5);
          revista->adicionaInconsistencia(&i);
    	}
  	}
    //Autor autor2("marcos","asda","sdweew","sadas",12);
    //revista->adicionaColaborador(&autor2);
    //autor2("prado","asda","sdweew","sadas",32);
    //revista->adicionaColaborador(&autor2);
    cout << revista->getColaboradores().size() << endl;
    cout << revista->buscaColaborador(2017)->getNome() << endl;


}