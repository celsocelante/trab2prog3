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
#include "CadastroRevisoes.h"
#include "InterpretadorDeArgumentos.h"

int main(int argc, char** argv){
	cout << 1 << endl;

	Revista revista = Revista("Engesoft");
		cout << 1 << endl;

	InterpretadorDeArgumentos argumentos = InterpretadorDeArgumentos(argv,argc);

	cout << 1 << endl;

	vector<char*> entradas = argumentos.retornaEntradas();

	CadastroPessoas pessoas = CadastroPessoas(entradas[2], &revista);
    CadastroTemas temas = CadastroTemas(entradas[1], &revista);
    CadastroEdicao edicao = CadastroEdicao(entradas[0], &revista);
    CadastroArtigos artigos = CadastroArtigos(entradas[3], &revista);
    CadastroRevisoes revisoes = CadastroRevisoes(entradas[4], &revista);

	return 0;

} 
