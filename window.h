#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "astre.h"
#include "windowPlanete.h"
#include "construction.h"
#include "batiment.h"
#include "planete.h"
#include "bouton.h"
#include "joueur.h"
#include "util.h"
#include "data.h"

class Window: public sf::RenderWindow
{
    public:
        Window(sf::VideoMode mode, const std::string &title);
        virtual ~Window();
        
        sf::Sprite* getSprite();
        int getXSouris();
        int getYSouris();
        void setPosSouris(int x, int y);
        void initTexture();
        void nouvelleFlotte(Flotte* flotte);
        Flotte* getFlottes(int num);
        int getNbFlottes();
        void afficher(Planete* planete);
        void afficher(Flotte* flotte, int num);
        Flotte* getFlotteActuelle();
        void setFlotteActuelle(Flotte* flotte);
        void moveFlotte(int diff);
        void revelerCercle(Joueur* joueur, int x, int y, int rayon);
        void dessinerEspace();
        Data* getData();
        void addProd(int diff);
        void handleEvent(WindowPlanete* windowPlanete);
        Planete* getPlanete(int i);

    protected:
        Data* data;
        int xSouris;
        int ySouris;
        Flotte* flotteChangee;
        sf::Text* text;
        sf::Sprite* sprite;
        sf::Texture* texture;
};

#endif   //WINDOW_H