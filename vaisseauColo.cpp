#include <iostream>
#include <string>
#include "vaisseauColo.h"

using namespace std;

VaisseauColo::VaisseauColo() : Vaisseau()
{
    metalUp = 10000;
    cristalUp = 20000;
    deuteriumUp = 10000;
}

VaisseauColo::~VaisseauColo(){
	
}

string VaisseauColo::getNom(){
    return "vaisseau de colonisation";
}

int VaisseauColo::getNum(){
	return 12;
}
