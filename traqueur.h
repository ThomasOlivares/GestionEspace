#ifndef TRAQUEUR_H
#define TRAQUEUR_H

#include <string>
#include "vaisseau.h"

class Traqueur : public Vaisseau
{
    public :
        Traqueur();
        virtual ~Traqueur();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // TRAQUEUR_H
