#ifndef HANGAR_CRISTAL_H
#define HANGAR_CRISTAL_H

#include <iostream>
#include <string>
#include "batiment.h"

class HangarCristal : public Batiment
{
    public:
        HangarCristal();
        virtual ~HangarCristal();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // HANGAR_CRISTAL_H
