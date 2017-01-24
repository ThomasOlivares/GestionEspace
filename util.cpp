#include "util.h"

using namespace std;

// convert integer to string
string itos(int a){
    int Number = a;
    string Result;
    ostringstream convert;
    convert << Number;
    Result = convert.str();
    return Result;
}

float getAngle(int x1, int y1, int x2, int y2){
	if (x1 == x2){
		if (y1 < y2){
			return pi;
		}
	}
	if (y1 > y2){
		return (float)atan((float)(x2-x1)/(float)(y2-y1));
	}
	else if (x1 > x2){
		return pi/2 - (float)atan((float)(y2-y1)/(float)(x2-x1));
	}
	else if (x1 < x2){
		return -pi/2 - (float)atan((float)(y2-y1)/(float)(x2-x1));
	}
	else{   // Si x2=x1 et y1=y2, l'angle renvoyé est 0 (arbitraire)
		return 0;
	}
	cout << "erreur : util::getAngle" << x1 << "  " << y1 << "  " << x2 << "  " << y2 << endl;
	throw "error";
}

float getAngleDegre(int x1, int y1, int x2, int y2){
	return -(180/3.14)*getAngle(x1, y1, x2, y2);
}

string getDuree(int temps){
	string duree = "";
	int secondes = temps;
	int heures = secondes / 3600;
	secondes -= heures * 3600;
	int minutes  = secondes / 60;
	secondes -= minutes * 60;
	if (heures != 0){
		duree += itos(heures) + " min" + itos(minutes) + " min";
	}
	else if (minutes != 0){
		duree += itos(minutes) + " min" + itos(secondes) + " s";
	}
	else{
		duree += itos(secondes) + " sec";
	}
	return duree;
}

double distance(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}