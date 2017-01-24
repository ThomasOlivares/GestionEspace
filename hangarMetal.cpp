#include <iostream>
#include "hangarMetal.h"
#include <math.h>

using namespace std;

HangarMetal::HangarMetal():Batiment(){
	refresh();
}

HangarMetal::~HangarMetal(){
	
}

void HangarMetal::Description(ostream &flux) const{
    flux << "hangar de metal";
}

void HangarMetal::refresh(){
	metalUp = 2000*pow(2, niveau);
    cristalUp = 0;
    deuteriumUp = 0;
}

string HangarMetal::getNom(){
    return "hangar de metal";
}
