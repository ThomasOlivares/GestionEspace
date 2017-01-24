#include <iostream>
#include "silo.h"
#include <math.h>

using namespace std;

Silo::Silo():Batiment(){
	refresh();
}

Silo::~Silo(){
	
}

void Silo::Description(ostream &flux) const{
    flux << "silo a missiles";
}

void Silo::refresh(){
	metalUp = 20000*pow(2, niveau);
    cristalUp = 20000*pow(2, niveau);
    deuteriumUp = 1000*pow(2, niveau);
}

string Silo::getNom(){
    return "silo a missiles";
}
