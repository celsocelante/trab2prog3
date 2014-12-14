#ifndef ARTIGO_H
#define ARTIGO_H

#include "Avaliacao.h"
#include "Autor.h"

class Artigo
{
private:
	string titulo;
	int codigo;
	set<Autor*> autores;
	set<Avaliacao*,AvaComp> revisoes;
	Autor* contato;

	Artigo(){}
public:

	Artigo(int cdg, string ttl){
		codigo = cdg;
		titulo = ttl;
	}

	void vinculaAutor(Autor* autor);

	void setContato(Autor* autor);

	void adicionaAvaliacao(Avaliacao* avaliacao);

	int getCodigo() const;

	string getTitulo() const;

	string getContato() const;

	bool contemAutor(Autor* autor);

	bool quantidadeRevisoes();

	set<Avaliacao*,AvaComp>* getRevisao();

	int getQuantidadeRevisoes() const;

	double getMedia() const;

	int getQuantidadeAutores();
};



struct ArtComp {
	bool operator()(const Artigo* lhs, const Artigo* rhs) const{
				return lhs->getMedia() >= rhs->getMedia();
	}
};

#endif /* ARTIGO_H */
