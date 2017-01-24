#ifndef FLOTTE_H
#define FLOTTE_H

#include <iostream>
#include <cmath>
#include "astre.h"
#include "util.h"


class Flotte: public Astre{
	public:
		Flotte(int numJoueur, int x, int y, float angle);
		virtual ~Flotte();
		
		int getObjX();
		void setObjX(int x);
		int getObjY();
		void setObjY(int y);
		float getAngle();
		int getEnvoye();
		void setEnvoye(int i);
		void setAngle(float angle);
		void addVaisseau(int num, int nb);
		void destroyVaisseau(int num, int nb);
		void avancer(int temps);

	protected:
		int envoye;
		int numJoueur;
		int vitesseFlotte;
		double objX;
		double objY;
		float angle; //orientation de la flotte
		int nombre[nbVaisseaux];
};

#endif // FLOTTE_H