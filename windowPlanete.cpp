#include "windowPlanete.h"

using namespace std;

WindowPlanete::WindowPlanete(sf::VideoMode mode, const string &title): 
	sf::RenderWindow(mode, title), planete(0), visible(0), vue("général")
{
	init();
}

WindowPlanete::WindowPlanete(Planete* planete, sf::VideoMode mode, const string &title): 
	sf::RenderWindow(mode, title), planete(planete), visible(1), vue("général")
{
	init();
    joueur = 0;
}

WindowPlanete::~WindowPlanete(){
    delete(sprite);
    delete(text);
    delete(texture);
    delete(font);
    for (int i = 0; i<nbVaisseaux; i++){
        delete(champsTexte[i]);
    }

    delete(planete);

    delete(batiments);
    delete(vaisseaux);
    delete(recherche);
    delete(flotte);
    delete(envoi);

    delete(nouvelle);

}

void WindowPlanete::init(){
    text = new sf::Text();
    texture = new sf::Texture();
    sprite = new sf::Sprite();
    font = new sf::Font();
    initTextes();
    setBouton(0, 100, 20);
    nouvelle = 0;
    setVisible(visible);
}

void WindowPlanete::initTextes(){
    for (int i = 0; i<nbVaisseaux; i++){
        champsTexte[i] = new TextArea();
    }
}

Planete* WindowPlanete::getPlanete(){
	return planete;
}

void WindowPlanete::setPlanete(Planete* plan){
	planete = plan;
}

void WindowPlanete::affecter(Planete* plan, Joueur* j){
    joueur = j;
	setVisible(1);
	setActive(1);
    setPlanete(plan);
    setTitle(plan->getNom());
}

int WindowPlanete::isVisible(){
	return visible;
}

// rend la fenetre visible (1) ou cachée (0)
void WindowPlanete::setVisible(int visib){
	visible = visib;
    if (visib == 0){
        initTextes();
        setVue("général");
    }
    sf::RenderWindow::setVisible(visib);
}

void WindowPlanete::setVue(std::string nvVue){
	vue = nvVue;
}

std::string WindowPlanete::getVue(){
	return vue;
}

Flotte* WindowPlanete::getFlotte(){
    return nouvelle;
}

void WindowPlanete::resetFlotte(){
    nouvelle = 0;
}

// charge le contenu de la fenêtre planète
void WindowPlanete::loadContenu(){
    
	if (!visible){
        setVisible(0);
        sf::Event event;
        while (pollEvent(event)){
            if (event.type == sf::Event::Closed){
                setVisible(0);
            }
        }
		return;
	}
	initTexture();
	initTexte();

    checkEvent();

    clear(sf::Color::Black);
    draw(*sprite);
    setTextPlanete();
    display();
    exit;
}

// --------------------------------  Initialisations -------------------------------------------------

void WindowPlanete::initTexture(){
    if (!texture->loadFromFile("fond2.jpg"))
    {
        cout << "erreur de texture2" << endl;
    }
    sprite->setTexture(*texture);
}

void WindowPlanete::initTexte(){
    if (!font->loadFromFile("arial.ttf"))
    {
        cout << "erreur de font" << endl;
    }
    text->setFont(*font);
    text->setCharacterSize(16); // in pixels, not points!
    text->setColor(sf::Color::Red);
}

// --------------------------------  Evénements -------------------------------------------------

// main loop event
void WindowPlanete::checkEvent(){
    sf::Event event;
    while (pollEvent(event)){
        switch(event.type){
            case sf::Event::Closed:
                setVisible(0);
                break;
            default :
                if (vue == "général"){
                    checkEventBatiments(event);
                }
                else if (vue == "chantier"){
                    checkEventVaisseaux(event);
                }
                else if (vue == "recherche"){
                    checkEventRecherche(event);
                }
                else if (vue == "flotte"){
                    checkEventFlotte(event);
                }
                isClicked(event.mouseButton.x, event.mouseButton.y);
        }
    }
}

