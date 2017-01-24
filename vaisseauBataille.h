#ifndef VAISSEAU_BATAILLE_H
#define VAISSEAU_BATAILLE_H

#include <string>
#include "vaisseau.h"

class VaisseauBataille : public Vaisseau
{
    public :
        VaisseauBataille();
        virtual ~VaisseauBataille();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // VAISSEAU_BATAILLE_H
