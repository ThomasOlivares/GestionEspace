#ifndef HANGAR_METAL_H
#define HANGAR_METAL_H

#include <iostream>
#include <string>
#include "batiment.h"

class HangarMetal : public Batiment
{
    public:
        HangarMetal();
        virtual ~HangarMetal();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // HANGAR_METAL_H
