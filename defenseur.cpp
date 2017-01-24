#include <iostream>
#include <string>
#include "defenseur.h"

using namespace std;

/* Vaisseau servant à transporter des missiles d'interception afin de defendre
la flotte de ceux-ci*/
Defenseur::Defenseur() : Vaisseau()
{
    metalUp = 30000;
    cristalUp = 10000;
    deuteriumUp = 2000;
}

Defenseur::~Defenseur(){
	
}

string Defenseur::getNom(){
    return "defenseur";
}

int Defenseur::getNum(){
	return 14;
}
