/**
* \file Expression.cpp
* \brief Impl�mentation de la classe Expression
* \author Charles Bong.
* \date 5 Avril 2015
*/

#include "Expression.h"

/** \brief Cr�ation de la classe Expression
*	Permet d'analyser une expression sous forme d'une chaine de caract�re
*	et d'en construire l'op�rande associ�e.
* \param exp string : Expression sous forme d'une chaine de caract�re
*
* \author Charles Bong.
*/
Expression::Expression(std::string exp)
{	
	_tableV = _tableV->getInstance();
	char* expc;
	expc = (char*)exp.c_str();
	char * pch;
	char separators[] = " ,\t\n";

	char *next_token1;
	pch = strtok_s(expc, separators, &next_token1);

	Operande* opa = newOpaDigOrChar(pch);
	pch = strtok_s(NULL, separators, &next_token1);
	Operande* opb = newOpaDigOrChar(pch);
	pch = strtok_s(NULL, separators, &next_token1);
	Operateur* op = newOperateur(pch, opa, opb);
	pch = strtok_s(NULL, separators, &next_token1);

	//op->afficherPolonaise();
	//std::cout << std::endl;

	while (pch != NULL)
	{
		opa = op;
		opb = newOpaDigOrChar(pch);

		pch = strtok_s(NULL, separators, &next_token1);
		if (pch != NULL) op = newOperateur(pch, opa, opb);

		pch = strtok_s(NULL, separators, &next_token1);

		//op->afficherPolonaise();
		//std::cout << std::endl;
	}

	_expression = op;

	//_expression->afficher_expression();

}


Expression::~Expression()
{
	delete _expression;
}

/** \brief Cr�ation d'un Operande, Constante ou Variable suivant si c'est un nombre ou pas
* \param exp char* : Caract�re � analyser
*/
Operande* Expression::newOpaDigOrChar(char* exp)
{
	if (isdigit(exp[0]))
		return new Constante(atof(exp));
	else
		return _tableV->getVariable(exp);
}

/** \brief Cr�ation d'un Operateur, suivant le caract�re de l'op�ration � r�aliser.
* \param exp char* : Caract�re � analyser
* \param A Operande* : Op�rande gauche de l'op�ration
* \param B Operande* : Op�rande droit de l'op�ration
*/
Operateur* Expression::newOperateur(char* exp, Operande* A, Operande* B)
{
	switch (exp[0])
	{
	case '+':
		return new Addition(A, B);
	case '-':
		return new Soustraction(A, B);
	case '*':
		return new Multiplication(A, B);
	case '/':
		return new Division(A, B);
	default:
		return NULL;
	}
}



void Expression::afficher_expression()
{
	_expression->afficher_expression();
}
void Expression::afficher()
{
	_expression->afficher();
}
void Expression::afficherSimple()
{
	_expression->afficherSimple();
}
void Expression::afficherPolonaise()
{
	_expression->afficherPolonaise();
}
void Expression::calculer()
{
	_expression->calculer();
}