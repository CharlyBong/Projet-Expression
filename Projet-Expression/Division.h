/**
* \file Division.h
* \brief D�claration de la classe Division
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef DIVISION
#define DIVISION
#include "Operateur.h"

/** \class Division
* \brief Op�rateur division
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Division :
	public Operateur
{
public:
	Division(Operande* op_gauche, Operande* op_droit);
	~Division();

	void afficher(); /* Affiche l'op�rande */
	void afficherPolonaise(); /* Affiche l'op�rande en version polonaise*/
	void afficherSimple(); /* Affiche l'op�rande en mode simplifi� */
	float calculer(); /* Permet d'�ffectuer l'op�ration contenu */
};

#endif