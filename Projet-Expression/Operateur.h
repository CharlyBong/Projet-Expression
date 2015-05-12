/**
* \file Operateur.h
* \brief D�claration de la classe Operateur
* \author Charles Bong.
* \date 14 Mars 2015
*/
#ifndef OPERATEUR
#define OPERATEUR
#include "Operande.h"

/** \class Operateur
* \brief Op�rateur d'une op�ration
* \author Charles Bong.
* \date 14 Mars 2015
*/
class Operateur :
	public Operande
{
public:
	Operateur(void) {};
	Operateur(Operande* op_gauche, Operande* op_droit)
	{
		_op_gauche = op_gauche;
		_op_droit = op_droit;
	};
	Operateur(const Operateur &o)
	{
		_op_droit = o._op_droit;
		_op_gauche = o._op_gauche;
	};
	virtual ~Operateur() {
		_op_gauche = NULL;
		_op_droit = NULL;
	};

	/** \brief Affiche l'op�ration et son r�sultat */
	void afficher_expression() 
	{
		afficher();
		float result = calculer();
		if (result != NULL) 
			std::cout << " = " << result << std::endl;
		else
			std::cout << "   -inconnu- " << std::endl;
	};

	Operande* _op_gauche;
	Operande* _op_droit;
};

#endif