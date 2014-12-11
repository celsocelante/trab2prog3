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

#endif /* INCONSISTENCIA_H */