	#include "Revisor.h"
	#include "Artigo.h"
		void Revisor::vinculaInstituicao(string instituicao){
			instituicoes.insert(instituicao);
		}

		void Revisor::vinculaRevisao(Artigo& artigo){
			revisoes.insert(&artigo);
		}

		bool Revisor::participuDaEdicao(){
			return !revisoes.empty();
		}

		set<Artigo*>& Revisor::getRevisoes(){
			return revisoes;
		}

		int Revisor::getQuantidadeArtigos(){
			return revisoes.size();
		}
