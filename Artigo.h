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
	set<Avaliacao*> revisoes;
	Autor* contato;

	Artigo(){}
public:

	Artigo(int cdg, string ttl){
		codigo = cdg;
		titulo = ttl;
	}

	void vinculaAutor(Autor* autor);

	void setContato(Autor* autor);

	void adicionaAvaliacao(Avaliacao& avaliacao);

	int getCodigo() const;

	string getTitulo();

	string getContato();

	bool contemAutor(Autor* autor);

	bool quantidadeRevisoes();

	set<Avaliacao*> getRevisao();

	int getQuantidadeRevisoes();

	double getMedia() const;

	bool operator< (const Artigo* a) const;
};

#endif /* ARTIGO_H */
