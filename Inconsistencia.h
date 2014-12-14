#ifndef INCONSISTENCIA_H
#define INCONSISTENCIA_H
#include <string>
#include <iostream>
using namespace std;

class Inconsistencia {
private:
	string mensagem;
	int tipo;

	Inconsistencia() {}
public:
	Inconsistencia(string m, int t) {
		mensagem = m;
		tipo = t;
	}

	int getTipo() const;

	string getMensagem() const;



};


struct IncComp {
	bool operator()(const Inconsistencia* lhs, const Inconsistencia* rhs) const{
				return lhs->getTipo() <= rhs->getTipo();
	}
};


#endif /* INCONSISTENCIA_H */
