#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <string>
#include "bouton.h"
#include "util.h"

class Construction
{
    public:
        Construction();
        Construction(Construction* constr);
        virtual ~Construction();

        virtual void Description(std::ostream &flux) const;
        virtual std::string getNom();
        int enConstruction();
        virtual int getMetal();   // Cout en metal/cristal/deut de la construction
        virtual int getCristal();
        virtual int getDeuterium();
        int getTemps();
        float getTempsHeure();
        void setTemps(float nv);
        void setBouton(int x, int y);
        virtual std::string getType();
        Bouton* getBoutonUp();
        Bouton* getBoutonDown();
        Bouton* getBoutonCancel();
        std::string isClicked(int x, int y);
        virtual void refresh();

    protected:
        std::string type;
        int metalUp;
        int cristalUp;
        int deuteriumUp;
        float temps;
        Bouton* up;
        Bouton* down;
        Bouton* cancel;
};

std::ostream& operator<<(std::ostream &flux, Construction const& c);

#endif  //CONSTRUCTION_H
