 #include "flotte.h"

using namespace std;

Flotte::Flotte(int numJoueur, int x, int y, float angle): Astre(x, y, numJoueur), 
		objX(x), objY(y), angle(angle), vitesseFlotte(50), envoye(0){
	for (int i = 0; i<nbVaisseaux; i++){
		nombre[i] = 0;
	}
}

Flotte::~Flotte(){
	
}

int Flotte::getObjX(){
	return (int)objX;
}

void Flotte::setObjX(int x){
	objX = x;
}

int Flotte::getObjY(){
	return (int)objY;
}

void Flotte::setObjY(int y){
	objY = y;
}

float Flotte::getAngle(){
	return angle;
}

void Flotte::setAngle(float nvAngle){
	angle = nvAngle;
}

void Flotte::setEnvoye(int i){
	envoye = i;
}

int Flotte::getEnvoye(){
	return envoye;
}

void Flotte::addVaisseau(int num, int nb){
	nombre[num]+=nb;
}

void Flotte::destroyVaisseau(int num, int nb){
	nombre[num]-=nb;
}

// temps en µs
void Flotte::avancer(int temps){
	if (posX == objX && posY == objY){
		return;
	}
	double distanceAParcourir = distance(posX, posY, objX, objY);
	if (distanceAParcourir < 3){
		objX = (int)posX;
		objY = (int)posY;
		posX = (int)posX;
		posY = (int)posY;
		return;
	}
	long uneHeure = pow(10,6)*60*60/(float)vitesse;
	float tempsH = (float)temps/(float)uneHeure;
	float distance = vitesseFlotte*(tempsH)*vitesse;
	posX += sin(pi*angle/180)*distance;
	posY -= cos(pi*angle/180)*distance;
}