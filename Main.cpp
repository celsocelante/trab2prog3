#include "Colaborador.h"
#include "Revisor.h"
#include "Artigo.h"
#include "Autor.h"


int main(void){

	Autor c("Marcos","xxx","en","senha",10);
	c.vinculaInstituicao("UfES");
	cout << c.getNome() << endl;

	Artigo a(100,"Um artigo");
	a.setContato(&c);
	
	a.vinculaAutor(c);
	
	cout << a.getContato() << endl;
	
	
	return 0;
	} 