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
#include "RelatorioRevisoes.h"
#include "RelatorioRevisores.h"

int main(int argc, char** argv){

	Revista revista = Revista("Engesoft");

	// Interpreta as entradas por "argv"
	InterpretadorDeArgumentos argumentos = InterpretadorDeArgumentos(argv,argc);
	vector<char*> entradas = argumentos.retornaEntradas();

	// Constrói os objetos que lêem os arquivos
	CadastroPessoas pessoas = CadastroPessoas(entradas[2], &revista);
    CadastroTemas temas = CadastroTemas(entradas[1], &revista);
    CadastroEdicao edicao = CadastroEdicao(entradas[0], &revista);
    CadastroArtigos artigos = CadastroArtigos(entradas[3], &revista);
    CadastroRevisoes revisoes = CadastroRevisoes(entradas[4], &revista);

    RelatorioResumo relat_resumo = RelatorioResumo(&revista);
    relat_resumo.escreveRelatorio();

    // Só escreve relatórios se inconsistências não forem detectadas 
	if(revista.getInconsistencias()->empty()){
		RelatorioRevisoes relat_revisoes = RelatorioRevisoes(&revista);
		relat_revisoes.escreveRelatorio();

		RelatorioRevisores relat_revisores = RelatorioRevisores(&revista);
		relat_revisores.escreveRelatorio();
	}

	return 0;
}
