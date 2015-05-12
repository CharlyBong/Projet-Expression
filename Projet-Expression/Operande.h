/**
* \file Operande.h
* \brief Déclaration de la classe Operande
* \author Charles Bong.
* \date 14 Mars 2015
*/

#ifndef OPERANDE
#define OPERANDE
#include <iostream>

/** \class Operande
* \brief Opérande d'une opération
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Operande
{
public:
	Operande() {};
	virtual ~Operande() {};

	/** \brief Afficheur par défaut de l'opérande */
	virtual void afficher() = 0; 
	/** \brief Afficheur de l'opérande en version polonaise */
	virtual void afficherPolonaise() = 0;
	/** \brief Afficheur de l'opérande en mode simplifié */
	virtual void afficherSimple() = 0;
	/** \brief Permet d'éffectuer l'opération contenu */
	virtual float calculer() = 0;
	
};

#endif
