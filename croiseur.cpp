#include <iostream>
#include <string>
#include "croiseur.h"

using namespace std;

Croiseur::Croiseur() : Vaisseau()
{
    metalUp = 20000;
    cristalUp = 7000;
    deuteriumUp = 2000;
}

Croiseur::~Croiseur(){
	
}

string Croiseur::getNom(){
    return "croiseur";
}

int Croiseur::getNum(){
	return 2;
}
