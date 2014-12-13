#include "InterpretadorDeArgumentos.h"
InterpretadorDeArgumentos::InterpretadorDeArgumentos(const char* args[], int argc){
	// Inicializa com zeros
	vector<char*> entradas;

    if(argc != 10){
      // Imprime mensagem de erro se a quantidade ideal de parâmetros não estiver sendo respeitada
      //cout << "Erro de I/O" << endl;
      exit(1);
    }

    // Verifica cada elemento do vetor à procura de flags + argumentos
    for(int i = 0; i < argc; i++){
      if(strcmp("-e",args[i]) == 0)
        entradas[0].push_back(args[i+1]);
      if(strcmp("-t",args[i]) == 0)
        entradas[1].push_back(args[i+1]);
      if(strcmp("-p",args[i]) == 0)
        entradas[2].push_back(args[i+1]);
      if(strcmp("-a",args[i]) == 0)
        entradas[3].push_back(args[i+1]);
      if(strcmp("-r",args[i]) == 0)
        entradas[4].push_back(args[i+1]);
    }
    // Verifica se algum dos parametros não foi preenchido
    if(entradas[0] == 0|| entradas[1] == 0 || entradas[2] == 0 || entradas[3] == 0 || entradas[4] == 0){
      cout << "Erro de I/O" << endl;
      exit(1);
    }
}

// Método para retornar o que foi processado pelo classe
vector<char*> retornaEntradas(){
	return NULL;
}