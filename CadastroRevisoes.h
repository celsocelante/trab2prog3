#ifndef CADASTROREVISOES_H
#define CADASTROREVISOES_H

#include "Revista.h"
#include "Avaliacao.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

class CadastroRevisoes {
private:
    CadastroRevisoes(){}
public:
	CadastroRevisoes(const char* entrada, Revista* revista);
};

#endif
