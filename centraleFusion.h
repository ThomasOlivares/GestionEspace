#ifndef CENTRALE_FUSION_H
#define CENTRALE_FUSION_H

#include <iostream>
#include <string>
#include "batiment.h"

class CentraleFusion : public Batiment
{
    public:
        CentraleFusion();
        virtual ~CentraleFusion();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // CENTRALE_FUSION_H
