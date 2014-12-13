#include "InterpretadorDeArgumentos.h"
<<<<<<< HEAD
InterpretadorDeArgumentos::InterpretadorDeArgumentos(char* args[], int argc){
	// Inicializa com zeros
	vector<char*> entradas;
=======
InterpretadorDeArgumentos::InterpretadorDeArgumentos(const char* args[], int argc){
>>>>>>> 2eeb0a0e8190cd789a91b91eeb766dea14d44395

    if(argc != 11){
      // Imprime mensagem de erro se a quantidade ideal de parâmetros não estiver sendo respeitada
      //cout << "Erro de I/O" << endl;
      exit(1);
    }

    // Verifica cada elemento do vetor à procura de flags + argumentos
    for(int i = 1; i <= argc; i++){
      if(strcmp("-e",args[i]) == 0)
        entradas.push_back(args[i+1]);
      if(strcmp("-t",args[i]) == 0)
        entradas.push_back(args[i+1]);
      if(strcmp("-p",args[i]) == 0)
        entradas.push_back(args[i+1]);
      if(strcmp("-a",args[i]) == 0)
        entradas.push_back(args[i+1]);
      if(strcmp("-r",args[i]) == 0)
        entradas.push_back(args[i+1]);
    }
    // Verifica se algum dos parametros não foi preenchido
    if(entradas[0] == 0|| entradas[1] == 0 || entradas[2] == 0 || entradas[3] == 0 || entradas[4] == 0){
      cout << "Erro de I/O" << endl;
      exit(1);
    }
}

// Método para retornar o que foi processado pelo classe

vector<const char*> InterpretadorDeArgumentos::retornaEntradas(){

	return entradas;
}