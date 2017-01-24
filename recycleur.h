#ifndef RECYCLEUR_H
#define RECYCLEUR_H

#include <string>
#include "vaisseau.h"

class Recycleur : public Vaisseau
{
    public :
        Recycleur();
        virtual ~Recycleur();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // RECYCLEUR_H
