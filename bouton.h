#ifndef BOUTON_H
#define BOUTON_H

#include <string>

class Bouton
{
    public:
        Bouton();
        Bouton(std::string symbole, std::string action, int posX, int posY, int largeur, int longueur);
        Bouton(Bouton* b);
        virtual ~Bouton();
        
        int getActif();
        void setActif(int act);
        int getClicked(int x, int y);
        std::string getSymbole();
        std::string getAction();
        int getPosX();
        int getPosY();
        int getLargeur();
        int getLongueur();

    protected:
        int actif;
        std::string symbole;
        int posX;
        int posY;
        int largeur;
        int longueur;
        std::string action;
};

#endif  //BOUTON_H
