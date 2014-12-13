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
    
private:
	InterpretadorDeArgumentos(){}
	vector<char*> entradas;

public:
	InterpretadorDeArgumentos(const char* args[], int argc);
	vector<char*> retornaEntradas();
};

#endif