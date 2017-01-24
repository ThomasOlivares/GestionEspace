#include <iostream>
#include <math.h>
#include "batiment.h"
#include "util.h"

using namespace std;

Batiment::Batiment():Construction(), niveau(0){
    type = "batiment";
}

Batiment::Batiment(Batiment* bat): Construction(bat), niveau(bat->getNiveau()){
    type = "batiment";
}

Batiment::~Batiment(){
}

void Batiment::Description(ostream &flux) const{
    flux << "Je suis un batiment de niveau " << niveau;
}

string Batiment::getNom(){
    return "batiment";
}

int Batiment::getNiveau(){
    return niveau;
}

void Batiment::construire(int tps){
    float uneHeure = pow(10,6)*3600;
    if (!enConstruction()){
        return;
    }
    temps-=(float)tps/uneHeure;
    if (temps <= 0){
        temps = 0;
        niveau++;
        refresh();
        setConstruction(0);
    }
}

void Batiment::cancelConstruction(){
    temps = 0;
    setConstruction(0);
}

void Batiment::levelUp(){
    if (enConstruction()){
        throw string("Batiment déjà en construction");
        return;
    }
    temps = (float)(metalUp + cristalUp)/5000*(2/(float)vitesse);
    setConstruction(1);
}

void Batiment::levelDown(){
    niveau--;
    refresh();
}

int Batiment::enConstruction(){
    return temps > 0;
}

void Batiment::setConstruction(int etat){
    cancel->setActif(etat);
    up->setActif(!etat);
    down->setActif(!etat);
}

// Fonctions virtuelles

int Batiment::getMetal(){return 0;}

int Batiment::getCristal(){return 0;}

int Batiment::getDeuterium(){return 0;}

int Batiment::getProd(){return 0;}

int Batiment::getConso(){return 0;}

void Batiment::refresh(){}

ostream& operator<<(ostream &flux, Batiment const& bat){
    bat.Description(flux);
    return flux;
}
