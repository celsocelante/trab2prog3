	#include "Inconsistencia.h"
		int Inconsistencia::getTipo() const{
			return tipo;
		}

		string Inconsistencia::getMensagem() const{
			return mensagem;
		}

		ostream& operator<< (ostream& str, const Inconsistencia& e){
			return str << "Erro " << e.getTipo() << ": " << e.getMensagem();
			
		}
