/**
* \file Variable.cpp
* \brief Implémentation de la classe Variable
* \author Charles Bong.
* \date 17 Mars 2015
*/

#include "Variable.h"
#include "Table_Variable.h"

/** \brief Constructeur par défaut
* \param name string : Nom de la variable
*/
Variable::Variable(std::string name)
{
	_name = name;
}

/** \brief Constructeur avancé
* \param name string : Nom de la variable
* \param value float : Valeur à donné à la variable
*/
Variable::Variable(std::string name, float value)
{
	_name = name;
	_value = value;
}

/** \brief Destructeur */
Variable::~Variable()
{
	Table_Variable* _tableV = _tableV->getInstance();
	_tableV->destroyVariable(_name);
}

/** \brief Assignation d'une valeur à la variable
* \param value float : Valeur à donné à la variable
*/
void Variable::definir(float value)
{
	_value = value;
}

void Variable::afficher()
{
	std::cout << _name;
}

void Variable::afficherPolonaise()
{
	std::cout << _name << " ";
}

void Variable::afficherSimple()
{
	this->afficher();
}

float Variable::calculer()
{
	return _value;
}
