#ifndef PLANETE_H
#define PLANETE_H

#include <string>
#include "astre.h"
#include "batiment.h"
#include "metal.h"
#include "cristal.h"
#include "deuterium.h"
#include "centraleSolaire.h"
#include "hangarMetal.h"
#include "hangarCristal.h"
#include "reservoirDeut.h"
#include "usineRobots.h"
#include "chantierSpatial.h"
#include "laboRecherche.h"
#include "silo.h"
#include "usineNanites.h"
#include "terraformeur.h"
#include "vaisseau.h"
#include "recherche.h"
#include "util.h"

class Planete: public Astre
{
    public:
        Planete(std::string nom, int posX, int posY);
        Planete(std::string nom, int posX, int posY, int numJoueur);
        Planete(Planete* plan);
        virtual ~Planete();

        void initBatiment();
        void initRecherche();

        std::string getNom();
        int getNbCases();
        int getMetal();
        int getCristal();
        int getDeuterium();
        int getProdMetal();
        int getProdCristal();
        int getProdDeuterium();
        int getNiveau(Recherche* recherche);
        Vaisseau* getVaisseau(int i);
        float getPourcentageProd();
        int getNombre(Vaisseau* vaisseau);
        int getConsoTotale();
        int enConstruction(std::string type);
        void decrementerTimers(int tps);
        void removeVaisseau(int num, int nb);

        void apply(std::string commande, Batiment* bat);
        void apply(std::string commande, Vaisseau* v);
        void ajouter(int temps);
        void ajouter(int m, int c, int d);
        int enlever(int m, int c, int d);
        Batiment* getBatiment(int num);
        Recherche* getRecherche(int i);
        void setRecherche(int i, int valeur);
        int getEnergie();

    protected:
        Recherche* recherches[nbRecherches];
        Batiment* bat[nbBatiments];
        std::string nom;
        int nbCases;
        double metal;
        double cristal;
        double deuterium;
        int energie;
};

#endif  //PLANETE_H