//  Gestion des évènements en vue batiment
void WindowPlanete::checkEventBatiments(sf::Event &event){
    if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Left){
            for (int i = 0; i<nbBatiments; i++){
                Batiment* actuel = planete->getBatiment(i);
                string res = actuel->isClicked(event.mouseButton.x, event.mouseButton.y);
                planete->apply(res, actuel);
            }
        }
    }
}

void WindowPlanete::checkEventVaisseaux(sf::Event &event){
    if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Left){
            for (int i = 0; i<nbVaisseaux; i++){
                ChantierSpatial* chantier = (ChantierSpatial*)(planete->getBatiment(4));
                Vaisseau* actuel = chantier->getVaisseau(i);
                string res = actuel->isClicked(event.mouseButton.x, event.mouseButton.y);
                planete->apply(res, actuel);
            }
        }
    }
}

void WindowPlanete::checkEventRecherche(sf::Event &event){
    if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Left){
            for (int i = 0; i<nbVaisseaux; i++){
                Recherche* actuelle = joueur->getRecherche(i);
                string res = actuelle->isClicked(event.mouseButton.x, event.mouseButton.y);
                joueur->apply(res, actuelle, planete);
            }
        }
    }
}

void WindowPlanete::checkEventFlotte(sf::Event &event){
    if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Left){
            for (int i = 0; i<nbVaisseaux; i++){
                if (champsTexte[i]->getClicked(event.mouseButton.x, event.mouseButton.y)){
                    for (int j = 0; j<nbVaisseaux; j++){
                        champsTexte[j]->setFocus(0);
                    }
                    champsTexte[i]->setFocus(1);
                    champsTexte[i]->setTexte("");
                }
            }
        }
    }
    if (event.type == sf::Event::TextEntered){
        for (int j = 0; j<nbVaisseaux; j++){
            if(champsTexte[j]->getFocus()){
                champsTexte[j]->addChar(static_cast<char>(event.text.unicode));
            }
        }
    }
}

void WindowPlanete::setBouton(int x1, int y1, int increment){
    int cote = 16;
    int x = x1;
    int y = y1;
    batiments = new Bouton("->batiments", "openBatiments", x, y, 100, cote);
    vaisseaux = new Bouton("->chantier spatial", "openChantier", x, y+increment, 100, cote);
    recherche = new Bouton("->effectuer une recherche", "rechercher", x, y+2*increment, 100, cote);
    flotte = new Bouton("->constituer une flotte", "sendFlotte", x, y+3*increment, 100, cote);
    envoi = new Bouton("envoyer une flotte", "sendFlotte", 0, 0, 0, 0);
}

void WindowPlanete::isClicked(int x, int y){
    if (batiments->getClicked(x, y)){
        initTextes();
    	setVue("général");
    }
    else if (vaisseaux->getClicked(x, y)){
        initTextes();
    	setVue("chantier");
    }
    else if (recherche->getClicked(x, y)){
        initTextes();
        setVue("recherche");
    }
    else if (flotte->getClicked(x, y)){
        initTextes();
    	setVue("flotte");
    }
    else if (envoi->getClicked(x, y) && isVaisseau()){
        nouvelle = envoyerFlotte();
    }
}

// ----------------------------------  Textes -------------------------------------------------

// écrit les informations sur la planète dans la fenêtre planète
void WindowPlanete::setTextPlanete(){
	setTextRessources();

    int posY = 100;
    int increment = 20;

    setMenu(posY, increment);

    if (vue == "général"){
    	for (int i = 0; i<nbBatiments; i++){
        	Batiment* actuel = planete->getBatiment(i);
        	setText(actuel, posY, increment);
    	}
	}
	else if (vue == "chantier"){
		for (int i = 0; i<nbVaisseaux; i++){
			Vaisseau* actuel = planete->getVaisseau(i);
			setText(actuel, posY, increment);
		}
	}
    else if (vue == "recherche"){
        for (int i = 0; i<nbRecherches; i++){
            Recherche* actuelle = joueur->getRecherche(i);
            setText(actuelle, posY, increment);
        }
    }
	else if (vue == "flotte"){
		for (int i = 0; i<nbVaisseaux; i++){
			Vaisseau* actuel = planete->getVaisseau(i);
			setText(actuel, posY, increment, i);
		}
        setBoutonEnvoi(posY, increment);
	}
}

