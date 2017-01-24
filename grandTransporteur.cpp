#include <iostream>
#include <string>
#include "grandTransporteur.h"

using namespace std;

GrandTransporteur::GrandTransporteur() : Vaisseau()
{
    metalUp = 6000;
    cristalUp = 6000;
    deuteriumUp = 0;
}

GrandTransporteur::~GrandTransporteur(){
	
}

string GrandTransporteur::getNom(){
    return "grand transporteur";
}

int GrandTransporteur::getNum(){
	return 9;
}
