#ifndef DATA_H
#define DATA_H

#include "joueur.h"
#include "planete.h"
#include "util.h"

class Data
{
    public:
        Data();
        virtual ~Data();

        void loadData();
        void addProd(long diff);
        Planete* getPlanete(int i);
        Joueur* getJoueur(int i);
        Joueur* getJoueurActuel();

    protected:
        Joueur* joueurs[nbJoueurs];
        Planete* planetes[nbPlanetes];
};

#endif   //DATA_H