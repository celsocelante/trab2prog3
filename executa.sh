#!/bin/bash

g++ Autor.cpp Artigo.cpp Avaliacao.cpp Revisor.cpp Colaborador.cpp Edicao.cpp Revista.cpp Inconsistencia.cpp Tema.cpp CadastroPessoas.cpp CadastroTemas.cpp CadastroEdicao.cpp CadastroArtigos.cpp CadastroRevisoes.cpp InterpretadorDeArgumentos.cpp Main.cpp -o main
./main -p entradas/pessoas.csv -r entradas/revisoes.csv -a entradas/artigos.csv -t entradas/temas.csv -e entradas/edicao.txt
