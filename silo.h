#ifndef SILO_H
#define SILO_H

#include <iostream>
#include <string>
#include "batiment.h"

class Silo : public Batiment
{
    public:
        Silo();
        virtual ~Silo();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // SILO_H
