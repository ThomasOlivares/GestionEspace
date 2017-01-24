#include <iostream>
#include <string>
#include "etoileDeLaMort.h"

using namespace std;

EtoileDeLaMort::EtoileDeLaMort() : Vaisseau()
{
    metalUp = 5000000;
    cristalUp = 3000000;
    deuteriumUp = 1000000;
}

EtoileDeLaMort::~EtoileDeLaMort(){
	
}

string EtoileDeLaMort::getNom(){
    return "etoile de la mort";
}

int EtoileDeLaMort::getNum(){
	return 7;
}
