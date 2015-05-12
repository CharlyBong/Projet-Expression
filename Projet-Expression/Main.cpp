/**
* \file Main.cpp
* \brief Fichier principale du programme
* \author Charles Bong.
* \date 14 Mars 2015
*/

#include <iostream>
#include <string>

#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Constante.h"
#include "Variable.h"
#include "Expression.h"


int main()
{
	Table_Variable* _tableV = _tableV->getInstance();
	std::string input;
	
	std::cout << "Bonjour :)" << std::endl;
	std::cout << " Veuillez rentrer votre expression (notation polonaise inverse), puis appuyer sur entrer : " << std::endl;

	
	std::getline(std::cin, input);
	Expression* exp_user = new Expression(input);
	std::cout << std::endl;

	std::cout << " Affichage simple : " << std::endl;
	exp_user->afficher();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << " Affichage polonaise inverse : " << std::endl;
	exp_user->afficherPolonaise();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << " Affichage simplifie : " << std::endl;
	exp_user->afficherSimple();
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << " Affichage du resultat : " << std::endl;
	exp_user->afficher_expression();
	std::cout << std::endl;

	std::stack<std::string> listVariableNull = _tableV->getListVariableNonDef();
	if (!listVariableNull.empty())
	{
		while (!listVariableNull.empty())
		{
			std::string var = listVariableNull.top();
			listVariableNull.pop();
			std::cout << " Assigner une valeur a " << var << " = ";
			float a;
			std::cin >> a;
			_tableV->setVariable(var, a);
		}

		std::cout << std::endl;
		std::cout << " Affichage du resultat : " << std::endl;
		exp_user->afficher_expression();
		std::cout << std::endl;
		std::getline(std::cin, input);
	}

	delete exp_user;
	_tableV->kill();

	std::cout << " -- END -- " << std::endl;
	std::cout << " Appuyer sur 'entree' pour terminer le programme ...";
	std::getline(std::cin, input);
	std::cout << " -- END -- " << std::endl;

	return 0;
}
