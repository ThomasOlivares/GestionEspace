#ifndef JOUEUR_H
#define JOUEUR_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "recherche.h"
#include "astre.h"
#include "vaisseau.h"
#include "flotte.h"
#include "planete.h"

class Joueur
{
    public:
        Joueur(std::string name, std::string type);
        virtual ~Joueur();
        
        std::string getNom();
        std::string getType();
        int getNumero();
        void addPlanete(Planete* planete);
        std::vector<Planete*> getPlanete();
        void addFlotte(Flotte* flotte);
        std::vector<Flotte*> getFlottes();
        Flotte* getFlotte(int i);
        sf::Color getCouleur();
        std::vector<Astre*> getAstres();
        Astre* getAstre(int i);
        void addAstre(Astre* astre);

        Recherche* getRecherche(std::string nom);
        Recherche* getRecherche(int num);
        int enRecherche();

        void apply(std::string commande, Recherche* r, Planete* plan);

    protected:
        static sf::Color couleurs[];
        static int compteur;
        std::vector<Planete*> planetes;
        std::vector<Flotte*> flottes;
        std::string name;
        std::string type;
        int numero;
        std::vector<Astre*> astres;
        sf::Color couleur;
        Recherche* recherches[nbRecherches];
};

#endif  // JOUEUR_H
