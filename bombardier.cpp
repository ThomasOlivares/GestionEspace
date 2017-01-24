#include <iostream>
#include <string>
#include "bombardier.h"

using namespace std;

Bombardier::Bombardier() : Vaisseau()
{
    metalUp = 50000;
    cristalUp = 25000;
    deuteriumUp = 15000;
}

Bombardier::~Bombardier(){
	
}

string Bombardier::getNom(){
    return "bombardier";
}

int Bombardier::getNum(){
	return 5;
}
