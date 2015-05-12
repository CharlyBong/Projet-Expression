/**
* \file Division.cpp
* \brief Implémentation de la classe Division
* \author Charles Bong.
* \date 14 Mars 2015
*/

#include "Division.h"


Division::Division(Operande* op_gauche, Operande* op_droit)
{
	_op_gauche = op_gauche;
	_op_droit = op_droit;
}


Division::~Division()
{
	delete _op_gauche;
	delete _op_droit;
	_op_gauche = NULL;
	_op_droit = NULL;
}

void Division::afficher()
{
	std::cout << "(";
	_op_gauche->afficher();
	std::cout << " / ";
	_op_droit->afficher();
	std::cout << ")";
}

void Division::afficherPolonaise()
{
	_op_gauche->afficherPolonaise();
	_op_droit->afficherPolonaise();
	std::cout << "/ ";
}

void Division::afficherSimple()
{
	float a = _op_gauche->calculer();
	float b = _op_droit->calculer();

	std::cout << "(";
	if (a == NULL) _op_gauche->afficherSimple();
	else std::cout << a;
	std::cout << " / ";
	if (b == NULL) _op_droit->afficherSimple();
	else std::cout << b;
	std::cout << ")";
}

float Division::calculer()
{
	float a = _op_gauche->calculer();
	float b = _op_droit->calculer();
	if (a == NULL) return NULL;
	if ((b == NULL)||(b==0.0f)) return NULL;
	return a / b;
}
