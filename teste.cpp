	#include <iostream>
	#include <fstream>
	#include "Colaborador.h"
	#include "Autor.h"
	#include "Revisor.h"
	using namespace std;

int main(){

	Colaborador c("Ares","sdasda","das","sadas",3);
	Autor a("Marcos","xxx","en","senha",10);
	Revisor r("Prado","xxx","en","senha",2);

	Colaborador* ptr = &a;
	Colaborador* ptr2 = &r;

	
	ofstream saida;
	saida.open("saida.txt");
	saida << a.getNome() << endl;

	saida.close();
	return 0;
}