#ifndef RECHERCHE_H
#define RECHERCHE_H

#include <string>
#include "construction.h"

class Recherche: public Construction{
	public:
		Recherche(int num);
		Recherche(Recherche* r);
		virtual ~Recherche();
		
		void initCout();
		int getNum();
		virtual std::string getNom();
		void setNom(std::string nv);
		virtual std::string getType();
		int getNiveau();
		void setNiveau(int valeur);
		void levelUp();
		void construire(int tps);
		int enRecherche();
		void cancelRecherche();

	protected:
		int num;
		std::string nom;
		int niveau;
};

#endif // RECHERCHE_H