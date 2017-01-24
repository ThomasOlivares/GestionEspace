#ifndef ETOILE_DE_LA_MORT_H
#define ETOILE_DE_LA_MORT_H

#include <string>
#include "vaisseau.h"

class EtoileDeLaMort : public Vaisseau
{
    public :
        EtoileDeLaMort();
        virtual ~EtoileDeLaMort();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // ETOILE_DE_LA_MORT_H
