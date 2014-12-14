#include "RelatorioRevisores.h"


void RelatorioRevisores::escreveRelatorio(){

  Edicao* edicao = revista->getEdicao();
  ofstream relatorio;

  relatorio.open("relat-revisores.csv");
  relatorio.imbue(locale(""));


  // Registra o relatório de revisores de acordo com as especificações

  relatorio << "Revisor;Qtd. artigos revisados;Média das notas atribuídas";

  set<Colaborador*,ClbComp>::iterator it;

  for(it = revista->getColaboradores()->begin(); it != revista->getColaboradores()->end(); it++){
      Colaborador* colaborador = *it;

      if(dynamic_cast<Revisor*>(colaborador)){
          Revisor* revisor = dynamic_cast<Revisor*>(colaborador);
          if(revisor->participouDaEdicao()){
            relatorio << endl;
            relatorio << revisor->getNome() << ";" << revisor->getQuantidadeArtigos() << ";";
            relatorio << std::fixed << std::setprecision(2) << revisor->getMediaNotasAtribuidas();

          }
      }
  }
  relatorio.close();
}
