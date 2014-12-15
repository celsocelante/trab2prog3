# Programa principal:
PRINCIPAL = Main
# Depedencias:
OBJS = Artigo.o Avaliacao.o Autor.o Revisor.o Colaborador.o Edicao.o Revista.o Inconsistencia.o Tema.o CadastroPessoas.o CadastroTemas.o CadastroEdicao.o CadastroArtigos.o CadastroRevisoes.o InterpretadorDeArgumentos.o RelatorioResumo.o RelatorioRevisoes.o RelatorioRevisores.o

INCLUDES = Artigo.h Avaliacao.h Autor.h Revisor.h Colaborador.h Edicao.h Revista.h Inconsistencia.h Tema.h CadastroPessoas.h CadastroTemas.h CadastroEdicao.h CadastroArtigos.h CadastroRevisoes.h InterpretadorDeArgumentos.h RelatorioResumo.h RelatorioRevisoes.h RelatorioRevisores.h


all: $(PRINCIPAL)
compile: $(PRINCIPAL)

$(PRINCIPAL): $(PRINCIPAL).o $(OBJS)
	g++ $(PRINCIPAL).o $(OBJS) -o $@

$(PRINCIPAL).o: $(PRINCIPAL).cpp $(INCLUDES)
	g++ -c $(PRINCIPAL).cpp -o $(PRINCIPAL).o

# compila todos os arquivos .cpp que tem includes
%.o: %.cpp %.h
	g++ -c $*.cpp -o $@

clean:
	rm *.o
	rm $(PRINCIPAL)

run:
	./$(PRINCIPAL) -p entradas/pessoas.csv -a entradas/artigos.csv -r entradas/revisoes.csv -t entradas/temas.csv -e entradas/edicao.txt
