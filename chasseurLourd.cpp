#include <iostream>
#include <string>
#include "chasseurLourd.h"


using namespace std;

ChasseurLourd::ChasseurLourd() : Vaisseau()
{
    metalUp = 6000;
    cristalUp = 4000;
    deuteriumUp = 0;
}

ChasseurLourd::~ChasseurLourd(){
	
}

string ChasseurLourd::getNom(){
    return "chasseur lourd";
}

int ChasseurLourd::getNum(){
	return 1;
}
