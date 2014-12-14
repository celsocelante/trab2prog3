#include "CadastroEdicao.h"

CadastroEdicao::CadastroEdicao(const char* entrada, Revista* revista){
	string linha;

	string tema;
  string editor;
  string data;
  string volume;
  string numero;
  int volume_int;
  int numero_int;

	ifstream inf(entrada);

  getline(inf,tema);
  getline(inf,editor);
  getline(inf,volume);
  getline(inf,numero);
  getline(inf,data);
  volume_int = atoi(volume.c_str());
  numero_int = atoi(numero.c_str());

  Tema* t = revista->buscaTema(tema);
  Colaborador* c = revista->buscaColaborador(editor);

  if(t == NULL) {
    //Trata inconsistencia #1: tema na edicao nao cadastrado
    // Cria o stream para o texto da inconsistência e o transforma em string
    ostringstream texto_inconsistencia_stream;
    string texto_inconsistencia;
    texto_inconsistencia_stream << "O tema " << "\"" << tema << "\"" << " não foi encontrado no cadastro.";

    texto_inconsistencia = texto_inconsistencia_stream.str();

    Inconsistencia* i = new Inconsistencia(texto_inconsistencia,1);
    revista->adicionaInconsistencia(i);

  }
  else if (c == NULL){
          //Trata inconsistencia #2: editor-chefe nao cadastrado no cadastro de pessoas
          ostringstream texto_inconsistencia_stream2;
          string texto_inconsistencia2;

          texto_inconsistencia_stream2 << "O editor-chefe " << "\"" << editor << "\"" << " não foi encontrado no cadastro.";
          texto_inconsistencia2 = texto_inconsistencia_stream2.str();
          Inconsistencia* i = new Inconsistencia(texto_inconsistencia2,2);
          revista->adicionaInconsistencia(i);
        }

  Edicao* edicao = new Edicao(volume_int,numero_int,data,t,c);
  revista->setEdicao(edicao);
}
