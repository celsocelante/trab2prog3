#include "InterpretadorDeArgumentos.h"

InterpretadorDeArgumentos::InterpretadorDeArgumentos(char* args[], int argc){

    // Inicializa o vetor com entradas nulas
    for(int i = 0; i< 5; i++)
      entradas.push_back(NULL);


    if(argc != 11){
      // Imprime mensagem de erro se a quantidade ideal de parâmetros não estiver sendo respeitada
      cout << "Erro de I/O (1)" << endl;
      exit(1);
    }

    // Verifica cada elemento do vetor à procura de flags + argumentos
    for(int i = 1; i < argc; i++){
      if(strcmp("-e",args[i]) == 0)
        entradas[0] = args[i+1];
      if(strcmp("-t",args[i]) == 0)
        entradas[1] = args[i+1];
      if(strcmp("-p",args[i]) == 0)
        entradas[2] = args[i+1];
      if(strcmp("-a",args[i]) == 0)
        entradas[3] = args[i+1];
      if(strcmp("-r",args[i]) == 0)
        entradas[4] = args[i+1];
    }


    // Verifica se algum dos parametros não foi preenchido
    if(entradas[0] == NULL || entradas[1] == NULL || entradas[2] == NULL || entradas[3] == NULL || entradas[4] == NULL){
      cout << "Erro de I/O (2)" << endl;
      exit(1);
    }
}

// Método para retornar o que foi processado pelo classe


vector<char*> InterpretadorDeArgumentos::retornaEntradas(){

  return entradas;
}
