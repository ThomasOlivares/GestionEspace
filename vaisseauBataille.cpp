#include <iostream>
#include <string>
#include "vaisseauBataille.h"

using namespace std;

VaisseauBataille::VaisseauBataille() : Vaisseau()
{
    metalUp = 45000;
    cristalUp = 15000;
    deuteriumUp = 0;
}

VaisseauBataille::~VaisseauBataille(){
	
}

string VaisseauBataille::getNom(){
    return "vaisseau de bataille";
}

int VaisseauBataille::getNum(){
	return 3;
}
