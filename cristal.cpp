#include <iostream>
#include "cristal.h"
#include <math.h>

using namespace std;

Cristal::Cristal():Batiment()
{
	refresh();
}

Cristal::~Cristal(){
    
}

int Cristal::getProd(){
    return prodCristal;
}

int Cristal::getConso(){
    return consoEnergie;
}

void Cristal::Description(ostream &flux) const{
    flux << "mine cristal";
}

void Cristal::refresh(){
    prodCristal = 20*niveau*pow(1.1, niveau);
    metalUp = 48*pow(1.6, niveau);
    cristalUp = 24*pow(1.6, niveau);
    deuteriumUp = 0;
    consoEnergie = 10*niveau*pow(1.1, niveau);
}

string Cristal::getNom(){
    return "mine de cristal";
}

