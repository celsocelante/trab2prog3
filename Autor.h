#include "Colaborador.h"
#include <set>
class Autor: public Colaborador
{

private:
	set<string> instituicoes;
 
public:
	//Construtor
	Autor(string n, string e, string end, string se, int cdg):Colaborador(n,e,end,se,cdg) { };

	void vinculaInstituicao(string instituicao){
		instituicoes.insert(instituicao);
	}


	};