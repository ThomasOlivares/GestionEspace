#ifndef USINE_NANITES_H
#define USINE_NANITES_H

#include <iostream>
#include <string>
#include "batiment.h"

class UsineNanites : public Batiment
{
    public:
        UsineNanites();
        virtual ~UsineNanites();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // USINE_NANITES_H
