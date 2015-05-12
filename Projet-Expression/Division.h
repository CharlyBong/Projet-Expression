/**
* \file Division.h
* \brief Déclaration de la classe Division
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef DIVISION
#define DIVISION
#include "Operateur.h"

/** \class Division
* \brief Opérateur division
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Division :
	public Operateur
{
public:
	Division(Operande* op_gauche, Operande* op_droit);
	~Division();

	void afficher(); /* Affiche l'opérande */
	void afficherPolonaise(); /* Affiche l'opérande en version polonaise*/
	void afficherSimple(); /* Affiche l'opérande en mode simplifié */
	float calculer(); /* Permet d'éffectuer l'opération contenu */
};

#endif