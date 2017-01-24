#include <iostream>
#include "centraleFusion.h"
#include <math.h>

using namespace std;

CentraleFusion::CentraleFusion():Batiment(){
	refresh();
}

CentraleFusion::~CentraleFusion(){
	
}

void CentraleFusion::Description(ostream &flux) const{
    flux << "centrale de fusion";
}

void CentraleFusion::refresh(){
	metalUp = 900*pow(2, niveau);
    cristalUp = 360*pow(2, niveau);
    deuteriumUp = 180*pow(2, niveau);
}

string CentraleFusion::getNom(){
    return "centrale de fusion";
}
