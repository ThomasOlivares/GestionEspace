#include <iostream>
#include <math.h>
#include "deuterium.h"

using namespace std;

Deuterium::Deuterium():Batiment()
{
	refresh();
}

Deuterium::~Deuterium(){
    
}

void Deuterium::Description(ostream &flux) const{
    flux << "mine deut.";
}

int Deuterium::getProd(){
    return prodDeut;
}

int Deuterium::getConso(){
    return consoEnergie;
}

void Deuterium::refresh(){
    prodDeut = 10*niveau*pow(1.1, niveau);
    metalUp = 225*pow(1.5, niveau);
    cristalUp = 75*pow(1.5, niveau);
    deuteriumUp = 0;
    consoEnergie = 20*niveau*pow(1.1, niveau);
}

string Deuterium::getNom(){
    return "mine de deut.";
}

