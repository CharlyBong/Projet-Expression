/**
* \file Addition.h
* \brief Déclaration de la classe Addition
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef ADDITION
#define ADDITION
#include "Operateur.h"

/** \class Addition
* \brief Opérateur addition
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Addition :
	public Operateur
{
public:
	Addition(Operande* op_gauche, Operande* op_droit);
	~Addition();

	void afficher(); /* Affiche l'opérande */
	void afficherPolonaise(); /* Affiche l'opérande en version polonaise*/
	void afficherSimple(); /* Affiche l'opérande en mode simplifié */
	float calculer(); /* Permet d'éffectuer l'opération contenu */
	//void afficher_expression(); /* affichage l'opération  et son résultat */
};

#endif