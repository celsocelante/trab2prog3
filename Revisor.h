#include "Colaborador.h"
#include "Artigo.h"
#include <set>

class Revisor : public Colaborador
{

private:

	set<string> instituicoes;
	set<Artigo> revisoes;

public:
	//Construtor
	Revisor(string n, string e, string end, string se, int cdg):Colaborador(n,e,end,se,cdg) { };

	void vinculaInstituicao(string instituicao){
		instituicoes.insert(instituicao);
	}

	void vinculaRevisao(Artigo& artigo){
		revisoes.insert(artigo);
	}

	bool participuDaEdicao(){
		return !revisoes.empty();
	}

	set<artigo>& getRevisoes(){
		return revisoes;
	}

	int getQuantidadeArtigos(){
		return revisoes.size();
	}

	};