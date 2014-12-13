#ifndef CADASTROEDICAO_H
#define CADASTROEDICAO_H

#include "Revista.h"
#include "Edicao.h"
#include "Tema.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class CadastroEdicao {
private:
  	CadastroEdicao(){}

public:
	CadastroEdicao(const char* entrada, Revista* revista);
        
};

#endif