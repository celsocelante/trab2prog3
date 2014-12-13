#ifndef CADASTROARTIGOS_H
#define CADASTROARTIGOS_H

#include "Revista.h"
#include "Colaborador.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class CadastroArtigos {
    
    //private:
	
    
    CadastroArtigos(){}

    public:
	CadastroArtigos(const char* entrada, Revista* revista);
        
};

#endif