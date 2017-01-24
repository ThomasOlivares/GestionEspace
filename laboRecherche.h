#ifndef LABO_RECHERCHE_H
#define LABO_RECHERCHE_H

#include <iostream>
#include <string>
#include "batiment.h"
#include "recherche.h"

class LaboRecherche : public Batiment
{
    public:
        LaboRecherche();
        virtual ~LaboRecherche();
        
        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        virtual void refresh();
        

    protected:
    	
};

#endif // LABO_RECHERCHE_H
