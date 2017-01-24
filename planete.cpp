#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "planete.h"

using namespace std;

Planete::Planete(Planete* plan): Astre(plan->getPosX(), plan->getPosY(), plan->getNumJoueur()),
    nom(plan->getNom()){
    for (int i = 0; i< nbBatiments; i++){
        bat[i] = new Batiment(plan->getBatiment(i));
    }
    for (int i = 0; i<nbRecherches; i++){
        recherches[i] = new Recherche(plan->getRecherche(i));
    }
}

Planete::Planete(string nom, int posX, int posY): Astre(posX, posY), nom(nom),
        metal(metalStart), cristal(cristalStart), deuterium(deuteriumStart){
    initBatiment();
    initRecherche();
}

Planete::Planete(string nom, int posX, int posY, int numJoueur): Astre(posX, posY, numJoueur), nom(nom),
        metal(metalStart), cristal(cristalStart), deuterium(deuteriumStart){
    initBatiment();
    initRecherche();
}

Planete::~Planete(){
    for (int i = 0; i<nbBatiments; i++){
        delete(bat[i]);
    }
    for (int i = 0; i<nbRecherches; i++){
        delete(recherches[i]);
    }
}

void Planete::initBatiment(){
    bat[0] = new Metal();
    bat[1] = new Cristal();
    bat[2] = new Deuterium();
    bat[3] = new CentraleSolaire();
    bat[4] = new ChantierSpatial();
    bat[5] = new LaboRecherche();
    bat[6] = new HangarMetal();
    bat[7] = new HangarCristal();
    bat[8] = new ReservoirDeut();
    bat[9] = new UsineRobots();
    bat[10] = new Silo();
    bat[11] = new UsineNanites();
    bat[12] = new Terraformeur();
}

void Planete::initRecherche(){
    for (int i = 0; i<nbRecherches; i++){
        recherches[i] = new Recherche(i);
    }
}

string Planete::getNom(){
    return nom;
}

int Planete::getMetal(){
	return (int)metal;
}

int Planete::getCristal(){
	return (int)cristal;
}

int Planete::getDeuterium(){
	return (int)deuterium;
}

int Planete::getNiveau(Recherche* recherche){
    return recherche->getNiveau();
}

Vaisseau* Planete::getVaisseau(int i){
    return ((ChantierSpatial*)bat[4])->getVaisseau(i);
}

void Planete::removeVaisseau(int num, int nb){
    ((ChantierSpatial*)bat[4])->removeVaisseau(num, nb);
}

Recherche* Planete::getRecherche(int i){
    return recherches[i];
}

void Planete::setRecherche(int i, int valeur){
    recherches[i]->setNiveau(valeur);
}

int Planete::getNombre(Vaisseau* vaisseau){
    return ((ChantierSpatial*)bat[4])->getNombre(vaisseau);
}

int Planete::enConstruction(string type){
    if (type == "batiment"){
        for(int i = 0; i<nbBatiments; i++){
            if(bat[i]->enConstruction()){
                return 1;
            }
        }
    }
    else if (type == "vaisseau"){
        ChantierSpatial* chantier = (ChantierSpatial*)bat[4];
        if (chantier->enConstruction()){
            return 1;
        }
    }
    return 0;
}

int Planete::getProdMetal(){
    float prod = (float)(bat[0]->getProd())*getPourcentageProd()+30;
    return (int)prod;
}

int Planete::getProdCristal(){
    float prod = bat[1]->getProd()*getPourcentageProd()+15;
    return (int)prod;
}

int Planete::getProdDeuterium(){
    float prod = bat[2]->getProd()*getPourcentageProd();
    return (int)prod;
}

int Planete::getEnergie(){
    int energ = -getConsoTotale();
    energ+=bat[3]->getProd();
    return energ;
}

int Planete::getConsoTotale(){
    int energ = 0;
    for (int i = 0; i<3; i++){
        energ+=bat[i]->getConso();
    }
    return energ;
}

float Planete::getPourcentageProd(){
    int energieProd = bat[3]->getProd();
    if (energieProd == 0){
        return 0;
    }
    float pourcentage = 1+(float)getEnergie()/(float)getConsoTotale();
    if (pourcentage > 1){
        return 1;
    }
    return pourcentage;
}

void Planete::decrementerTimers(int tps){
    for (int i = 0; i<nbBatiments; i++){
        bat[i]->construire(tps);
    }
    ChantierSpatial* chantier = (ChantierSpatial*)bat[4];
    chantier->construire(tps);
    /*
    for (int i = 0; i<nbRecherches; i++){
        labo->getRecherche(i)->construire(tps);
    }
    */
}

void Planete::apply(string commande, Batiment* bat){
    if (bat->enConstruction() && commande == "cancel"){
        ajouter(bat->getMetal(), bat->getCristal(), bat->getDeuterium());
        bat->cancelConstruction();
    }
    else if(!enConstruction("batiment")){
        if (commande == "up"){
            if (enlever(bat->getMetal(), bat->getCristal(), bat->getDeuterium())){
                bat->levelUp();
            }
        }
        else if (commande == "down"){
            bat->levelDown();
        }
    }
}

void Planete::apply(string commande, Vaisseau* v){
    if(!enConstruction("batiment") && commande == "up"){
        if (enlever(v->getMetal(), v->getCristal(), v->getDeuterium())){
            ChantierSpatial* chantier = (ChantierSpatial*)getBatiment(4);
            chantier->addVaisseau(v);
        }
    }
}

void Planete::ajouter(int temps){
    long uneHeure = pow(10,6)*60*60/(float)vitesse;
    metal+= getProdMetal()*(float)temps/uneHeure;
    cristal+= getProdCristal()*(float)temps/uneHeure;
    deuterium+= getProdDeuterium()*(float)temps/uneHeure;
    energie = getEnergie();
    decrementerTimers(temps);

}

void Planete::ajouter(int m, int c, int d){
    metal+=m;
    cristal+=c;
    deuterium+=d;
}

int Planete::enlever(int m, int c, int d){
    if ((metal >= m) && (cristal >= c) && (deuterium >= d)){
        metal-=m;
        cristal-=c;
        deuterium-=d;
        return 1;
    }
    return 0;
}

int Planete::getNbCases(){
    return nbCases;
}

Batiment* Planete::getBatiment(int num){
    return bat[num];
}