#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

#define pi 3.141

#define vitesse 50
#define metalStart 5000000
#define cristalStart 5000000
#define deuteriumStart 5000000

#define nbJoueurs 4
#define nbPlanetes 4
#define nbBatiments 14
#define nbVaisseaux 14
#define nbRecherches 16
#define sizeFlotte 20
#define sizePlanete 25

std::string itos(int a);
double distance(int x1, int y1, int x2, int y2);
double distance(double x1, double y1, double x2, double y2);
float getAngle(int x1, int y1, int x2, int y2);
float getAngleDegre(int x1, int y1, int x2, int y2);
std::string getDuree(int temps);

#endif // UTIL_H