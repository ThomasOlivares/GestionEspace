#include <iostream>
#include <string>
#include "satellite.h"

using namespace std;

Satellite::Satellite() : Vaisseau()
{
    metalUp = 0;
    cristalUp = 2000;
    deuteriumUp = 500;
}

Satellite::~Satellite(){
	
}

string Satellite::getNom(){
    return "satellite";
}

int Satellite::getNum(){
	return 10;
}
