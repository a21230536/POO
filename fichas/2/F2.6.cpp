// Ficha 2, Exercício 6

#include <iostream>
#include <sstream>// (c)
#include <string>

using namespace std;
//-----------------------------------------------------------------------------
// (a) Construir a classe Automovel com as características enunciadas e incluir
//     na função main código que permite testar a classe.
//-----------------------------------------------------------------------------
class Automovel{
	string matricula;
	string combustivel;
	string marca;
	string modelo;
	string cor;
	string outros;//int ano;//int rodas;

public:

	// funções para obter valores
	string getMatricula();
	string getCombustivel();
	string getMarca();
	string getModelo();
	string getCor();
	string getOutros();

	// funções para o atribuir/modificar valore
	void setMatricula(string);
	void setCombustivel(string);
	void setMarca(string);
	void setModelo(string);
	void setCor(string);
	void setOutros(string);

	// funções para manipular todos os valores
	void mostra();
	void setPorCin();

	// função modifica os valores por argumentos
	void set(string matricula, string combustivel, string marca,
		string modelo, string cor, string outros);

	// devolve representação textual (c)
	string getString();

	// executar o construtor com valores por omissão
	Automovel(string mat="N/D", string com="N/D", string mar="N/D",
		string mod="N/D", string cor="N/D", string out="N/D");
};

int main(){
	Automovel automovel;

	// mostrar valores oblidos por omissão
	automovel.mostra();

	automovel.set("AH-23-21-AJ", "gasoleo", "Opel", "Corsa", "preto", "especial");
	automovel.mostra();

	while(true){
		automovel.setPorCin();
		cout << automovel.getString() << endl;
	}

	return 0;
}

//-----------------------------------------------------------------------------
// (b) Analise as regras mais óbvias do mundo real acerca de automóveis,
//     nomeadamente no que diz respeito à sua construção e inicialização...
//-----------------------------------------------------------------------------

// construtor
Automovel::Automovel(string mat, string com, string mar,
		string mod, string cor, string out){
	// validar os valores aqui (b)

	set(mat, com, mar, mod, cor, out);
}

//-----------------------------------------------------------------------------
// (c) Escreva uma função que permita obter a representação textual do conteúdo
//     da estrutura...
//-----------------------------------------------------------------------------
string Automovel::getString(){
	ostringstream automovelString;

	automovelString << "\nAutomovel\nMatricula:" << matricula
		<<"\nCombustivel:" << combustivel
		<<"\nMarca: " << marca
		<< "\nModelo: " << modelo
		<<"\nCor: " << marca
		<< "\nOutros: " << outros << endl;

	return automovelString.str();
}

// mostra na consola todos os valores
void Automovel::mostra(){
	cout << endl
	     << "Automovel" << endl
	     << "Matricula: " << getMatricula() << endl
	     << "Combustivel: " << getCombustivel() << endl
	     << "Marca: " << getMarca() << endl
	     << "Modelo: " << getModelo() << endl
	     << "Cor: " << getCor() << endl
	     << "Outros: " << getOutros() << endl
	     << endl;
}

// modifica as variáveis com valores obtidos pela consola
void Automovel::setPorCin(){
	string mat, com, mar, mod, cor, out;

	cout << "Matricula: ";
	getline(cin, mat);
	setMatricula(mat);

	cout << "Combustivel: ";
	getline(cin, com);
	setCombustivel(com);

	cout << "Marca: ";
	getline(cin, mar);
	setMarca(mar);

	cout << "Modelo: ";
	getline(cin, mod);
	setModelo(mod);

	cout << "Cor: ";
	getline(cin, cor);
	setCor(cor);

	cout << "Outros: ";
	getline(cin, out);
	setOutros(out);
}

//-----------------------------------------------------------------------------
// (c) Escrever uma função que preencha o conteúdo de uma variável do tipo
//     Automovel com valores fornecidos. Evitar interagir com o utilizador
//     directamente dentro das funções que manipulam os dados da estrutura.
//-----------------------------------------------------------------------------
void Automovel::set(string mat, string com, string mar,
		string mod, string cor, string out){
	setMatricula(mat);
	setCombustivel(com);
	setMarca(mar);
	setModelo(mod);
	setCor(cor);
	setOutros(out);
}

//-----------------------------------------------------------------------------
// (d) Escreva funções que permitam obter e actualizar cada dado desta estrutura.
//-----------------------------------------------------------------------------
string Automovel::getMatricula(){
	return matricula;
}

string Automovel::getCombustivel(){
	return combustivel;
}

string Automovel::getMarca(){
 return marca;
}

string Automovel::getModelo(){
	return modelo;
}

string Automovel::getCor(){
	return cor;
}

string Automovel::getOutros(){
	return outros;
}
void Automovel::setMatricula(string s){
	// validar o valor de s aqui (b)

	matricula = s;
}

void Automovel::setCombustivel(string s){
	// validar o valor de s aqui (b)

	combustivel = s;
}

void Automovel::setMarca(string s){
	// validar o valor de s aqui (b)

	marca = s;
}

void Automovel::setModelo(string s){
	// validar o valor de s aqui (b)

	modelo = s;
}

void Automovel::setCor(string s){
	// validar o valor de s aqui (b)

	cor = s;
}

void Automovel::setOutros(string s){
	// validar o valor de s aqui (b)

	outros = s;
}
