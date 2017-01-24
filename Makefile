FLAG=-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \

LDFLAGS=-g

BATIMENTS=batiment.o \
	metal.o \
	cristal.o \
	deuterium.o \
	centraleSolaire.o \
	centraleFusion.o \
	hangarMetal.o \
	hangarCristal.o \
	reservoirDeut.o \
	usineRobots.o \
	chantierSpatial.o \
	laboRecherche.o \
	silo.o \
	usineNanites.o \
	terraformeur.o

VAISSEAUX=vaisseau.o \
	chasseurLeger.o \
	chasseurLourd.o \
	croiseur.o \
	vaisseauBataille.o \
	traqueur.o \
	bombardier.o \
	destructeur.o \
	etoileDeLaMort.o \
	petitTransporteur.o \
	grandTransporteur.o \
	vaisseauColo.o \
	sonde.o \
	recycleur.o \
	satellite.o

ASTRE=astre.o \
	planete.o \
	flotte.o \

CLASSES=main.o \
	window.o \
	data.o \
	windowPlanete.o \
	construction.o \
	bouton.o \
	textArea.o \
	joueur.o \
	recherche.o \
	$(ASTRE) \
	$(BATIMENTS) \
	$(VAISSEAUX) \
	util.o

all : main

main : $(CLASSES)
	g++ $(LDFLAGS) $(CLASSES) -o ogame $(FLAG)

main.o : main.cpp
	g++ -c main.cpp

window.o : window.cpp
	g++ -c window.cpp

data.o : data.cpp
	g++ -c data.cpp

windowPlanete.o : windowPlanete.cpp
	g++ -c windowPlanete.cpp

astre.o : astre.cpp
	g++ -c astre.cpp

planete.o : planete.cpp
	g++ -c planete.cpp

bouton.o : bouton.cpp
	g++ -c bouton.cpp

textArea.o : textArea.cpp
	g++ -c textArea.cpp

construction.o : construction.cpp
	g++ -c construction.cpp

batiment.o : batiment.cpp
	g++ -c batiment.cpp

metal.o : metal.cpp
	g++ -c metal.cpp

cristal.o : cristal.cpp
	g++ -c cristal.cpp

deuterium.o : deuterium.cpp
	g++ -c deuterium.cpp

centraleSolaire.o : centraleSolaire.cpp
	g++ -c centraleSolaire.cpp

centraleFusion.o : centraleFusion.cpp
	g++ -c centraleFusion.cpp

hangarMetal.o : hangarMetal.cpp
	g++ -c hangarMetal.cpp

hangarCristal.o : hangarCristal.cpp
	g++ -c hangarCristal.cpp

reservoirDeut.o : reservoirDeut.cpp
	g++ -c reservoirDeut.cpp

usineRobots.o : usineRobots.cpp
	g++ -c usineRobots.cpp

chantierSpatial.o : chantierSpatial.cpp
	g++ -c chantierSpatial.cpp

laboRecherche.o : laboRecherche.cpp
	g++ -c laboRecherche.cpp

silo.o : silo.cpp
	g++ -c silo.cpp

usineNanites.o : usineNanites.cpp
	g++ -c usineNanites.cpp

terraformeur.o : terraformeur.cpp
	g++ -c terraformeur.cpp

joueur.o : joueur.cpp
	g++ -c joueur.cpp

vaisseau.o : vaisseau.cpp
	g++ -c vaisseau.cpp

flotte.o : flotte.cpp
	g++ -c flotte.cpp

chasseurLeger.o : chasseurLeger.cpp
	g++ -c chasseurLeger.cpp

chasseurLourd.o : chasseurLourd.cpp
	g++ -c chasseurLourd.cpp

croiseur.o : croiseur.cpp
	g++ -c croiseur.cpp

vaisseauBataille.o : vaisseauBataille.cpp
	g++ -c vaisseauBataille.cpp

traqueur.o : traqueur.cpp
	g++ -c traqueur.cpp

bombardier.o : bombardier.cpp
	g++ -c bombardier.cpp

destructeur.o : destructeur.cpp
	g++ -c destructeur.cpp

etoileDeLaMort.o : etoileDeLaMort.cpp
	g++ -c etoileDeLaMort.cpp

petitTransporteur.o : petitTransporteur.cpp
	g++ -c petitTransporteur.cpp

grandTransporteur.o : grandTransporteur.cpp
	g++ -c grandTransporteur.cpp

satellite.o : satellite.cpp
	g++ -c satellite.cpp

sonde.o : sonde.cpp
	g++ -c sonde.cpp

vaisseauColo.o : vaisseauColo.cpp
	g++ -c vaisseauColo.cpp

recycleur.o : recycleur.cpp
	g++ -c recycleur.cpp

recherche.o : recherche.cpp
	g++ -c recherche.cpp

util.o : util.cpp
	g++ -c util.cpp

clean :
	rm *.o