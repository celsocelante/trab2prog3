#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <string>

using namespace std;

class Colaborador
{
protected:
	string nome;
	string email;
	string endereco;
	string senha;
	int codigo;
private:
	Colaborador(){}
public:
	virtual ~Colaborador() {  }
	//Construtor
	Colaborador(string n, string e, string end, string se, int cdg){
		nome = n;
		email = e;
		endereco = end;
		senha = se;
		codigo = cdg;
	}
	//Getters e setters
	int getCodigo() const;

	string getNome() const;

};


struct ClbComp {
	bool operator()(const Colaborador* lhs, const Colaborador* rhs) const{
				return lhs->getNome() <= rhs->getNome();
	}
};


#endif /* COLABORADOR_H */
