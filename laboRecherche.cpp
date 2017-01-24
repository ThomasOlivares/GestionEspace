#include <iostream>
#include "laboRecherche.h"
#include <math.h>

using namespace std;

LaboRecherche::LaboRecherche():Batiment(){
	refresh();
}

LaboRecherche::~LaboRecherche(){
	
}

void LaboRecherche::Description(ostream &flux) const{
    flux << "labo de recherche";
}

void LaboRecherche::refresh(){
    metalUp = 200*pow(2, niveau);
    cristalUp = 400*pow(2, niveau);
    deuteriumUp = 200*pow(2, niveau);
}

string LaboRecherche::getNom(){
    return "labo de recherche";
}
