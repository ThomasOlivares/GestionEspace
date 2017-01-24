#ifndef TERRAFORMEUR_H
#define TERRAFORMEUR_H

#include <iostream>
#include <string>
#include "batiment.h"

class Terraformeur : public Batiment
{
    public:
        Terraformeur();
        virtual ~Terraformeur();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // TERRAFORMEUR_H
