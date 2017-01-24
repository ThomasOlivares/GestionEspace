#ifndef TEXT_AREA_H
#define TEXT_AREA_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "util.h"

class TextArea{
	
	public:
		TextArea();
		TextArea(int x, int y, int largeur, int longueur);
		virtual ~TextArea();
		
		void setColor(sf::Color newColor);
		void addChar(char c);
		std::string getTexte();
		void setTexte(std::string nvTexte);
		int getClicked(int x, int y);
		void setPosition(int x, int y);
		void setSize(int x, int y);
		int getFocus();
		void setFocus(int nvFocus);
		sf::Color getColor();
		int getMax();
		void setMax(int m);

	protected:
		void removeChar();
		int checkMax(char c);
		int max;   // Valeur maximale acceptée par le champs de texte
		int posX;
		int posY;
		int largeur;
		int longueur;
		sf::Color color;
		std::string texte;
		int focus;
};

#endif  //TEXT_AREA_H