// affiche les ressources actuelles de la planète
void WindowPlanete::setTextRessources(){
    text->setString("Metal : " + itos(planete->getMetal()) + 
        '(' + itos(planete->getProdMetal()) + ')');
    text->setPosition(0,0);
    draw(*text);
    text->setString("Cristal : " + itos(planete->getCristal()) + 
        '(' + itos(planete->getProdCristal()) + ')');
    text->setPosition(0,20);
    draw(*text);
    text->setString("Deuterium : " + itos(planete->getDeuterium()) + 
        '(' + itos(planete->getProdDeuterium()) + ')');
    text->setPosition(0,40);
    draw(*text);
    text->setString("Energie : " + itos(planete->getEnergie()));
    text->setPosition(0,60);
    draw(*text);
}

// affiche le menu permettant d'acceder aux différents pôle de la planète
void WindowPlanete::setMenu(int &posY, int increment){
    string items[4] = {"->batiments", "->chantier spatial", "->recherche", 
        "->constituer une flotte"};
    for (int i = 0; i<4; i++){
        text->setString(items[i]);
        text->setPosition(0,posY);
        draw(*text);
        posY+=increment;
    }
    posY+=increment;
}

// charge le contenu du batiment actuel
void WindowPlanete::setText(Batiment* actuel, int &posY, int increment){
	int xBouton = 200;

	string s = "";
    if (actuel->getTemps() != 0){
        s = getDuree(actuel->getTemps());
    }
    text->setString(actuel->getNom() + " : " + itos(actuel->getNiveau()) + " " + s);
    text->setPosition(0,posY);
    draw(*text);

    actuel->setBouton(xBouton, posY);

    if(actuel->enConstruction()){
        setBoutonCancel(actuel);
    }
    else if (!planete->enConstruction("batiment")){
        setBoutonConstruire(actuel);
    }

    posY+=increment;
}

// charge le contenu de la flotte disponible
void WindowPlanete::setText(Vaisseau* actuel, int &posY, int increment){
	int xBouton = 220;

	string s = "";
    if (actuel->getTemps() != 0){
        s = getDuree(actuel->getTemps());
    }
    text->setString(actuel->getNom() + " : " + itos(planete->getNombre(actuel)) 
    	+ " " + s);
    text->setPosition(0,posY);
    draw(*text);

    actuel->setBouton(xBouton, posY);

    if (!planete->enConstruction("vaisseau")){
        setBoutonConstruire(actuel);
    }

    posY+=increment;
}

// charge le contenu des recherches disponibles
void WindowPlanete::setText(Recherche* actuelle, int &posY, int increment){
    int xBouton = 220;

    string s = "";
    if (actuelle->getTemps() != 0){
        s = getDuree(actuelle->getTemps());
    }
    text->setString(actuelle->getNom() + " : " + itos(actuelle->getNiveau())
        + " " + s);
    text->setPosition(0,posY);
    draw(*text);

    actuelle->setBouton(xBouton, posY);

    if(actuelle->enRecherche()){
        setBoutonCancel(actuelle);
    }
    else if (!joueur->enRecherche()){
        setBoutonConstruire(actuelle);
    }

    posY+=increment;
}

