#include "CadastroRevisoes.h"

CadastroRevisoes::CadastroRevisoes(const char* entrada, Revista* revista){

  string cell, linha;
  string codigo;
  int codigo_int;
  string revisor;
  int revisor_int;

  string originalidade, apresentacao, conteudo;
  double originalidade_d, apresentacao_d,conteudo_d;

  ifstream inf(entrada);

  getline(inf, linha);

  while (getline(inf, linha)) {

    stringstream lineStream(linha);

    getline(lineStream,codigo,';');
    // Converte o string lido para inteiro
    codigo_int = atoi(codigo.c_str());

    getline(lineStream,revisor,';');
    revisor_int = atoi(revisor.c_str());

    getline(lineStream,originalidade,';');
    originalidade_d = atof(originalidade.c_str());

    getline(lineStream,conteudo,';');
    conteudo_d = atof(conteudo.c_str());

    getline(lineStream,apresentacao,';');
    apresentacao_d = atof(apresentacao.c_str());


    // Cria o stream para o texto da inconsistência e o transforma em string
    ostringstream texto_inconsistencia_stream;
    string texto_inconsistencia;

    Colaborador* c = revista->buscaColaborador(revisor_int);
    if(c == NULL || dynamic_cast<Revisor*>(c) != 0){
      // Trata inconsistencia #8: Revisor informado para revisao nao esta cadastrado
      texto_inconsistencia_stream << "O código " << revisor_int << " encontrado no cadastro de revisões não corresponde a um revisor cadastrado.";
      texto_inconsistencia = texto_inconsistencia_stream.str();

      Inconsistencia* i  = new Inconsistencia(texto_inconsistencia,8);
      revista->adicionaInconsistencia(i);
    }
    else{

      Revisor* r = dynamic_cast<Revisor*>(c);
      Avaliacao* avaliacao = new Avaliacao(r);
      avaliacao->atribuirNota(originalidade_d,conteudo_d,apresentacao_d);

      Artigo* artigo = revista->getEdicao()->buscaArtigo(codigo_int);
      
      
      if(artigo == NULL){
        texto_inconsistencia_stream.str("");
        // Trata insconsistencia #9: código do artigo não está cadastrado em artigos submetidos à edição
        texto_inconsistencia_stream << "O código " << codigo_int + " encontrado no cadastro de revisões não corresponde a um artigo cadastrado.";
        texto_inconsistencia = texto_inconsistencia_stream.str();
        Inconsistencia* i = new Inconsistencia(texto_inconsistencia,9);

        revista->adicionaInconsistencia(i);
      }
      else{
        artigo->adicionaAvaliacao(avaliacao);
        r->vinculaRevisao(artigo);

        texto_inconsistencia_stream.str("");
        // Trata inconsistencia #10: revisor não habilitado a revisar artigo sob tema da edição
        if(&(revista->getEdicao()->getTema()) != NULL)
          if(!(revista->getEdicao()->getTema().contemRevisor(r))){
              
              texto_inconsistencia_stream << "O revisor " << r->getNome() << " avaliou o artigo " + artigo->getTitulo() << ", porém ele não consta como apto a avaliar o tema." << revista->getEdicao()->getTema() << ", desta edição.";
              texto_inconsistencia = texto_inconsistencia_stream.str();
              Inconsistencia* i = new Inconsistencia(texto_inconsistencia,10);

              revista->adicionaInconsistencia(i);
          }

      }
    }
  }


  texto_inconsistencia_stream.str("");
  set<Artigo*>::iterator it;
  for(it = revista->getEdicao()->getArtigos().begin(); it != revista->getEdicao()->getArtigos().end(); it++){
    Artigo* a = *it;
      if (!a->getQuantidadeRevisoes()){
        texto_inconsistencia_stream << "O artigo " << "\"" << a->getTitulo() << "\"" << " possui " < a->getQuantidadeRevisoes() < " revisões. Cada artigo deve conter exatamente 3 revisões.";
        texto_inconsistencia = texto_inconsistencia_stream.str();
        Inconsistencia* i = new Inconsistencia(texto_inconsistencia,11);
        
        revista->adicionaInconsistencia(i);

        // Limpa o stream de mensagem de inconsistencia
        texto_inconsistencia_stream.str("");
      }
  }

}