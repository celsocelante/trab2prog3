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
	vector<const char*> entradas;
    
	private:
		InterpretadorDeArgumentos(){}

	public:
		InterpretadorDeArgumentos(const char* args[], int argc);
		vector<const char*> retornaEntradas();
};

#endif