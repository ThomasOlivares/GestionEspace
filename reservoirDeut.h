#ifndef RESERVOIR_DEUT_H
#define RESERVOIR_DEUT_H

#include <iostream>
#include <string>
#include "batiment.h"

class ReservoirDeut : public Batiment
{
    public:
        ReservoirDeut();
        virtual ~ReservoirDeut();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // RESERVOIR_DEUT_H
