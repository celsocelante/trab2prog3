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
#include "RelatorioResumo.h"

int main(int argc, char** argv){

	Revista revista = Revista("Engesoft");

	InterpretadorDeArgumentos argumentos = InterpretadorDeArgumentos(argv,argc);
	vector<char*> entradas = argumentos.retornaEntradas();


	CadastroPessoas pessoas = CadastroPessoas(entradas[2], &revista);
    CadastroTemas temas = CadastroTemas(entradas[1], &revista);
    CadastroEdicao edicao = CadastroEdicao(entradas[0], &revista);
    CadastroArtigos artigos = CadastroArtigos(entradas[3], &revista);
    CadastroRevisoes revisoes = CadastroRevisoes(entradas[4], &revista);

    RelatorioResumo resumo = RelatorioResumo(&revista);
    resumo.escreveRelatorio();

	return 0;

} 
