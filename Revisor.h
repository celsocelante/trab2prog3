#ifndef REVISOR_H
#define REVISOR_H

#include <set>
#include "Colaborador.h"

class Artigo; //forward declaration

class Revisor : public Colaborador
{

private: 

	set<string> instituicoes;
	set<Artigo*> revisoes;

public:
	//Construtor
	Revisor(string n, string e, string end, string se, int cdg):Colaborador(n,e,end,se,cdg) { };

	void vinculaInstituicao(string instituicao);

	void vinculaRevisao(Artigo& artigo);

	bool participuDaEdicao();

	set<Artigo*>& getRevisoes();

	int getQuantidadeArtigos();

	};
	
	
#endif /* REVISOR_H */ 