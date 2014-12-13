#ifndef RELATORIORESUMO_H
#define RELATORIORESUMO_H

#include <iostream>
#include <iostream>
#include <fstream>
#include "Revista.h"

class RelatorioResumo {

private:
	Revista* revista;
	RelatorioResumo() {  }

public:
	RelatorioResumo(Revista* r){
		revista = r;
	}
	void escreveRelatorio();

};


#endif