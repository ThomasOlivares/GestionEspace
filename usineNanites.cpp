#include <iostream>
#include "usineNanites.h"
#include <math.h>

using namespace std;

UsineNanites::UsineNanites():Batiment(){
	refresh();
}

UsineNanites::~UsineNanites(){
	
}

void UsineNanites::Description(ostream &flux) const{
    flux << "usine de nanites";
}

void UsineNanites::refresh(){
    metalUp = 1000000*pow(2, niveau);
    cristalUp = 500000*pow(2, niveau);
    deuteriumUp = 100000*pow(2, niveau);
}

string UsineNanites::getNom(){
    return "usine de nanites";
}
