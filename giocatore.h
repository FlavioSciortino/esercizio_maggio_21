#include<iostream>
using namespace std;
#ifndef GIOCATORE_H
#define GIOCATORE_H
class giocatore {
	string cognome, nome, circolo;
	int anno;
	double punteggio;
public:
	bool operator <=(giocatore & g) { return this->punteggio <= g.punteggio;}
	bool operator >=(giocatore & g) {return this->punteggio >= g.punteggio; }
	bool operator !=(giocatore & g) {return this->punteggio != g.punteggio; }
	giocatore(string cognome, string nome, string circolo, int anno, double punteggio) {cognome(cognome), nome(nome), circolo(circolo), anno(anno), punteggio(punteggio)}
	friend ostream &operator<<(ostream &os, giocatore & g) {
		os << "nome = " << g.nome << endl; 
		os << "cognome = " << g.cognome << endl;
		os << "circolo = " << g.circolo << endl;
		os << "anno = " << g.anno << endl;
		os << "punteggio = " << g.punteggio << endl;
		return os;
	}

	friend istream &operator>>(istream &is, giocatore g) {
		string punteggio_str, anno_str;
		std::getline(is, g.nome, ';');
		std::getline(is, g.cognome, ';');
		std::getline(is, g.circolo, ';');
		std::getline(is, g.anno, ';');
		std::getline(is, g.punteggio, '\n');
		g.punteggio = std::atof(punteggio_str.c_str());
		g.anno = std::atoi(anno_str.c_str());
		return is;
	}
};
#endif