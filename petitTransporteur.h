#ifndef PETIT_TRANSPORTEUR_H
#define PETIT_TRANSPORTEUR_H

#include <string>
#include "vaisseau.h"

class PetitTransporteur : public Vaisseau
{
    public :
        PetitTransporteur();
        virtual ~PetitTransporteur();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // PETIT_TRANSPORTEUR_H
