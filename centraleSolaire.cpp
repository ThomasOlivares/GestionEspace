#include <iostream>
#include "centraleSolaire.h"
#include <math.h>

using namespace std;

CentraleSolaire::CentraleSolaire():Batiment(){
	refresh();
}

CentraleSolaire::~CentraleSolaire(){
	
}

void CentraleSolaire::Description(ostream &flux) const{
    flux << "centrale solaire";
}

int CentraleSolaire::getProd(){
	return prodEnergie;
}

void CentraleSolaire::refresh(){
	prodEnergie = 20*niveau*pow(1.1, niveau);
    metalUp = 75*pow(1.5, niveau);
    cristalUp = 30*pow(1.5, niveau);
    deuteriumUp = 0;
}

string CentraleSolaire::getNom(){
    return "centrale solaire";
}
