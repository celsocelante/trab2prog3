#ifndef RELATORIOREVISOES_H
#define RELATORIOREVISOES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Revista.h"

class RelatorioRevisoes{

private:
  Revista* revista;
  RelatorioRevisoes() {  }

public:

  RelatorioRevisoes(Revista* r){
      revista = r;
  }

  void escreveRelatorio();
};



#endif
