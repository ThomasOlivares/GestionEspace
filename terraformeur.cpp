#include <iostream>
#include "terraformeur.h"
#include <math.h>

using namespace std;

Terraformeur::Terraformeur():Batiment(){
	refresh();
}

Terraformeur::~Terraformeur(){
	
}

void Terraformeur::Description(ostream &flux) const{
    flux << "terraformeur";
}

void Terraformeur::refresh(){
	metalUp = 0;
    cristalUp = 50000*pow(2, niveau);
    deuteriumUp = 100000*pow(2, niveau);
}

string Terraformeur::getNom(){
    return "terraformeur";
}
