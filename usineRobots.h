#ifndef USINE_ROBOTS_H
#define USINE_ROBOTS_H

#include <iostream>
#include <string>
#include "batiment.h"

class UsineRobots : public Batiment
{
    public:
        UsineRobots();
        virtual ~UsineRobots();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();

    protected:
};

#endif // USINE_ROBOTS_H
