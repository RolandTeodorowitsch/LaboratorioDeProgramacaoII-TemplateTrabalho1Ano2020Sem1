// Cnpj.hpp (Roland Teodorowitsch; 29 abr. 2020)

#ifndef _CNPJ_HPP
#define _CNPJ_HPP

#include <string>

using namespace std;

class Cnpj {
	private:
		string raiz;
		string filial;
		string dv;
	public:
		Cnpj();
		bool define(string cnpj);
		static bool ehValido(string cnpj);
		string obtemRaiz();
		string obtemFilial();
		string obtemDV();
		string toString();
		bool operator==(Cnpj &cnpj);
};

#endif
