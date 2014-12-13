#ifndef AVALIACAO_U
#define AVALIACAO_U


#include "Revisor.h"

class Avaliacao{
private:
	double originalidade;
	double conteudo;
	double apresentacao;
	double somaNotas;
	Revisor* revisor;

	Avaliacao(){}
public:
	Avaliacao(Revisor* r){
		revisor = r;
	}

	Revisor* getRevisor() const;

	double getSomaNotas() const;
	
	void atribuirNota(double o, double c, double a);

	
	bool operator< (const Avaliacao* a) const{
		return revisor->getNome() < a->getRevisor()->getNome();
	}
};


#endif /* AVALIACAO_U */ 