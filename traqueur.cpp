#include <iostream>
#include <string>
#include "traqueur.h"

using namespace std;

Traqueur::Traqueur() : Vaisseau()
{
    metalUp = 30000;
    cristalUp = 40000;
    deuteriumUp = 15000;
}

Traqueur::~Traqueur(){
	
}

string Traqueur::getNom(){
    return "traqueur";
}

int Traqueur::getNum(){
	return 4;
}
