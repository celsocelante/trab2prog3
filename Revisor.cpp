#include "Revisor.h"
#include "Artigo.h"

void Revisor::vinculaInstituicao(string instituicao){
	instituicoes.insert(instituicao);
}

void Revisor::vinculaRevisao(Artigo* artigo){
	revisoes.insert(artigo);
}

bool Revisor::participouDaEdicao(){
	return !revisoes.empty();
}

set<Artigo*>* Revisor::getRevisoes(){
	return &revisoes;
}

int Revisor::getQuantidadeArtigos() const{
	return revisoes.size();
}

double Revisor::getMediaNotasAtribuidas(){
	double media = 0;

	set<Artigo*>::iterator it;
	for(it = revisoes.begin(); it != revisoes.end(); it++){
		Artigo* artigo = *it;

		set<Avaliacao*,AvaComp>::iterator it2;
		for(it2 = artigo->getRevisao()->begin(); it2 != artigo->getRevisao()->end(); it2++){
				Avaliacao* avaliacao = *it2;
				if(nome == avaliacao->getRevisor()->getNome())
						media = media + avaliacao->getSomaNotas();
		}
	}

	return media/getQuantidadeArtigos();
}
