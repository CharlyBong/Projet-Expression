/**
* \file Table_Variable.cpp
* \brief Impl�mentation de la classe Table_Variable
* \author Charles Bong.
* \date 5 Avril 2015
*/

#include "Table_Variable.h"


Table_Variable::Table_Variable()
{}

Table_Variable::~Table_Variable()
{
	for (auto one : _listof)
		if (one.second != NULL) delete one.second;
	_listof.clear();
}

/** \brief Obtetion d'une variable
*	Test l'existance d'une variable, la cr�e dans le cas contraire
*	Et la retourne.
* \param name string : Nom de la variable � obtenir
*/
Variable* Table_Variable::getVariable(std::string name)
{
	std::map<std::string, Variable*>::iterator it = _listof.find(name);
	if (it == _listof.end())
		_listof[name] = new Variable(name);
	return _listof[name];
}

/** \brief Assignation d'une valeur � une variable
*	Recherche dans les variables enregistr�es (_listof) celle ayant comme nom 'name'.
*	Assignation d'une valeur pour cette variable s'il elle existe, cr�ation de la variable dans le cas contraire.
* \param name string : Nom de la variable � obtenir
* \param value float : Valeur � d�finir
*/
void Table_Variable::setVariable(std::string name, float value)
{
	std::map<std::string, Variable*>::iterator it = _listof.find(name);
	if (it == _listof.end())
		_listof[name] = new Variable(name, value);
	else
		_listof[name]->definir(value);

	std::cout << name << " = " << value << std::endl;
}

/** \brief Destruction d'une variable
* \param name string : Nom de la variable � supprimer
*/
void Table_Variable::destroyVariable(std::string name)
{
	_listof.erase(name);
}

/** \brief Getter d'un la liste des variables n'ayant pas de valeur assigni�e
*	Cr�ation d'un stack pour le retour (list).
*	Parcours des variables enregistr�es (_listof).
*	Ajout dans le stack des variables n'ayant pas de valeur assigni�e (item.second->calculer() == NULL).
*/
std::stack<std::string> Table_Variable::getListVariableNonDef()
{
	std::stack<std::string> list;
	for (auto item : _listof)
		if ((item.second != NULL) && (item.second->calculer() == NULL)) list.push(item.first);
	return list;
}

