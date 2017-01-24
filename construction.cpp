#include <iostream>
#include <math.h>
#include "batiment.h"

using namespace std;

Construction::Construction(): temps(0), type("construction"),
        metalUp(0), cristalUp(0), deuteriumUp(0){
    up = new Bouton();
    down = new Bouton();
    cancel = new Bouton();
}

Construction::Construction(Construction* constr){
    type = constr->getType();
    metalUp = constr->getCristal();
    deuteriumUp = constr->getDeuterium();
    temps = constr->getTemps();
    up = new Bouton(constr->getBoutonUp());
    down = new Bouton(constr->getBoutonDown());
    cancel = new Bouton(constr->getBoutonCancel());
}

Construction::~Construction(){
    delete(up);
    delete(down);
    delete(cancel);
}

void Construction::Description(ostream &flux) const{
    flux << "Je suis une construction";
}

string Construction::getNom(){
    return "construction";
}

int Construction::getTemps(){
    return ceil(temps*3600);
}

float Construction::getTempsHeure(){
    return temps;
}

void Construction::setTemps(float nv){
    temps = nv;
}

void Construction::setBouton(int x1, int y1){
    int cote = 16;
    int x = x1;
    int y = y1;
    up = new Bouton("+", "up", x, y, cote, cote);
    down = new Bouton("-", "down", x + 1.5*cote, y, cote, cote);
    cancel = new Bouton("Annuler", "cancel", x, y, 50, cote);
}

string Construction::getType(){
    return type;
}

int Construction::enConstruction(){
    return temps > 0;
}

Bouton* Construction::getBoutonUp(){
    return up;
}

Bouton* Construction::getBoutonDown(){
    return down;
}

Bouton* Construction::getBoutonCancel(){
    return cancel;
}

// Fonctions virtuelles

int Construction::getMetal(){return 0;}

int Construction::getCristal(){return 0;}

int Construction::getDeuterium(){return 0;}

void Construction::refresh(){}

string Construction::isClicked(int x, int y){
    string etat = "";
    if (cancel->getClicked(x, y)){
        etat = "cancel";
    }
    if(up->getClicked(x, y)){
        etat = "up";
    }
    if(down->getClicked(x, y)){
        etat = "down";
    }
    return etat;
}

// Fin de la classe

ostream& operator<<(ostream &flux, Construction const& c){
    c.Description(flux);
    return flux;
}
