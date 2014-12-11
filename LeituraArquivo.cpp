    #include <fstream>
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include <vector>
    #include <sstream>
    #include <iterator>

    int main()
    {
        using namespace std;

        ifstream inf("artigos.csv");

        if (!inf) {
            cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
            exit(1);
        }

        string cell, linha;

        string codigo;
        string titulo;
        string autores_temp;
        string contato;


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
                    cout << cell << endl;
                    // Adiciona os autores à lista de autores
                }
            }

            /* CONSTRUIR OBJETO AQUI */



            cout << "Contato: " << contato << endl;
            cout << "---" << endl;
        }

        return 0;
    }
