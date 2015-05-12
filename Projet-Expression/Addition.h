/**
* \file Addition.h
* \brief D�claration de la classe Addition
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef ADDITION
#define ADDITION
#include "Operateur.h"

/** \class Addition
* \brief Op�rateur addition
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Addition :
	public Operateur
{
public:
	Addition(Operande* op_gauche, Operande* op_droit);
	~Addition();

	void afficher(); /* Affiche l'op�rande */
	void afficherPolonaise(); /* Affiche l'op�rande en version polonaise*/
	void afficherSimple(); /* Affiche l'op�rande en mode simplifi� */
	float calculer(); /* Permet d'�ffectuer l'op�ration contenu */
	//void afficher_expression(); /* affichage l'op�ration  et son r�sultat */
};

#endif