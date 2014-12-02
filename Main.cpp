#include <iostream>
#include "Artigo.h"

int main(void){

	Autor c("Marcos","xxx","en","senha",10);
	c.vinculaInstituicao("UfES");
	cout << c.getNome() << endl;

	//Artigo a(100,"Um artigo");
	return 0;
	} 