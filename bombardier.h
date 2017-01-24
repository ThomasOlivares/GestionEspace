#ifndef BOMBARDIER_H
#define BOMBARDIER_H

#include <string>
#include "vaisseau.h"

class Bombardier : public Vaisseau
{
    public :
        Bombardier();
        virtual ~Bombardier();
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // BOMBARDIER_H
