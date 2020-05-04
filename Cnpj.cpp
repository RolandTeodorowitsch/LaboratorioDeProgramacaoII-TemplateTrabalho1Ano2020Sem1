// Cnpj.cpp (Roland Teodorowitsch; 29 abr. 2020)

#include <cctype>
#include <iostream>
#include "Cnpj.hpp"

Cnpj::Cnpj() {
	raiz="00000000";
    filial="0000";
    dv="00";
}

bool Cnpj::define(string cnpj) {
	if	(!ehValido(cnpj))
		return false;
    if	(cnpj.size()==18) {
		raiz = cnpj.substr(0,2) + cnpj.substr(3,3) + cnpj.substr(7,3);
        filial = cnpj.substr(11,4);
        dv = cnpj.substr(16,2);
    }
    else {
		raiz = cnpj.substr(0,8);
        filial = cnpj.substr(8,4);
        dv = cnpj.substr(12,2);
    }
	return true;
}

bool Cnpj::ehValido(string cnpj) {
	if	(cnpj.size()==18) { // 00.000.000/0000-00
		if	(cnpj.at(2)!='.' || cnpj.at(6)!='.' || cnpj.at(10)!='/' || cnpj.at(15)!='-')
			return false;
		cnpj = cnpj.substr(0,2) + cnpj.substr(3,3) + cnpj.substr(7,3) +
		       cnpj.substr(11,4) + cnpj.substr(16,2);
	}
	if (cnpj.size()==14) {
		for	(int i=0; i<14; ++i)
			if	(!isdigit(cnpj.at(i)))
				return false;
		int peso1[] = {5,4,3,2,9,8,7,6,5,4,3,2};
		int soma = 0;
		for	(int i=0; i<12; ++i)
			soma += (cnpj.at(i)-'0') * peso1[i];
		int div = soma / 11;
		int resto = soma % 11;
		char dv1;
		if	(resto < 2)
			dv1 = '0';
		else
			dv1 = 11 - resto + '0';
		if	(dv1 != cnpj.at(12))
			return false;
		int peso2[] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
		soma = 0;
		for	(int i=0; i<13; ++i)
			soma += (cnpj.at(i)-'0') * peso2[i];
		div = soma / 11;
		resto = soma % 11;
		char dv2;
		if	(resto < 2)
			dv2 = '0';
		else
			dv2 = 11 - resto + '0';
		if	(dv2 != cnpj.at(13))
			return false;
		return true;
	}
	else
		return false;
}

string Cnpj::obtemRaiz() {
	return raiz;
}

string Cnpj::obtemFilial() {
	return filial;
}

string Cnpj::obtemDV() {
	return dv;
}

string Cnpj::toString() {
	return raiz.substr(0,2)+"."+raiz.substr(2,3)+"."+raiz.substr(5,3)+"/"+filial+"-"+dv;
}

bool Cnpj::operator==(Cnpj &cnpj) {
	if	(raiz.compare(cnpj.obtemRaiz())==0 &&
         filial.compare(cnpj.obtemFilial())==0 &&
         dv.compare(cnpj.obtemDV())==0 )
		return true;
	return false;	
}
