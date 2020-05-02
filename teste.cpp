// testa_trabalho.cpp (Roland Teodorowitsch; 29 abr. 2020)

#include <iostream>
#include "Cnpj.hpp"
//#include "Endereco.hpp"
//#include "Telefone.hpp"
//#include "Empresa.hpp"
//#include "Produto.hpp"
//#include "Produtos.hpp"

using namespace std;

#ifdef _CNPJ_HPP
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

#ifdef _ENDERECO_HPP
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

#ifdef _TELEFONE_HPP
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

#ifdef _EMPRESA_HPP
int testaEmpresa() {
    // Não testa toString(), pois o formato de saída não é rigoroso neste caso
    string csv="Supermercado Boa Praça;40.160.083/0001-09;1020306789;Rua da Esperança;1234;;Jardim Velho;Porto Alegre;RS;90123-456;55;51;34215678";
    
    Endereco end1;
    end1.defineLogradouro("1");
    end1.defineNumero("2");
    end1.defineComplemento("3");
    end1.defineBairro("4");
    end1.defineCidade("5");
    end1.defineUF("6");
    end1.defineCEP("7");
    Endereco end2;
    end2.defineLogradouro("Rua da Esperança");
    end2.defineNumero("1234");
    end2.defineComplemento("");
    end2.defineBairro("Jardim Velho");
    end2.defineCidade("Porto Alegre");
    end2.defineUF("RS");
    end2.defineCEP("90123-456");
    Endereco end3 = end2;
    
    Telefone tel1;
    tel1.defineDDI(1);
    tel1.defineDDD(2);
    tel1.defineNumero(3);
    Telefone tel2;
    tel2.defineDDI(55);
    tel2.defineDDD(51);
    tel2.defineNumero(34215678);
    Telefone tel3 = tel2;
    
    Empresa emp;
    emp.defineNome("Supermercado Boa ");
    emp.defineCNPJ("15305817000145");
    emp.defineInscEst("102030");
    emp.defineEndereco(&end1);
    emp.defineTelefone(&tel1);

    string s;
    s = emp.obtemNome();
    emp.defineNome(s+"Praça");
    s = emp.obtemCNPJ();
    if (s != "15.305.817/0001-45")
        return 0;
    emp.defineCNPJ("40.160.083/0001-09");
    s = emp.obtemInscEst();
    emp.defineInscEst(s+"6789");
    Endereco *pEnd = emp.obtemEndereco();
    if (pEnd->toCSV() != "1;2;3;4;5;6;7")
        return 0;
    emp.defineEndereco(&end2);
    Telefone *pTel = emp.obtemTelefone();
    if (pTel->toCSV() != "1;2;3")
        return 0;
    emp.defineTelefone(&tel2);

    if (emp.toCSV() != csv)
        return 0;

    Empresa emp3;
    emp3.defineNome("Supermercado Boa Praça");
    emp3.defineCNPJ("40160083000109");
    emp3.defineInscEst("1020306789");
    emp3.defineEndereco(&end3);
    emp3.defineTelefone(&tel3);

	if	(!(emp == emp3))
		return 0;
    emp3.defineInscEst("1020306788");
	if	(emp == emp3)
		return 0;

    return 1;
}
#endif

#ifdef _PRODUTO_HPP
int testaProduto() {
    string csv1="7896324274608;Biscoito Mosmann Maria Tradicional 400g;unidade;kg;0.4;4.29";
    Produto p1("7896324274608","Biscoito Mosmann Maria Tradicional 400g",1,"kg", 0.4, 4.29);
    if ( p1.toCSV() != csv1 )
        return 0;
    Produto p2;
    string csv2 = "7898912020178;Cerveja Dadobier Lager Leve Lata 350ml;unidade;litro;0.35;2.19";
    if (!p2.fromCSV(csv2))
        return 0;
    if ( p2.toCSV() != csv2 )
        return 0;
    string csv3 = "7891095100552;Lentilha Yoki 500g;unidade;kg;0.5;4.99";
    Produto p3("7891095100","Lentilha Yoki",0,"k",0.1,3.99);
    string s = p3.obtemCodBarras();
    p3.defineCodBarras(s+"552");
    s = p3.obtemDescricao();
    p3.defineDescricao(s+" 500g");
    int u = p3.obtemGranelOuUnidade();
    p3.defineGranelOuUnidade(u+1);
    s = p3.obtemMedida();
    p3.defineMedida(s+"g");
    double v = p3.obtemQuantidade();
    p3.defineQuantidade(v+0.4);
    v = p3.obtemPreco();
    p3.definePreco(v+1.0);
    if ( p3.toCSV() != csv3 )
        return 0;
    
    Produto p4 = p3;
	if	(!(p4 == p3))
		return 0;
    p4.definePreco(4.999);
	if	(p4 == p3)
		return 0;

    if ( !(p1 < p2) )
        return 0;
    if ( p2 < p1 )
        return 0;
    
	return 1;
}
#endif
    
#ifdef _PRODUTOS_HPP
int testaProdutos() {
	return 1;
}
#endif

int main() {
#ifdef _CNPJ_HPP
	cout << "Cnpj:\t\t\t" << (testaCnpj()?"OK":"FALHOU") << endl;
#endif    
#ifdef _ENDERECO_HPP
	cout << "Endereco:\t\t" << (testaEndereco()?"OK":"FALHOU") << endl;
#endif    
#ifdef _TELEFONE_HPP
	cout << "Telefone:\t\t" << (testaTelefone()?"OK":"FALHOU") << endl;
#endif    
#ifdef _EMPRESA_HPP
	cout << "Empresa:\t\t" << (testaEmpresa()?"OK":"FALHOU") << endl;
#endif    
#ifdef _PRODUTO_HPP
	cout << "Produto:\t\t" << (testaProduto()?"OK":"FALHOU") << endl;
#endif    
#ifdef _PRODUTOS_HPP
	cout << "Produtos:\t\t" << (testaProdutos()?"OK":"FALHOU") << endl;
#endif    
	return 0;
}

