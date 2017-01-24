#ifndef CHASSEURLOURD_H
#define CHASSEURLOURD_H

#include <string>
#include "vaisseau.h"

class ChasseurLourd : public Vaisseau
{
    public :
        ChasseurLourd();
        virtual ~ChasseurLourd();
        
        virtual std::string getNom();
        virtual int getNum();

    protected:
};

#endif // CHASSEURLOURD_H
