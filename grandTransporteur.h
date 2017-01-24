#ifndef GRAND_TRANSPORTEUR_H
#define GRAND_TRANSPORTEUR_H

#include <string>
#include "vaisseau.h"

class GrandTransporteur : public Vaisseau
{
    public :
        GrandTransporteur();
        virtual ~GrandTransporteur();

        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // GRAND_TRANSPORTEUR_H
