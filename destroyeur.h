#ifndef DESTROYEUR_H
#define DESTROYEUR_H

#include <string>
#include "vaisseau.h"

class Destroyeur : public Vaisseau
{
    public :
        Destroyeur();
        virtual ~Destroyeur();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // DESTROYEUR_H
