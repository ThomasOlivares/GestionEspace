#ifndef CHANTIER_SPATIAL_H
#define CHANTIER_SPATIAL_H

#include <iostream>
#include <string>
#include <vector>
#include "batiment.h"
#include "vaisseau.h"
#include "util.h"

class Vaisseau;
class ChantierSpatial : public Batiment
{
    public:
        ChantierSpatial();
        virtual ~ChantierSpatial();

        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        void addVaisseau(Vaisseau* vaisseau);
        void removeVaisseau(int num, int nb);
        Vaisseau* getVaisseau(int i);
        int enConstruction();
        void construction();
        virtual void refresh();
        int vtoi(Vaisseau* vaisseau);
        int getNombre(Vaisseau* vaisseau);
        void construire(int tps);

    protected:
    	Vaisseau* liste[nbVaisseaux];
    	int flotte[nbVaisseaux];
    	Bouton* self;
        std::vector<Vaisseau*> commande;
};

#endif // CHANTIER_SPATIAL_H
