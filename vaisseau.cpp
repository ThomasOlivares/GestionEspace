#include "vaisseau.h"

#include <iostream>
#include <string>

using namespace std;

Vaisseau::Vaisseau() :Construction()
{
    type = "vaisseau";
}

Vaisseau::~Vaisseau(){
    
}

string Vaisseau::getNom(){
    return "vaisseau";
}

int Vaisseau::getNum(){
    cout << "Vaisseau::getNum()" << endl;
    throw "not supposed to be called";
}

int Vaisseau::getCoutMetal(){
    return metalUp;
}

int Vaisseau::getCoutCristal(){
    return cristalUp;
}

int Vaisseau::getCoutDeuterium(){
    return deuteriumUp;
}

void Vaisseau::setBouton(int x1, int y1){
    int cote = 16;
    int x = x1;
    int y = y1;
    up = new Bouton("+", "up", x, y, cote, cote);
}

void Vaisseau::ajouter(){
    temps = (float)(metalUp + cristalUp)/5000*(2/(float)vitesse);
}