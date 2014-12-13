	#include "Artigo.h"
		void Artigo::vinculaAutor(Autor* autor){
			autores.insert(autor);
		}

		bool Artigo::contemAutor(Autor* autor){
			return autores.find(autor) != autores.end();
		}

		void Artigo::adicionaAvaliacao(Avaliacao& avaliacao){
			revisoes.insert(&avaliacao);
		}

		bool Artigo::quantidadeRevisoes(){
			return revisoes.size()==3;
		}

		//Getters e setters
		void Artigo::setContato(Autor* autor){
			contato = autor;
		}

		int Artigo::getCodigo() const{
			return codigo;
		}

		string Artigo::getTitulo(){
			return titulo;
		}

		string Artigo::getContato(){
			if (contato == NULL)
				return "";

			else return contato->getNome();
		}

		set<Avaliacao*> Artigo::getRevisao(){
			return revisoes;
		}

		int Artigo::getQuantidadeRevisoes(){
			return revisoes.size();
		}

		double Artigo::getMedia() const{
			double media=0;
			set<Avaliacao*>::iterator it;

			for(it = revisoes.begin(); it!=revisoes.end();it++){
				Avaliacao* a = *it;
				media+=a->getSomaNotas();
			}
			return media/3;
		}


		bool Artigo::operator< (const Artigo* a) const{
			return getMedia() > a->getMedia();
		}
