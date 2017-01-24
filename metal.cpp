#include <iostream>
#include "metal.h"
#include <math.h>

using namespace std;

Metal::Metal():Batiment(){
	refresh();
}

Metal::~Metal(){
    
}

void Metal::Description(ostream &flux) const{
    flux << "mine metal";
}

int Metal::getProd(){
	return prodMetal;
}

int Metal::getConso(){
    return consoEnergie;
}

void Metal::refresh(){
	prodMetal = 30*niveau*pow(1.1, niveau);
    metalUp = 60*pow(1.5, niveau);
    cristalUp = 15*pow(1.5, niveau);
    deuteriumUp = 0;
    consoEnergie = 10*niveau*pow(1.1, niveau);
}

string Metal::getNom(){
    return "mine de metal";
}
