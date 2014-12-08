#include "Colaborador.h"
#include "Revisor.h"
#include "Artigo.h"
#include "Autor.h"
#include "Avaliacao.h"
#include <iostream>

int main(void){

	Autor c("Marcos","xxx","en","senha",10);
	c.vinculaInstituicao("UfES");
	cout << c.getNome() << endl;

	Artigo a(100,"Um artigo");
	a.setContato(c);
	
	a.vinculaAutor(c);

	Revisor r("Prado","xxx","en","senha",2);
	cout << r.getNome() << endl;

	cout << a.getContato() << endl;
	
	Avaliacao ac(r);
	cout << ac.getRevisor()->getNome() << endl;
	return 0;
	} 