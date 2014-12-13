	#include <iostream>
	#include "Colaborador.h"
	#include "Autor.h"
	#include "Revisor.h"


int main(){

	Colaborador c("Ares","sdasda","das","sadas",3);
	Autor a("Marcos","xxx","en","senha",10);
	Revisor r("Prado","xxx","en","senha",2);

	Colaborador* ptr = &a;
	Colaborador* ptr2 = &r;
	if(!(dynamic_cast<Revisor*>(ptr) != 0)){

		cout << 1 << endl;
	}
	return 0;
}