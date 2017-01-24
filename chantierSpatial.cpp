#include <iostream>
#include <math.h>
#include "chantierSpatial.h"
#include "chasseurLeger.h"
#include "chasseurLourd.h"
#include "croiseur.h"
#include "vaisseauBataille.h"
#include "traqueur.h"
#include "bombardier.h"
#include "destructeur.h"
#include "etoileDeLaMort.h"
#include "petitTransporteur.h"
#include "grandTransporteur.h"
#include "satellite.h"
#include "sonde.h"
#include "vaisseauColo.h"
#include "recycleur.h"

using namespace std;

ChantierSpatial::ChantierSpatial():Batiment(){
	refresh();
	for(int i = 0; i<nbVaisseaux; i++){
		flotte[i] = 20;
	}
	liste[0] = new ChasseurLeger();
	liste[1] = new ChasseurLourd();
	liste[2] = new Croiseur();
	liste[3] = new VaisseauBataille();
	liste[4] = new Traqueur();
	liste[5] = new Bombardier();
	liste[6] = new Destructeur();
	liste[7] = new EtoileDeLaMort();
	liste[8] = new PetitTransporteur();
	liste[9] = new GrandTransporteur();
	liste[10] = new Satellite();
	liste[11] = new Sonde();
	liste[12] = new VaisseauColo();
	liste[13] = new Recycleur();
}

ChantierSpatial::~ChantierSpatial(){
	for (int i = 0; i< nbVaisseaux; i++){
		delete(liste[i]);
	}
	delete(self);
}

void ChantierSpatial::Description(ostream &flux) const{
    flux << "chantier spatial";
}

void ChantierSpatial::refresh(){
    metalUp = 400*pow(2, niveau);
    cristalUp = 200*pow(2, niveau);
    deuteriumUp = 100*pow(2, niveau);
}

string ChantierSpatial::getNom(){
    return "chantier spatial";
}

int ChantierSpatial::enConstruction(){
	for (int i = 0; i<nbVaisseaux; i++){
		if (getVaisseau(i)->getTemps() > 0){
			return 1;
		}
	}
	return 0;
}

int ChantierSpatial::vtoi(Vaisseau* vaisseau){
	return vaisseau->getNum();
}

int ChantierSpatial::getNombre(Vaisseau* vaisseau){
	int num = vtoi(vaisseau);
	return flotte[num];
}

Vaisseau* ChantierSpatial::getVaisseau(int i){
	if (i < 0 || i > 13){
		cout << "chantierSpatial::getVaisseau" << endl;
		throw "error";
	}
	return liste[i];
}

void ChantierSpatial::construire(int tps, int num){
	Vaisseau* v = liste[num];
	if (v->getTemps() == 0){
		return;
	}
    float uneHeure = pow(10,6)*3600;
    v->setTemps(v->getTemps() - (float)tps/uneHeure);
    if (v->getTemps() <= 0){
        v->setTemps(0);
        addVaisseau(v);
    }
}

void ChantierSpatial::addVaisseau(Vaisseau* vaisseau){
	flotte[vtoi(vaisseau)]++;
}

void ChantierSpatial::removeVaisseau(int num, int nb){
	flotte[num]-=nb;
}
