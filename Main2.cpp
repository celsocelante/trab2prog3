	#include "Colaborador.h"
	#include "Revisor.h"
	#include "Artigo.h"
	#include "Autor.h"
	#include "Avaliacao.h"
	#include "Revista.h"
	#include <iostream>
	#include "CadastroPessoas.h"
	#include "CadastroTemas.h"
	#include "CadastroEdicao.h"
	#include "CadastroArtigos.h"

	int main(int argc, char* argv[]){

		Autor c("Marcos","xxx","en","senha",10);
		c.vinculaInstituicao("UfES");

		Artigo a(100,"Um artigo");
		a.setContato(&c);
		
		a.vinculaAutor(&c);

		Revisor r("Prado","xxx","en","senha",2);

		
		Avaliacao ac(&r);

		Revista re("Engsoft");
		//re.adicionaColaborador(&r);
		//cout << re.buscaColaborador("Prado")->getCodigo() << endl;
		
		string s = "pessoas.csv";
		const char* arq_pessoas = (s.c_str());

		CadastroPessoas cp(arq_pessoas,&re);
		cout << re.getColaboradores()->size() << endl;


		string tem = "temas.csv";
		const char* arq_temas = tem.c_str();
		CadastroTemas ct(arq_temas,&re);


		string ed= "edicao.txt";
		const char* arq_edicao = ed.c_str();
		CadastroEdicao edc(arq_edicao,&re);	
		cout << re.getEdicao()->getTema()->getTitulo() << endl;


		string art = "artigos.csv";
		const char* arq_artigos = art.c_str();
		CadastroArtigos artg(arq_artigos,&re);

		cout << re.getInconsistencias()->size() << endl;

		return 0;

		} 