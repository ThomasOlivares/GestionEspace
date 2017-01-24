#include <iostream>
#include "reservoirDeut.h"
#include <math.h>

using namespace std;

ReservoirDeut::ReservoirDeut():Batiment(){
	refresh();
}

ReservoirDeut::~ReservoirDeut(){
	
}

void ReservoirDeut::Description(ostream &flux) const{
    flux << "reservoir deuterium";
}

void ReservoirDeut::refresh(){
	metalUp = 2000*pow(2, niveau);
    cristalUp = 2000*pow(2, niveau);
    deuteriumUp = 0;
}

string ReservoirDeut::getNom(){
    return "reservoir deuterium";
}
