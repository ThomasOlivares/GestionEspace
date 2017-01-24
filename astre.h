#ifndef ASTRE_H
#define ASTRE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "util.h"

class Astre
{
    public:
        Astre(int posX, int posY);
        Astre(int posX, int posY, int numJoueur);
        virtual ~Astre();

        double getPosX();
        void setPosX(double x);
        double getPosY();
        void setPosY(double y);
        int getNumJoueur();
        void setNumJoueur(int nouveau);
        double getDistance(int x, int y);
        double getDistance(double x, double y);
        double getDistance(Astre* autre);
        sf::CircleShape* getShape();
        void setShape(sf::CircleShape* nouvelle);

    protected:
        sf::CircleShape* shape;
        double posX;
        double posY;
        int numJoueur;
        
};

#endif  //ASTRE_H
