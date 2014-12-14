#ifndef INTERPRETADORDEARGUMENTOS_H
#define INTERPRETADORDEARGUMENTOS_H

#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <vector>

using namespace std;

class InterpretadorDeArgumentos {

	vector<char*> entradas;

	private:
		InterpretadorDeArgumentos(){}

	public:
		InterpretadorDeArgumentos(char** args, int argc);
		vector<char*> retornaEntradas();

};

#endif
