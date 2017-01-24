#ifndef SONDE_H
#define SONDE_H

#include <string>
#include "vaisseau.h"

class Sonde : public Vaisseau
{
    public :
        Sonde();
        virtual ~Sonde();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // SONDE_H
