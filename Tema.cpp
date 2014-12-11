    #include "Tema.h"
        string Tema::getTitulo() const{
            return titulo;
        }

        void Tema::vinculaRevisor(Revisor& revisor){
            revisores.insert(&revisor);
        }

        int Tema::getQuantidadeRevisores(){
            return revisores.size();
        }

        bool Tema::contemRevisor(Revisor& revisor){
            return revisores.find(&revisor) != revisores.end();
        }
