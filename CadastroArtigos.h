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
	int codigo_int;
	
        string titulo;
	
        string autores;
	int autor_int;
	
        string contato;
	int contato_int;
	
	Revista* revista;
	
        CadastroArtigos(){}

    public:
	CadastroArtigos(char* entrada, Revista& revista);
        
};

#endif