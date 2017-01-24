#include <iostream>
#include <string>
#include "destructeur.h"

using namespace std;

Destructeur::Destructeur() : Vaisseau()
{
    metalUp = 60000;
    cristalUp = 50000;
    deuteriumUp = 15000;
}

Destructeur::~Destructeur(){
	
}

string Destructeur::getNom(){
    return "destructeur";
}

int Destructeur::getNum(){
	return 6;
}
