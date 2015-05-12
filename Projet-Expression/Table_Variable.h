/**
* \file Table_Variable.h
* \brief Déclaration de la classe Table_Variable
* \author Charles Bong.
* \date 5 Avril 2015
*/

#ifndef TABLE_VARIABLE
#define TABLE_VARIABLE
#include <map>
#include <stack>
#include "Variable.h"
#include "Singleton.h"

/** \class Table_Variable
* \brief Tableau des variables, association entre une lettre et une valeur
* \author Charles Bong.
* \date 5 Avril 2015
*/
class Table_Variable : public Singleton<Table_Variable>
{
	friend class Singleton<Table_Variable>;

private:
	// Constructeur/destructeur
	Table_Variable();
	~Table_Variable();

public:
	// Interface publique
	void setVariable(std::string name, float value);
	Variable* getVariable(std::string name);
	void destroyVariable(std::string name);
	std::stack<std::string> getListVariableNonDef();

private:
	std::map<std::string, Variable*> _listof;
};

#endif
