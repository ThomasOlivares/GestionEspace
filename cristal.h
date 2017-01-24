#ifndef CRISTAL_H
#define CRISTAL_H

#include <iostream>
#include <string>
#include "batiment.h"

class Cristal : public Batiment
{
    public:
        Cristal();
        virtual ~Cristal();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();
        virtual int getProd();
        virtual int getConso();

    protected:
        int prodCristal;
        int consoEnergie;
};

#endif // CRISTAL_H
