/**
* \file Variable.h
* \brief Déclaration de la classe Variable
* \author Charles Bong.
* \date 17 Mars 2015
*/

#ifndef VARIABLE
#define VARIABLE
#include <string>
#include "Operande.h"


/** \class Variable
* \brief Valeur inconnue d'une expression
* \author Charles Bong.
* \date 17 Mars 2015
*/
class Variable :
	public Operande
{
public:
	Variable(std::string name);
	Variable(std::string name, float value);
	~Variable();

	void definir(float value);
	void afficher();
	void afficherPolonaise();
	void afficherSimple();
	float calculer();


private:
	std::string _name;
	float _value = NULL;
};

#endif
