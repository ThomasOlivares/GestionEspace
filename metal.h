#ifndef METAL_H
#define METAL_H

#include <iostream>
#include <string>
#include "batiment.h"

class Metal : public Batiment
{
    public:
        Metal();
        virtual ~Metal();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();
        virtual int getProd();
        virtual int getConso();

    protected:
        int prodMetal;
        int consoEnergie;
};

#endif // METAL_H
