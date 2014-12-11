#include "CadastroArtigos.h"

CadastroArtigos::CadastroArtigos(string entrada, Revista* r){
  revista = r;

  ifstream inf(entrada);

  /*if (!inf) {
      cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
      exit(1);
  }*/


  getline(inf, linha);

  while (getline(inf, linha)) {

      stringstream lineStream(linha);

      getline(lineStream,codigo,';');

      getline(lineStream,titulo,';');

      getline(lineStream,autores_temp,';');

      getline(lineStream,contato,';');

      if(contato.empty())
	  // Se o campo contato estiver vazio, quer dizer quer o artigo só possui um autor e ele é o contato
	  contato = autores_temp;

      else {
	  istringstream ss(autores_temp);
	  cout << "Autores: " << endl;
	  while(getline(ss,cell,',')){
	      if(cell[0] == ' ')
		  cell.erase(0,0);
		  int autor = atoi(cell.c_str());
	      cout << autor << endl;
	      // Adiciona os autores à lista de autores
	  }
      }

      /* CONSTRUIR OBJETO AQUI */

      int contato_num = atoi(contato.c_str());



      cout << "Contato: " << contato_num << endl;
      cout << "---" << endl;
  }
}
