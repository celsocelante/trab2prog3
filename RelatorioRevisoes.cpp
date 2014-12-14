#include "RelatorioRevisoes.h"


void RelatorioRevisoes::escreveRelatorio(){

  Edicao* edicao = revista->getEdicao();
  ofstream relatorio;

  relatorio.open("relat-revisoes.csv");
  relatorio.imbue(locale(""));

  relatorio << "Artigo;Autor de contato;Média das avaliações;Revisor 1; Revisor 2; Revisor 3";

  set<Artigo*,ArtComp>::iterator it;
	// Registra o relatório de revisões de acordo com as especificações
  for(it=edicao->getArtigosOrdenados()->begin();it!=edicao->getArtigosOrdenados()->end();it++){
    Artigo* artigo = *it;

    relatorio << endl;
    relatorio << artigo->getTitulo() << ";" << artigo->getContato() << ";" << std::fixed << std::setprecision(2) << artigo->getMedia();

    set<Avaliacao*,AvaComp>::iterator it2;
    for(it2=artigo->getRevisao()->begin(); it2 != artigo->getRevisao()->end(); it2++){
      Avaliacao* avaliacao = *it2;
      relatorio  << ";" << avaliacao->getRevisor()->getNome();
    }

  }
  relatorio.close();
}
