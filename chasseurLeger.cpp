#include <iostream>
#include <string>
#include "chasseurLeger.h"

using namespace std;

ChasseurLeger::ChasseurLeger() : Vaisseau()
{
    metalUp = 3000;
    cristalUp = 1000;
    deuteriumUp = 0;
}

ChasseurLeger::~ChasseurLeger(){
	
}

string ChasseurLeger::getNom(){
    return "chasseur leger";
}

int ChasseurLeger::getNum(){
	return 0;
}
