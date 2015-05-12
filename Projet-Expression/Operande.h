/**
* \file Operande.h
* \brief D�claration de la classe Operande
* \author Charles Bong.
* \date 14 Mars 2015
*/

#ifndef OPERANDE
#define OPERANDE
#include <iostream>

/** \class Operande
* \brief Op�rande d'une op�ration
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Operande
{
public:
	Operande() {};
	virtual ~Operande() {};

	/** \brief Afficheur par d�faut de l'op�rande */
	virtual void afficher() = 0; 
	/** \brief Afficheur de l'op�rande en version polonaise */
	virtual void afficherPolonaise() = 0;
	/** \brief Afficheur de l'op�rande en mode simplifi� */
	virtual void afficherSimple() = 0;
	/** \brief Permet d'�ffectuer l'op�ration contenu */
	virtual float calculer() = 0;
	
};

#endif
