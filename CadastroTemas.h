#ifndef CADASTROTEMAS_H
#define CADASTROTEMAS_H

#include "Revista.h"
#include "Tema.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class CadastroTemas {
private:
  	CadastroTemas(){}

public:
	CadastroTemas(const char* entrada, Revista* revista);
        
};

#endif