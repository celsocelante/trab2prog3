#!/bin/bash

g++ Autor.cpp Artigo.cpp Avaliacao.cpp Revisor.cpp Colaborador.cpp Edicao.cpp Revista.cpp Inconsistencia.cpp Tema.cpp CadastroPessoas.cpp CadastroTemas.cpp CadastroEdicao.cpp CadastroArtigos.cpp CadastroRevisoes.cpp InterpretadorDeArgumentos.cpp RelatorioResumo.cpp Main.cpp -o main
./main -e entradas/edicao.txt -t entradas/temas.csv -p entradas/pessoas.csv -a entradas/artigos.csv -r entradas/revisoes.csv 
