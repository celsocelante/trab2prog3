#ifndef INTERPRETADORDEARGUMENTOS_H
#define INTERPRETADORDEARGUMENTOS_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string.h>

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