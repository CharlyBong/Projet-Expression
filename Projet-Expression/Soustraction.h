/**
* \file Soustraction.h
* \brief D�claration de la classe Soustraction
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef SOUSTRACTION
#define SOUSTRACTION
#include "Operateur.h"

/** \class Soustraction
* \brief Op�rateur soustraction
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Soustraction :
	public Operateur
{
public:
	Soustraction(Operande* op_gauche, Operande* op_droit);
	~Soustraction();

	void afficher(); /* Affiche l'op�rande */
	void afficherPolonaise(); /* Affiche l'op�rande en version polonaise*/
	void afficherSimple(); /* Affiche l'op�rande en mode simplifi� */
	float calculer(); /* Permet d'�ffectuer l'op�ration contenu */
};

#endif