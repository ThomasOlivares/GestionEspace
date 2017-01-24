#ifndef DESRUCTEUR_H
#define DESRUCTEUR_H

#include <string>
#include "vaisseau.h"

class Destructeur : public Vaisseau
{
    public :
        Destructeur();
        virtual ~Destructeur();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // DESRUCTEUR_H
