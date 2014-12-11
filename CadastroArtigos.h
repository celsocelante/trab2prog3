#ifndef CADASTROARTIGOS_H
#define CADASTROARTIGOS_H

#include "Revista.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class CadastroArtigos {
    
    private:
        string cell, linha;
        string codigo;
        string titulo;
        string autores_temp;
        string contato;
	Revista* revista;
	
        CadastroArtigos(){}

    public:
	CadastroArtigos(string entrada, Revista* r);
        
};

#endif