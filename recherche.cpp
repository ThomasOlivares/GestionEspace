#include <string>
#include <cassert>
#include "recherche.h"

using namespace std;

Recherche::Recherche(int num):Construction(), num(num), niveau(0){
	initCout();
}

Recherche::Recherche(Recherche* r){
	num = r->getNum();
	nom = r->getNom();
	niveau = r->getNiveau();
}

Recherche::~Recherche(){
	
}

void Recherche::initCout(){
	switch(num){
		case 0:
			metalUp = 0;
			cristalUp = 800;
			deuteriumUp = 400;
			break;
		case 1:
			metalUp = 200;
			cristalUp = 100;
			deuteriumUp = 0;
			break;
		case 2:
			metalUp = 1000;
			cristalUp = 300;
			deuteriumUp = 100;
			break;
		case 3:
			metalUp = 0;
			cristalUp = 4000;
			deuteriumUp = 2000;
			break;
		case 4:
			metalUp = 2000;
			cristalUp = 4000;
			deuteriumUp = 1000;
			break;
		case 5:
			metalUp = 400;
			cristalUp = 0;
			deuteriumUp = 800;
			break;
		case 6:
			metalUp = 2000;
			cristalUp = 4000;
			deuteriumUp = 600;
			break;
		case 7:
			metalUp = 10000;
			cristalUp = 20000;
			deuteriumUp = 6000;
			break;
		case 8:
			metalUp = 200;
			cristalUp = 1000;
			deuteriumUp = 200;
			break;
		case 9:
			metalUp = 0;
			cristalUp = 400;
			deuteriumUp = 600;
			break;
		case 10:
			metalUp = 4000;
			cristalUp = 8000;
			deuteriumUp = 4000;
			break;
		case 11:
			metalUp = 240000;
			cristalUp = 400000;
			deuteriumUp = 160000;
			break;
		case 12:
			metalUp = 0;
			cristalUp = 0;
			deuteriumUp = 0;
			break;
		case 13:
			metalUp = 800;
			cristalUp = 200;
			deuteriumUp = 0;
			break;
		case 14:
			metalUp = 200;
			cristalUp = 600;
			deuteriumUp = 0;
			break;
		case 15:
			metalUp = 1000;
			cristalUp = 0;
			deuteriumUp = 0;
			break;
	}
}

int Recherche::getNum(){
	return num;
}

std::string Recherche::getNom(){
	return nom;
}

void Recherche::setNom(std::string nv){
	nom = nv;
}

std::string Recherche::getType(){
	return "recherche";
}

int Recherche::getNiveau(){
	return niveau;
}

void Recherche::setNiveau(int valeur){
	niveau = valeur;
}

void Recherche::levelUp(){
	assert(!enRecherche());
    temps = (float)(metalUp + cristalUp)/5000*(2/(float)vitesse);
}

int Recherche::enRecherche(){
	return temps > 0;
}

void Recherche::cancelRecherche(){
    temps = 0;
}

void Recherche::construire(int tps){
    float uneHeure = pow(10,6)*3600;
    if (!enRecherche()){
        return;
    }
    temps-=(float)tps/uneHeure;
    if (temps <= 0){
        temps = 0;
        niveau++;
        refresh();
    }
}