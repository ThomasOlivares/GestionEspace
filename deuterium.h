#ifndef DEUTERIUM_H
#define DEUTERIUM_H

#include <iostream>
#include <string>
#include "batiment.h"

class Deuterium : public Batiment
{
    public:
        Deuterium();
        virtual ~Deuterium();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();
        virtual int getProd();
        virtual int getConso();

    protected:
        int prodDeut;
        int consoEnergie;
};

#endif // DEUTERIUM_H