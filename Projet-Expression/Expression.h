/**
* \file Expression.h
* \brief Déclaration de la classe Expression
* \author Charles Bong.
* \date 5 Avril 2015
*/
#ifndef EXPRESSION
#define EXPRESSION

#include <string>
#include "Operande.h"
#include "Operateur.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Soustraction.h"
#include "Division.h"
#include "Constante.h"
#include "Variable.h"
#include "Table_Variable.h"


/** \class Expression
* \brief Fonction de création d'une expression à partir d'une chaine de caractére
*	Cette classe fait office d'interface pour l'utilisation des expressions
* \author Charles Bong.
* \date 5 Avril 2015
*/
class Expression
{
public:
	Expression(std::string exp);
	~Expression();

	void afficher_expression();
	void afficher();
	void afficherPolonaise();
	void afficherSimple();
	void calculer();
	
private:
	Operateur* _expression;	
	Table_Variable* _tableV;

	Operande* newOpaDigOrChar(char* exp);
	Operateur* newOperateur(char* exp, Operande* A, Operande* B);
};

#endif