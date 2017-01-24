#include <iostream>
#include "hangarCristal.h"
#include <math.h>

using namespace std;

HangarCristal::HangarCristal():Batiment(){
	refresh();
}

HangarCristal::~HangarCristal(){
	
}

void HangarCristal::Description(ostream &flux) const{
    flux << "hangar de cristal";
}

void HangarCristal::refresh(){
	metalUp = 2000*pow(2, niveau);
    cristalUp = 1000*pow(2, niveau);
    deuteriumUp = 0;
}

string HangarCristal::getNom(){
    return "hangar de cristal";
}
