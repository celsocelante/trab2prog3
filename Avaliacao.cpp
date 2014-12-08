#include "Avaliacao.h"


	Revisor* Avaliacao::getRevisor() const{
		return revisor;
	}

	double Avaliacao::getSomaNotas() const{
		return somaNotas;
	}

	void Avaliacao::atribuirNota(double o, double c, double a){
		originalidade = o;
		conteudo = c;
		apresentacao = a;
		somaNotas = o+c+a;
	}
