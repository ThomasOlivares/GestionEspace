#include <iostream>
#include <string>
#include "recycleur.h"

using namespace std;

Recycleur::Recycleur() : Vaisseau()
{
    metalUp = 10000;
    cristalUp = 6000;
    deuteriumUp = 2000;
}

Recycleur::~Recycleur(){
	
}

string Recycleur::getNom(){
    return "recycleur";
}

int Recycleur::getNum(){
	return 13;
}

