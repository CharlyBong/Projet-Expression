/**
* \file Constante.cpp
* \brief Implémentation de la classe Constante
* \author Charles Bong.
* \date 14 Mars 2015
*/

#include "Constante.h"


Constante::Constante(float value)
{
	_valeur = value;
}

void Constante::afficher()
{
	std::cout << _valeur;
}

void Constante::afficherPolonaise()
{
	std::cout << _valeur << " ";
}

void Constante::afficherSimple()
{
	this->afficher();
}

float Constante::calculer()
{
	return _valeur;
}
