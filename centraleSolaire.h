#ifndef CENTRALE_SOLAIRE_H
#define CENTRALE_SOLAIRE_H

#include <iostream>
#include <string>
#include "batiment.h"

class CentraleSolaire : public Batiment
{
    public:
        CentraleSolaire();
        virtual ~CentraleSolaire();

        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();
        virtual int getProd();

    protected:
        int prodEnergie;
};

#endif // CENTRALE_SOLAIRE_H
