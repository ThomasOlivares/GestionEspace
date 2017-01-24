#ifndef DEFENSEUR_H
#define DEFENSEUR_H

#include <string>
#include "vaisseau.h"

class Defenseur : public Vaisseau
{
    public :
        Defenseur();
        virtual ~Defenseur();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // DEFENSEUR_H
