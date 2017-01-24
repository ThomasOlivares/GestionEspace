#include "data.h"

using namespace std;

Data::Data(){
    joueurs[0] = new Joueur("Bob", "joueur");
    joueurs[1] = new Joueur("Jackie", "ia");
    joueurs[2] = new Joueur("Michel", "ia");
    joueurs[3] = new Joueur("Marcel", "ia");
    
    planetes[0] = new Planete("Yavin4", 100, 100);
    planetes[1] = new Planete("Coruscant", 100, 400);
    planetes[2] = new Planete("Alderaan", 400, 100);
    planetes[3] = new Planete("Mustafar", 400, 400);

    loadData();
}

Data::~Data(){
    for (int i = 0; i<nbPlanetes; i++){
        delete(planetes[i]);
    }
    
    for (int i = 0; i<nbJoueurs; i++){
        delete(joueurs[i]);
    }
}

// attribut automatiquement les planètes aux joueurs
void Data::loadData(){
    for(int i = 0; i<nbPlanetes; i++){
        planetes[i]->setNumJoueur(i);
        joueurs[i]->addPlanete(planetes[i]);
    }

}

Planete* Data::getPlanete(int i){
    return planetes[i];
}

Joueur* Data::getJoueur(int i){
    return joueurs[i];
}

// actualise les ressources de toutes les planètes
void Data::addProd(long diff){
    for (int i = 0; i<nbPlanetes; i++){
        Planete* actuelle = getPlanete(i);
        // On transmet le temps à la planete afin qu'elle actualise ses ressources
        actuelle->ajouter(diff);
    }
}