#ifndef CADASTROPESSOAS_H
#define CADASTROPESSOAS_H

#include "Revista.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class CadastroPessoas {
    
private:
	Revista* revista;
	CadastroPessoas(){}

public:
	CadastroPessoas(const char* entrada, Revista* revista);    
};

#endif