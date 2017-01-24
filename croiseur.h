#ifndef CROISEUR_H
#define CROISEUR_H

#include <string>
#include "vaisseau.h"

class Croiseur : public Vaisseau
{
    public :
        Croiseur();
        virtual ~Croiseur();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // CROISEUR_H
