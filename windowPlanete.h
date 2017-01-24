#ifndef WINDOW_PLANETE_H
#define WINDOW_PLANETE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "joueur.h"
#include "planete.h"
#include "util.h"
#include "bouton.h"
#include "textArea.h"
#include "flotte.h"

class WindowPlanete: public sf::RenderWindow
{
    public:
        WindowPlanete(sf::VideoMode mode, const std::string &title);
        WindowPlanete(Planete* planete, sf::VideoMode mode, const std::string &title);
        virtual ~WindowPlanete();
        
        void init();

        void setVue(std::string nvVue);
        std::string getVue();
        Planete* getPlanete();
        void setBoutonCancel(Recherche* recherche);
        void setPlanete(Planete* plan);
        int isVisible();
        void setVisible(int visib);
        Flotte* getFlotte();
        void resetFlotte();
        void affecter(Planete* plan, Joueur* j);

        void loadContenu();

        
        void initTextes();
        
        void initTexture();
        void initTexte();

        void checkEvent();
        void checkEventBatiments(sf::Event &event);
        void checkEventVaisseaux(sf::Event &event);
        void checkEventRecherche(sf::Event &event);
        void checkEventFlotte(sf::Event &event);

        void setTextPlanete();
        void setTextRessources();
        void setMenu(int &posY, int increment);
        void setText(Batiment* actuel, int &posY, int increment);
        void setText(Recherche* actuelle, int &posY, int increment);
        void setText(Vaisseau* actuel, int &posY, int increment);
        void setText(Vaisseau* actuel, int &posY, int increment, int num);
        void setBoutonCancel(Batiment* actuel);
        void setBoutonConstruire(Batiment* actuel);
        void setBoutonConstruire(Vaisseau* actuel);
        void setBoutonConstruire(Recherche* actuelle);
        
        void setBoutonEnvoi(int &posY, int increment);
        Flotte* envoyerFlotte();
        int isVaisseau();

        void setBouton(int x1, int y1, int increment);
        void isClicked(int x, int y);

    protected:
        int posX;
        int posY;
        Joueur* joueur;
        Planete* planete;
        int visible;
        std::string vue;

        Bouton* batiments;
        Bouton* vaisseaux;
        Bouton* recherche;
        Bouton* flotte;
        Bouton* envoi;

        sf::Sprite* sprite;
        sf::Text* text;
        sf::Texture* texture;
        sf::Font* font;
        TextArea* champsTexte[nbVaisseaux];

        Flotte* nouvelle;
};

std::ostream& operator<<(std::ostream &flux, Batiment const& bat);

#endif  //WINDOW_PLANETE_H
