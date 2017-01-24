#include <iostream>
#include <string>
#include "petitTransporteur.h"

using namespace std;

PetitTransporteur::PetitTransporteur() : Vaisseau()
{
    metalUp = 2000;
    cristalUp = 2000;
    deuteriumUp = 0;
}

PetitTransporteur::~PetitTransporteur(){
	
}

string PetitTransporteur::getNom(){
    return "petit transporteur";
}

int PetitTransporteur::getNum(){
	return 8;
}
