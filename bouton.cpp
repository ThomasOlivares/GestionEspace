#include "bouton.h"
#include <iostream>

using namespace std;

Bouton::Bouton() : posX(-10), posY(-10), largeur(-10), longueur(-10), symbole(""), action(""), actif(0){
	
}

Bouton::Bouton(string symbole, string action, int posX, int posY, int largeur, int longueur)
	 : symbole(symbole), action(action), posX(posX), posY(posY), largeur(largeur), 
	 	longueur(longueur), actif(1){
}

Bouton::Bouton(Bouton* b){
	actif = b->getActif();
	symbole = b->getSymbole();
	action = b->getAction();
	posX = b->getPosX();
	posY = b->getPosY();
	largeur = b->getLargeur();
	longueur = b->getLongueur();
}


Bouton::~Bouton(){
}

int Bouton::getClicked(int x, int y){
	if (!actif){
		return 0;
	}
	if ((x >= posX) && (x <= posX + largeur) && (y >= posY) && (y <= posY + longueur)){
		return 1;
	}
	return 0;
}

string Bouton::getSymbole(){
	return symbole;
}

string Bouton::getAction(){
	return action;
}

int Bouton::getPosX(){
	return posX;
}

int Bouton::getPosY(){
	return posY;
}

int Bouton::getLargeur(){
	return largeur;
}

int Bouton::getLongueur(){
	return longueur;
}

int Bouton::getActif(){
	return actif;
}

void Bouton::setActif(int act){
	actif = act;
}