// charge le contenu de la flotte disponible
void WindowPlanete::setText(Vaisseau* actuel, int &posY, int increment, int num){
    if (actuel->getNum() == 10){  // Les satellite (n°10) ne peuvent etre inclus dans une flotte
        return;
    }
    int xBouton = 220;

    text->setString(actuel->getNom() + " : " + itos(planete->getNombre(actuel)));
    text->setPosition(0,posY);
    draw(*text);

    champsTexte[num]->setPosition(xBouton, posY);
    champsTexte[num]->setSize(32, 16);
    int max = planete->getNombre(actuel);
    champsTexte[num]->setMax(max);

    sf::RectangleShape rectangle(sf::Vector2f(xBouton, posY));
    rectangle.setPosition(sf::Vector2f(xBouton, posY));
    rectangle.setSize(sf::Vector2f(32, 16));
    rectangle.setFillColor(champsTexte[num]->getColor());
    draw(rectangle);

    text->setString(champsTexte[num]->getTexte());
    text->setPosition(xBouton, posY);
    draw(*text);

    posY+=increment;
}

// affiche le bouton permettant l'envoi de la flotte
void WindowPlanete::setBoutonEnvoi(int &posY, int increment){
    int xBouton = 160;

    envoi = new Bouton("envoyer une flotte", "sendFlotte", 0, posY, 100, 20);

    text->setString("Envoi");
    text->setPosition(0,posY);
    draw(*text);
}

// Verifie si un vaisseau est selectionné avant l'envoi d'une flotte
int WindowPlanete::isVaisseau(){
    for (int i = 0; i<nbVaisseaux; i++){
        string texte = champsTexte[i]->getTexte();
        if (texte != ""){
            int nb = atoi(texte.c_str());
            if (nb >= 1){
                return 1;
            }
        }
    }
    return 0;
}

// constitue et envoi une flotte définie par l'utilisateur
Flotte* WindowPlanete::envoyerFlotte(){
    Flotte* flotte = new Flotte(planete->getNumJoueur(), planete->getPosX(), planete->getPosY(), 0);
    for (int i = 0; i<nbVaisseaux; i++){
        string text = champsTexte[i]->getTexte();
        int nb = atoi(text.c_str());
        flotte->addVaisseau(i, nb);
        planete->removeVaisseau(i, nb);
    }
    return flotte;
}

// -------------------------  Mise en place des boutons -----------------------------------

//charge le bouton "annuler la construction"
void WindowPlanete::setBoutonCancel(Batiment* actuel){
	text->setString(actuel->getBoutonCancel()->getSymbole());
    text->setPosition(actuel->getBoutonCancel()->getPosX(), actuel->getBoutonCancel()->getPosY());
    draw(*text);
}

//charge le bouton "annuler la recherche"
void WindowPlanete::setBoutonCancel(Recherche* recherche){
    text->setString(recherche->getBoutonCancel()->getSymbole());
    text->setPosition(recherche->getBoutonCancel()->getPosX(), recherche->getBoutonCancel()->getPosY());
    draw(*text);
}

//charge les boutons '+' = construire et '-' = détruire
void WindowPlanete::setBoutonConstruire(Batiment* actuel){
	text->setString(actuel->getBoutonUp()->getSymbole());
    text->setPosition(actuel->getBoutonUp()->getPosX(), actuel->getBoutonUp()->getPosY());
    draw(*text);

    text->setString(actuel->getBoutonDown()->getSymbole());
    text->setPosition(actuel->getBoutonDown()->getPosX(), actuel->getBoutonDown()->getPosY());
    draw(*text);
}

//charge les boutons '+' = construire et '-' = détruire
void WindowPlanete::setBoutonConstruire(Vaisseau* actuel){
	text->setString(actuel->getBoutonUp()->getSymbole());
    text->setPosition(actuel->getBoutonUp()->getPosX(), actuel->getBoutonUp()->getPosY());
    draw(*text);
}

//charge les boutons '+' = construire et '-' = détruire
void WindowPlanete::setBoutonConstruire(Recherche* actuelle){
    text->setString(actuelle->getBoutonUp()->getSymbole());
    text->setPosition(actuelle->getBoutonUp()->getPosX(), actuelle->getBoutonUp()->getPosY());
    draw(*text);
}
