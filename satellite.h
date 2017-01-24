#ifndef SATELLITE_H
#define SATELLITE_H

#include <string>
#include "vaisseau.h"

class Satellite : public Vaisseau
{
    public :
        Satellite();
        virtual ~Satellite();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // SATELLITE_H
