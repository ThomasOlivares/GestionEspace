#ifndef VAISSEAU_COLO_H
#define VAISSEAU_COLO_H

#include <string>
#include "vaisseau.h"

class VaisseauColo : public Vaisseau
{
    public :
        VaisseauColo();
        virtual ~VaisseauColo();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // VAISSEAU_COLO_H
