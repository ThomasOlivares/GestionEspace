#ifndef CHASSEURLEGER_H
#define CHASSEURLEGER_H

#include <string>
#include "vaisseau.h"

class ChasseurLeger : public Vaisseau
{
    public :
        ChasseurLeger();
        virtual ~ChasseurLeger();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // CHASSEURLEGER_H
