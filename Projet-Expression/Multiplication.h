/**
* \file Multiplication.h
* \brief D�claration de la classe Multiplication
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef MULTIPLICATION
#define MULTIPLICATION
#include "Operateur.h"

/** \class Multiplication
* \brief Op�rateur multiplication
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Multiplication :
	public Operateur
{
public:
	Multiplication(Operande* op_gauche, Operande* op_droit);
	~Multiplication();

	void afficher(); /* Affiche l'op�rande */
	void afficherPolonaise(); /* Affiche l'op�rande en version polonaise*/
	void afficherSimple(); /* Affiche l'op�rande en mode simplifi� */
	float calculer(); /* Permet d'�ffectuer l'op�ration contenu */
};

#endif