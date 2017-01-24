#include "main.h"

/* IDEES :
- fonctionnalité de séparation/fusion de flottes en plein vol
- agrandissement de la vision en fct du niveau d'espionnage
- furtivité
*/

/* TODO : 
- Mettre les cercles dans la classe planete
- Ajouter un bouton régulant la vitesse de jeu (contre les IA)
*/

using namespace std;

int incrementClock(){
    static sf::Clock clock; // starts the clock
    static sf::Time previous = sf::seconds(0);
    //calcul du temps écoulé depuis la dernière actualisation
    int diff = (clock.getElapsedTime() - previous).asMicroseconds();
    previous = clock.getElapsedTime();
    return diff;
}

int main()
{
    Window* window = new Window(sf::VideoMode(1300, 700), "Univers");
    window->initTexture();
    WindowPlanete* windowPlanete = new WindowPlanete(sf::VideoMode(250, 700), "");
    windowPlanete->setVisible(0);

    while (window->isOpen())
    { 
        window->handleEvent(windowPlanete);
        if (windowPlanete->getFlotte() != 0){
            window->nouvelleFlotte(windowPlanete->getFlotte());
            windowPlanete->resetFlotte();
            windowPlanete->setVisible(0);
        }
        int diff = incrementClock();
        window->addProd(diff);
        window->moveFlotte(diff);
        window->dessinerEspace();
        windowPlanete->loadContenu();
        
        exit;
    }

    //delete(window);
    //delete(windowPlanete);

    return 0;
}
