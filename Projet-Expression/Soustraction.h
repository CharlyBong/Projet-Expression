/**
* \file Soustraction.h
* \brief Déclaration de la classe Soustraction
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef SOUSTRACTION
#define SOUSTRACTION
#include "Operateur.h"

/** \class Soustraction
* \brief Opérateur soustraction
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Soustraction :
	public Operateur
{
public:
	Soustraction(Operande* op_gauche, Operande* op_droit);
	~Soustraction();

	void afficher(); /* Affiche l'opérande */
	void afficherPolonaise(); /* Affiche l'opérande en version polonaise*/
	void afficherSimple(); /* Affiche l'opérande en mode simplifié */
	float calculer(); /* Permet d'éffectuer l'opération contenu */
};

#endif