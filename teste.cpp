// testa_trabalho.cpp (Roland Teodorowitsch; 29 abr. 2020)

#define CNPJ_OK
//#define ENDERECO_OK
//#define TELEFONE_OK
//#define EMPRESA_OK
//#define PRODUTO_OK
//#define PRODUTOS_OK

#include <iostream>
#ifdef CNPJ_OK
#include "Cnpj.hpp"
#endif
#ifdef ENDERECO_OK
#include "Endereco.hpp"
#endif
#ifdef TELEFONE_OK
#include "Telefone.hpp"
#endif
#ifdef EMPRESA_OK
#include "Empresa.hpp"
#endif
#ifdef PRODUTO_OK
#include "Produto.hpp"
#endif
#ifdef PRODUTOS_OK
#include "Produtos.hpp"
#endif

using namespace std;

#ifdef CNPJ_OK
int testaCnpj() {
	// Teste para a classe Cnpj (return 0 significa que o teste falhou)s
	string s1 = "40.160.083/0001-09"; // CNPJ Valido
	if	(!Cnpj::ehValido(s1))
	       	return 0;
	string s2 = "15305817000145"; // CNPJ Valido
	if	(!Cnpj::ehValido(s2))
	       	return 0;
	if	(!Cnpj::ehValido("11.444.777/0001-61")) // CNPJ Valido
		return 0;
	if	(Cnpj::ehValido("11.444.777/0001-60")) // CNPJ Invalido
	       	return 0;
	if	(Cnpj::ehValido("11.444.777/0001-62")) // CNPJ Invalido
	       	return 0;
	if	(Cnpj::ehValido("0123456789abcd")) // CNPJ Invalido
		return 0;
	Cnpj cnpj1;
	cnpj1.define(s1);
	if	(cnpj1.toString() != s1)
		return 0;
	Cnpj cnpj2;
	cnpj2.define(s2);
	if	(cnpj2.obtemRaiz() != s2.substr(0,8) ||
		 cnpj2.obtemFilial() != s2.substr(8,4) ||
		 cnpj2.obtemDV() != s2.substr(12,2) )
		return 0;
	if	(cnpj1 == cnpj2)
		return 0;
	Cnpj cnpj3 = cnpj1;
	if	(!(cnpj1 == cnpj3))
		return 0;
	return 1;
}
#endif

#ifdef ENDERECO_OK
int testaEndereco() {
    // Não testa toString(), pois o formato de saída não é rigoroso neste caso
    string csv="Rua da Esperança;1234;s/c;Jardim Velho;Porto Alegre;RS;90123-456";
    Endereco e1;
    e1.defineLogradouro("Rua da ");
    e1.defineNumero("123");
    e1.defineComplemento("s/");
    e1.defineBairro("Jardim ");
    e1.defineCidade("Porto ");
    e1.defineUF("R");
    e1.defineCEP("90123-");
    string s;
    s = e1.obtemLogradouro();
    e1.defineLogradouro(s+"Esperança");
    s = e1.obtemNumero();
    e1.defineNumero(s+"4");
    s = e1.obtemComplemento();
    e1.defineComplemento(s+"c");
    s = e1.obtemBairro();
    e1.defineBairro(s+"Velho");
    s = e1.obtemCidade();
    e1.defineCidade(s+"Alegre");
    s = e1.obtemUF();
    e1.defineUF(s+"S");
    s = e1.obtemCEP();
    e1.defineCEP(s+"456");
    Endereco e2 = e1;
	if	(!(e1 == e2))
		return 0;
    e2.defineComplemento("");
	if	(e1 == e2)
		return 0;
    if (e1.toCSV() != csv)
        return 0;
	return 1;
}
#endif

#ifdef TELEFONE_OK
int testaTelefone() {
    Telefone t1;
    t1.defineDDI(55);
    t1.defineDDD(51);
    t1.defineNumero(34215678);
    if (t1.toString() != "+55(51)3421-5678")
        return 0;
    if (t1.toCSV(';') != "55;51;34215678")
        return 0;
    Telefone t2 = t1;
	if	(!(t1 == t2))
		return 0;
    t1.defineDDI(56);
	if	(t1 == t2)
		return 0;
	return 1;
}
#endif

#ifdef EMPRESA_OK
int testaEmpresa() {
	return 1;
}
#endif

#ifdef PRODUTO_OK
int testaProduto() {
	return 1;
}
#endif
    
#ifdef PRODUTOS_OK
int testaProdutos() {
	return 1;
}
#endif

int main() {
#ifdef CNPJ_OK
	cout << "Cnpj:\t\t\t" << (testaCnpj()?"OK":"FALHOU") << endl;
#endif    
#ifdef ENDERECO_OK
	cout << "Endereco:\t\t" << (testaEndereco()?"OK":"FALHOU") << endl;
#endif    
#ifdef TELEFONE_OK
	cout << "Telefone:\t\t" << (testaTelefone()?"OK":"FALHOU") << endl;
#endif    
#ifdef EMPRESA_OK
	cout << "Empresa:\t\t" << (testaEmpresa()?"OK":"FALHOU") << endl;
#endif    
#ifdef PRODUTO_OK
	cout << "Produto:\t\t" << (testaProduto()?"OK":"FALHOU") << endl;
#endif    
#ifdef PRODUTOS_OK
	cout << "Produtos:\t\t" << (testaProdutos()?"OK":"FALHOU") << endl;
#endif    
	return 0;
}

