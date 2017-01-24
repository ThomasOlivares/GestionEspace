#include <iostream>
#include <string>
#include "destroyeur.h"

using namespace std;

Destroyeur::Destroyeur() : Vaisseau()
{
    metalUp = 60000;
    cristalUp = 50000;
    deuteriumUp = 15000;
}

Destroyeur::~Destroyeur(){
	
}

string Destroyeur::getNom(){
    return "destructeur";
}

int Destroyeur::getNum(){
	return 6;
}
