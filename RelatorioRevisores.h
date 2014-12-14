#ifndef RELATORIOREVISORES_H
#define RELATORIOREVISORES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Revista.h"

class RelatorioRevisores{

private:
  Revista* revista;
  RelatorioRevisores() {  }

public:

  RelatorioRevisores(Revista* r){
      revista = r;
  }

  void escreveRelatorio();
};



#endif
