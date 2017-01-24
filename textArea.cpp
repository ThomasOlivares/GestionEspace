#include "textArea.h"

using namespace std;

TextArea::TextArea():focus(0), max(-1), texte("0"){
	setColor(sf::Color(255, 255, 255));
}

TextArea::TextArea(int x, int y, int largeur, int longueur) : focus(0), max(-1), posX(x), posY(y), 
		largeur(largeur), longueur(longueur), texte("0"){
	setColor(sf::Color(255, 255, 255));
}

TextArea::~TextArea(){
	
}

sf::Color TextArea::getColor(){
	return color;
}

void TextArea::setColor(sf::Color newColor){
	color = newColor;
}

void TextArea::setPosition(int x, int y){
	posX = x;
	posY = y;
}

void TextArea::setSize(int x, int y){
	largeur = x;
	longueur = y;
}

void TextArea::setMax(int m){
	max = m;
}

int TextArea::getMax(){
	return max;
}

void TextArea::addChar(char c){
	int code = c;
	if (code == 8){  // bouton "delete" 
		removeChar();
	}
	if (code < 48 || code > 57){   // c n'est pas un chiffre
		return;
	}
	if (checkMax(c)){
		texte+=c;
	}
	else{
		texte = itos(max);
	}
}

int TextArea::getClicked(int x, int y){
	if ((x >= posX) && (x <= posX + largeur) && (y >= posY) && (y <= posY + longueur)){
		return 1;
	}
	return 0;
}

string TextArea::getTexte(){
	return texte;
}

void TextArea::setTexte(string nvTexte){
	texte = nvTexte;
}

int TextArea::getFocus(){
	return focus;
}

void TextArea::setFocus(int nvFocus){
	if (nvFocus == 0){
		color = sf::Color(255, 255, 255);
	}
	else if (nvFocus == 1){
		color = sf::Color(255, 215, 0);
	}
	focus = nvFocus;
}

// ------------------------ Protected ------------------------------

int TextArea::checkMax(char c){
	if (max == -1){
		return 1;
	}
	string newTexte = texte + c;
	int i = atoi(newTexte.c_str());
	return i <= max;
}

void TextArea::removeChar(){
	if (texte == ""){
		return;
	}
	string nvTexte = "";
	for (int i = 0; i<texte.size()-1; i++){
		nvTexte += texte[i];
	}
	setTexte(nvTexte);
}