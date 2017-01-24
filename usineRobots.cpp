#include <iostream>
#include "usineRobots.h"
#include <math.h>

using namespace std;

UsineRobots::UsineRobots():Batiment(){
	refresh();
}

UsineRobots::~UsineRobots(){
	
}

void UsineRobots::Description(ostream &flux) const{
    flux << "usine de robots";
}

void UsineRobots::refresh(){
	metalUp = 400*pow(2, niveau);
    cristalUp = 120*pow(2, niveau);
    deuteriumUp = 200*pow(2, niveau);
}

string UsineRobots::getNom(){
    return "usine de robots";
}
