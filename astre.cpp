#include "astre.h"

using namespace std;

Astre::Astre(int x, int y, int numJoueur): posX(x), posY(y), numJoueur(numJoueur){
    shape = new sf::CircleShape();
}

Astre::Astre(int x, int y): posX(x), posY(y), numJoueur(-1){
    shape = new sf::CircleShape();
}

Astre::~Astre(){
    delete(shape);
}

double Astre::getPosX(){
    return posX;
}

void Astre::setPosX(double x){
    posX = x;
}

double Astre::getPosY(){
    return posY;
}

void Astre::setPosY(double y){
    posY = y;
}

int Astre::getNumJoueur(){
    return numJoueur;
}

void Astre::setNumJoueur(int nouveau){
    numJoueur = nouveau;
}

sf::CircleShape* Astre::getShape(){
    return shape;
}

void Astre::setShape(sf::CircleShape* nouvelle){
    shape = nouvelle;
}

double Astre::getDistance(Astre* autre){
    return distance(posX, posY, autre->getPosX(), autre->getPosY());
}

double Astre::getDistance(double x, double y){
    return distance(posX, posY, x, y);
}

double Astre::getDistance(int x, int y){
    return getDistance((double)x, (double)y);
}