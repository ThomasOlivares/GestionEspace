#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "joueur.h"

using namespace std;

int Joueur::compteur = 1;
sf::Color Joueur::couleurs[4] = {sf::Color(50, 100, 250), sf::Color(250, 100, 250),
            sf::Color(250, 100, 50), sf::Color(50, 250, 100)};


Joueur::Joueur(string name, string type):name(name), type(type)
{
    if (compteur == 1){
        couleurs[0] = sf::Color(50, 100, 250);
        couleurs[1] = sf::Color(250, 100, 250);
        couleurs[2] = sf::Color(250, 100, 50);
        couleurs[3] = sf::Color(50, 250, 100);
    }
    couleur = couleurs[compteur%4];
    numero = compteur++;

    for (int i = 0; i<nbRecherches; i++){
        recherches[i] = new Recherche(i);
    }
    recherches[0]->setNom("energie");
    recherches[1]->setNom("laser");
    recherches[2]->setNom("ion");
    recherches[3]->setNom("hyperespace");
    recherches[4]->setNom("plasma");
    recherches[5]->setNom("combustion");
    recherches[6]->setNom("impulsion");
    recherches[7]->setNom("propulsion hyperespace");
    recherches[8]->setNom("espionnage");
    recherches[9]->setNom("ordinateur");
    recherches[10]->setNom("astrophysique");
    recherches[11]->setNom("reseau de recherche");
    recherches[12]->setNom("graviton");
    recherches[13]->setNom("arme");
    recherches[14]->setNom("bouclier");
    recherches[15]->setNom("protection");
}

Joueur::~Joueur(){
    delete(&planetes);
    delete(&flottes);
    delete(&astres);
    for (int i = 0; i<nbRecherches; i++){
        delete(recherches[i]);
    }
}

Recherche* Joueur::getRecherche(string nom){
    for (int i = 0; i<nbRecherches; i++){
        if(recherches[i]->getNom() == nom){
            return recherches[i];
        }
    }
}

Recherche* Joueur::getRecherche(int num){
    return recherches[num];
}

int Joueur::enRecherche(){
    for (int i = 0; i<nbRecherches; i++){
        if (recherches[i]->getTemps() > 0){
            return 1;
        }
    }
    return 0;
}

string Joueur::getType(){
    return type;
}

string Joueur::getNom(){
    return name;
}

sf::Color Joueur::getCouleur(){
    return couleur;
}

int Joueur::getNumero(){
    return numero;
}

void Joueur::addPlanete(Planete* planete){
    planetes.push_back(planete);
}

vector<Planete*> Joueur::getPlanete(){
    return planetes;
}

void Joueur::addFlotte(Flotte* flotte){
    flottes.push_back(flotte);
}

vector<Flotte*> Joueur::getFlottes(){
    return flottes;
}

Flotte* Joueur::getFlotte(int i){
    return flottes[i];
}

vector<Astre*> Joueur::getAstres(){
    return astres;
}

Astre* Joueur::getAstre(int i){
    return astres[i];
}

void Joueur::addAstre(Astre* astre){
    for (int i = 0; i<astres.size(); i++){
        if (astres[i]->getPosX() == astre->getPosX() &&
                astres[i]->getPosY() == astre->getPosY()){
            Astre* temp = astres[i];
            astres[i] = astre;
            delete(temp);
            return;
        }
    }
    astres.push_back(astre);
}

void Joueur::apply(string commande, Recherche* r, Planete* plan){
    if(!enRecherche() && commande == "up"){
        if (plan->enlever(r->getMetal(), r->getCristal(), r->getDeuterium())){
            r->levelUp();
        }
    }
}
