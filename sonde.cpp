#include <iostream>
#include <string>
#include "sonde.h"

using namespace std;

Sonde::Sonde() : Vaisseau()
{
    metalUp = 0;
    cristalUp = 1000;
    deuteriumUp = 0;
}

Sonde::~Sonde(){
	
}

string Sonde::getNom(){
    return "sonde d'espionnage";
}

int Sonde::getNum(){
	return 11;
}
