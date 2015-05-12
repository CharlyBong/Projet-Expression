/**
* \file Constante.h
* \brief Déclaration de la classe Constante
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef CONSTANTE
#define CONSTANTE
#include "Operande.h"


/** \class Constante
* \brief Valeur définie d'une expression
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Constante :
	public Operande
{
public:
	Constante(float	value);
	Constante(const Constante &o)
	{
		_valeur = o._valeur;
	};
	~Constante() {};

	void afficher();
	void afficherPolonaise();
	void afficherSimple();
	float calculer();
	

private:
	float _valeur; 
};

#endif