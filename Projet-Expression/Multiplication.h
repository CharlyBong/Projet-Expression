/**
* \file Multiplication.h
* \brief Déclaration de la classe Multiplication
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef MULTIPLICATION
#define MULTIPLICATION
#include "Operateur.h"

/** \class Multiplication
* \brief Opérateur multiplication
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Multiplication :
	public Operateur
{
public:
	Multiplication(Operande* op_gauche, Operande* op_droit);
	~Multiplication();

	void afficher(); /* Affiche l'opérande */
	void afficherPolonaise(); /* Affiche l'opérande en version polonaise*/
	void afficherSimple(); /* Affiche l'opérande en mode simplifié */
	float calculer(); /* Permet d'éffectuer l'opération contenu */
};

#endif