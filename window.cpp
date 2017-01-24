#include "window.h"

using namespace std;

Window::Window(sf::VideoMode mode, const string &title): sf::RenderWindow(mode, title),
     flotteChangee(0)
{
    sprite = new sf::Sprite();
    text = new sf::Text();
    texture = new sf::Texture();
    data = new Data();
}

Window::~Window(){
    delete(data);
    delete(sprite);
    delete(text);
    delete(texture);
}

void Window::initTexture(){
    if (!texture->loadFromFile("fond.jpeg"))
    {
        cout << "erreur de texture" << endl;
    }
    sprite->setTexture(*texture);
}

sf::Sprite* Window::getSprite(){
    return sprite;
}

void Window::setPosSouris(int x, int y){
    xSouris = x;
    ySouris = y;
}

int Window::getXSouris(){
    return xSouris;
}

int Window::getYSouris(){
    return ySouris;
}

Flotte* Window::getFlotteActuelle(){
    return flotteChangee;
}

void Window::setFlotteActuelle(Flotte* flotte){
    flotteChangee = flotte;
}

Data* Window::getData(){
    return data;
}

Planete* Window::getPlanete(int i){
    return data->getPlanete(i);
}

void Window::handleEvent(WindowPlanete* windowPlanete){
    sf::Event event;
    while (pollEvent(event))
    {
        switch (event.type){
            case sf::Event::Closed:
                close();
                break;
            case sf::Event::MouseMoved:
                setPosSouris(event.mouseMove.x, event.mouseMove.y);
                break;
            case sf::Event::MouseButtonReleased:
                // On change la trajectoire d'une flotte
                if (event.mouseButton.button == sf::Mouse::Left && getFlotteActuelle() != 0){
                    Flotte* actuelle = getFlotteActuelle();
                    float angle = getAngleDegre(actuelle->getPosX(), 
                        actuelle->getPosY(), getXSouris(), getYSouris());
                    actuelle->setAngle(angle);
                    actuelle->setObjX(getXSouris());
                    actuelle->setObjY(getYSouris());
                    setFlotteActuelle(0);
                    actuelle->setEnvoye(1);
                }

                // On consulte les caractéristiques d'une planète
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    //indique si on a déjà trouver l'objet cliquer (les vaisseaux sont prioritaires)
                    int distanceSelect = 20;
                    for (int i = 0; i<nbJoueurs; i++){
                        Joueur* joueur = data->getJoueur(i);
                        for (int j = 0; j<joueur->getFlottes().size(); j++){
                            Flotte* flotte = joueur->getFlotte(j);
                            int dist = flotte->getDistance(event.mouseButton.x, event.mouseButton.y);
                            if (dist<20 && dist<distanceSelect){
                                setFlotteActuelle(flotte);
                                distanceSelect = dist;
                            }
                        }
                    }
                    Flotte* actuelle = getFlotteActuelle();
                    if(actuelle){
                        actuelle->setEnvoye(0);
                    }
                    // Si pas de vaisseau selectionner -> on cherche dans les planètes
                    if (distanceSelect == 20){
                        for (int i = 0; i<nbPlanetes; i++){
                            Planete* plan = data->getPlanete(i);
                            if (plan->getDistance(event.mouseButton.x, event.mouseButton.y)<50){
                                Planete* plan = data->getPlanete(i);
                                Joueur* joueur = data->getJoueur(plan->getNumJoueur());
                                windowPlanete->affecter(plan, joueur);
                            }
                        }
                    }
                }
                break;
        }
    }
}



void Window::moveFlotte(int diff){
    for (int i = 0; i< nbJoueurs; i++){
        Joueur* joueur = data->getJoueur(i);
        for (int j = 0; j<joueur->getFlottes().size(); j++){
            Flotte* flotte = joueur->getFlotte(j);
            flotte->avancer(diff);
        }
    }
}

void Window::nouvelleFlotte(Flotte* flotte){
    int num = flotte->getNumJoueur();
    data->getJoueur(num)->addFlotte(flotte);
    flotteChangee = flotte;
}

void Window::revelerCercle(Joueur* joueur, int x, int y, int rayon){
    sf::CircleShape* vision = new sf::CircleShape(rayon);
    vision->setPosition(x, y);
    float largeur = vision->getGlobalBounds().width;
    float hauteur = vision->getGlobalBounds().height;
    vision->setOrigin(largeur/2, hauteur/2);
    vision->setTexture(texture);
    vision->setTextureRect(sf::IntRect(x, y, largeur, hauteur));
    draw(*vision);
    for (int i = 0; i< nbPlanetes; i++){
        Planete* planete = data->getPlanete(i);
        if(planete->getDistance(x, y) - sizePlanete <= rayon){
            Planete* plan = (Planete*)malloc(sizeof(Planete));
            plan = new Planete(planete);
            joueur->addAstre(plan);
        }
    }
}

void Window::afficher(Planete* planete){
    sf::CircleShape* cercle = new sf::CircleShape(sizePlanete);
    Joueur* joueur = data->getJoueur(planete->getNumJoueur());
    cercle->setFillColor(joueur->getCouleur());
    cercle->setPosition(planete->getPosX(), planete->getPosY());
    float largeur = cercle->getGlobalBounds().width;
    float hauteur = cercle->getGlobalBounds().height;
    cercle->setOrigin(largeur/2, hauteur/2);
    draw(*cercle);
}

void Window::afficher(Flotte* flotte, int num){
    sf::CircleShape* triangle = new sf::CircleShape(sizeFlotte, 3);
    triangle->setFillColor(sf::Color(255,255,255));
    triangle->setPosition(flotte->getPosX(), flotte->getPosY());
    triangle->setRotation(flotte->getAngle());
    float largeur = triangle->getGlobalBounds().width;
    float hauteur = triangle->getGlobalBounds().height;
    triangle->setOrigin(largeur/2, hauteur/2);
    if (!flotte->getEnvoye()){
        float angle = getAngleDegre(flotte->getPosX()+largeur/2, 
            flotte->getPosY()+hauteur/2, xSouris, ySouris);
        triangle->setRotation(angle);
        draw(*triangle);
        triangle->setPosition(xSouris, ySouris);  
        draw(*triangle);
    }
    else{
        draw(*triangle);
    }
}

void Window::dessinerEspace(){
    clear(sf::Color::Black);
    for(int j = 0; j<nbJoueurs; j++){
        Joueur* joueur = data->getJoueur(j);
        vector<Planete*> listePlanetes = joueur->getPlanete();
        if (joueur->getType() == "joueur"){
            for (int i = 0; i<listePlanetes.size(); i++){
                Planete* planete = listePlanetes[i];
                revelerCercle(joueur, planete->getPosX(), planete->getPosY(), sizePlanete*3);
            }
            vector<Flotte*> listeFlottes = joueur->getFlottes();
            for (int i = 0; i<listeFlottes.size(); i++){
                Flotte* flotte = joueur->getFlotte(i);
                revelerCercle(joueur, flotte->getPosX(), flotte->getPosY(), sizePlanete*2);
            }
            for (int i = 0; i<joueur->getAstres().size(); i++){
                Astre* astre = joueur->getAstre(i);
                afficher((Planete*)astre);
            }
            for (int i = 0; i<listePlanetes.size(); i++){
                Planete* planete = data->getPlanete(i);
                afficher(planete);
            }
            for (int i = 0; i<listeFlottes.size(); i++){
                Flotte* flotte = joueur->getFlotte(i);
                afficher(flotte, i);
            }
        }
    }
    display();   
}

void Window::addProd(int diff){
    data->addProd(diff);
}