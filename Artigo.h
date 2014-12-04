#ifndef ARTIGO_H
#define ARTIGO_H

#include "Autor.h"


class Artigo
{

private: 
	string titulo;
	int codigo;
	set<Autor*> autores;
	//Implementar conjunto de avaliacoes (revisoes)
	
	Autor* contato;

	Artigo(){} 

public: 

	Artigo(int cdg, string ttl){
		codigo = cdg;
		titulo = ttl;
	}

	void vinculaAutor(Autor& autor){
		autores.insert(&autor);
	}

	//Escrever método para adicionar avaliacao
/*
	bool contemAutor(Autor autor){
		return autores.find(autor) != autores.end();
	}*/

	/*bool quantidadeRevisoes(){
		return revisoes.size()==3;
	}*/

	//Getters e setters

	int getCodigo(){
		return codigo;
	}

	string getTitulo(){
		return titulo;
	}

	string getContato(){
		return contato->getNome();
	}	

	//Escrever método para retornar revisões,
	//retornar média das avaliações nas revisões
	//retornar quantidade de revisoes

	void setContato(Autor* autor){
		contato = autor;
	}

};

#endif /* ARTIGO_H */
