#include "RelatorioResumo.h"

// Registra o relatório de resumo de acordo com as especificações
void RelatorioResumo::escreveRelatorio(){

	Edicao* edicao = revista->getEdicao();

	ofstream resumo;
	resumo.open("relat-resumo.txt");
	resumo.imbue(locale(""));

	//Cabeçalho do Resumo
	resumo << "EngeSoft, num. " << edicao->getNumero() << ", volume " << edicao->getVolume() << " - " << edicao->getData() << endl;
	//Tratar data
	if(edicao->getTema() != NULL)
		resumo << "Tema: " << edicao->getTema()->getTitulo() << endl;

	resumo << "Editor-chefe: ";
	if(edicao->getEditorChefe() != NULL)
		resumo << edicao->getEditorChefe()->getNome();

	resumo << endl << endl;
	resumo << "Consistência dos dados:" << endl;

	if(!revista->getInconsistencias()->empty()){
		// Imprime no arquivo de saída todas as inconsistências armazenadas no objeto revista
		set<Inconsistencia*>::iterator it;
		for(it = revista->getInconsistencias()->begin(); it != revista->getInconsistencias()->end();it++){
			Inconsistencia* i = *it;
			resumo << endl;
			resumo << "Erro " << i->getTipo() << ": " << i->getMensagem();
		}
	}
	else{
		// Caso não haja qualquer inconsistência, uma mensagem informando a situação é inserida no arquivo
		resumo << "- Nenhum problema encontrado." << endl << endl;
		// Insere no arquivo a quantidade de artigos submetidos, revisoes capacitados e envolvidos

		resumo << "Artigos submetidos: " << revista->getEdicao()->getArtigos()->size() << endl;
		resumo << "Revisores capacitados: " << revista->getEdicao()->getTema()->getQuantidadeRevisores() << endl;
		resumo << "Revisores envolvidos: " << revista->getRevisoresEnvolvidos() << endl;

		double media = revista->getArtigosRevisados()/revista->getRevisoresEnvolvidos();
		resumo << "Média artigos/revisor: " << std::fixed << std::setprecision(2) << media;
	}

	resumo.close();

}
