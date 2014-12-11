#include "CadastroArtigos.h"

CadastroArtigos::CadastroArtigos(char* entrada, Revista* r){
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

      getline(lineStream,autores,';');

      getline(lineStream,contato,';');

      if(contato.empty()){
	  // Se o campo contato estiver vazio, quer dizer quer o artigo só possui um autor e ele é o contato
	  contato = autores;
      } else {
	  contato_int = atoi(contato.c_str());
	  codigo_int = atoi(codigo.c_str());
     
	  istringstream ss(autores);
	  cout << "Autores: " << endl;
	  while(getline(ss,cell,',')){
	      int autor_int = atoi(cell.c_str());
	      cout << autor_int << endl;
	      // Adiciona os autores à lista de autores
	  }
      }

      /* CONSTRUIR OBJETO AQUI */
      cout << "Contato: " << contato_int << endl;


      cout << "---" << endl;
  }
}
