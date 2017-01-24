#ifndef BATIMENT_H
#define BATIMENT_H

#include <string>
#include "bouton.h"
#include "construction.h"

class Batiment: public Construction
{
    public:
        Batiment();
        Batiment(Batiment* bat);
        virtual ~Batiment();

        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        void levelUp();
        void levelDown();
        int enConstruction();
        void cancelConstruction();
        void setConstruction(int etat);
        int getNiveau();
        virtual int getProd();
        virtual int getConso();
        void construire(int tps);
        virtual int getMetal();   // Cout en metal/cristal/deut du batiment
        virtual int getCristal();
        virtual int getDeuterium();
        virtual void refresh();

    protected:
        int niveau;
};

std::ostream& operator<<(std::ostream &flux, Batiment const& bat);

#endif
