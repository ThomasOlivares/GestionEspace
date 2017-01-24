#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <string>
#include "construction.h"
#include "util.h"
#include <cmath>

class Joueur;
class Vaisseau: public Construction
{
    public :
        Vaisseau();
        virtual ~Vaisseau();
        
        virtual std::string getNom();
        virtual int getNum();
        int getCoutMetal();
        int getCoutCristal();
        int getCoutDeuterium();
        void setBouton(int x1, int y1);
        void ajouter();

    protected:
};

#endif  // VAISSEAU.H
