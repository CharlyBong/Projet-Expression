/**
* \file Doxy_Second_Page.h
* \brief Compte-Rendu du projet
*
* Rendu du projet par une interface doxygen / HTML
* Page secondaire
*
* \author Charles Bong.
* \date 12 Mai 2015
*/


/*! \page Rendu Compte-Rendu du projet /-/ Charles Bongiorno
* \section intro_sec2 Introduction
*	Ce projet s'inscrit dans le cadre du module d'ouverture de C++.<br/>
*	Notre objectif principal �tait de traiter des expressions math�matiques simple.<br/>
*	Exemple : ( ( ( 6.5 * 2 ) - 8 ) + 7 )<br/>
*	<br/>
*	Ces expressions se limiteront aux op�rateurs arithm�tiques simple (addition, soustraction, multiplication, division)
*	avec des constantes flottantes et des variables.<br/>
*	Dans un premier temps, ces expressions seront cr��es en dur dans le code.<br/>
*	Pour ensuite �tre construite � partir d'une chaine de caract�res.<br/>
*	<br/>
*
*
* \section usecase_sec2 Cas d'utilisation
*	Lors du lancement du programme, vous serez invit� � entrer une expression algorithmique simple, en notation polonaise invers�.<br/>
*	Actuellement, il n'y a pas de traitement en cas d'erreur de saisie, merci de v�rifier vos entr�es.<br/>
*	Le programme va ensuite afficher l'expression sous diff�rentes formes.<br/>
*	De l'hypoth�se o� vous avez entr� des variables nomm�es, il vous sera propos� de leur assigner une valeur.<br/>
*	La programme affichera alors l'expression, avec un r�sultat.<br/>
*
*
*
*
* \section class_sec2 Repr�sentation des classes
*	Afin de r�pondre au sujet, nous avons effectu� une recherche sur un ensemble de classe pour mat�rialiser une expression math�matique.<br/>
*	Une expression est constitu� (au minimum) d'un op�rateur entre deux nombres.<br/>
*	Par exemple : <i>( 5 + 7 )</i> <br/>
*	<img alt="Diapositive1" src="images/Diapositive1.png"/><br/>
*	<br/>
*	Ici le + est l'op�rateur (encadr� en bleu) et les constances des op�randes (encadr� en violet).<br/>
*	<i>(nota: nous utiliserons le m�me code couleur pour les exemples suivants, et le vert sera utilis� pour les variables)</i><br/>
*	<br/>
*	Les op�rateurs qui seront utilis�s dans ce projet sont addition, soustraction, multiplication, division.<br/>
*	Nous allons donc avoir une classe m�re 'op�rateur' compos� de deux op�randes (droite et gauche) et des classes qui en h�riterons (+ - * /).<br/>
*	De m�me, nous aurons une classe g�n�rique 'op�rande' et des classes filles 'constante' et 'variable'.<br/>
*	<br/>
*	<br/>
*	Maintenant, prenons le cas d'une expression plus longue : <i>( ( 13 - 8 ) + 7 )</i> <br/>
*	<img alt="Diapositive2" src="images/Diapositive2.png"/><br/>
*	<br/>
*	Dans cette exemple, l'op�rateur '-' a remplac� l'op�rande '5'.<br/>
*	Nous g�n�ralisons donc un op�rateur comme une sorte d'op�rande.<br/>
*	Ainsi nous pouvons cascad� les op�rateurs les uns sous les autres afin de construire de longue expression.<br/>
*	<img alt="Diapositive3" src="images/Diapositive3.png"/><br/>
*	<br/>
*	<br/>
*	Nous arrivons donc � la repr�sentation statique des classes :<br/>
*	<img height="500px" alt="DiagramClassStatique.png" src="images/DiagramClassStatique.png"/>
*	<a href="images/DiagramClassStatique" TARGET=_BLANK><SMALL>(voir l'image)</SMALL></a><br/>
*
*
* \section detail_sec2 D�tails des classes
*
* \subsection exp_detail_sec2 Classe Expression
*	Fonction de cr�ation d'une expression � partir d'une chaine de caract�re Cette classe fait office d'interface pour l'utilisation des expressions.
* \subsubsection pub_exp_detail_sec2 Fonctions membres publiques
*			Expression (std::string exp) Cr�ation de la classe Expression. Permet d'analyser une expression sous forme d'une chaine de caract�re et d'en construire l'op�rande associ�e.<br/>
*	void 	afficher_expression ()<br/>
*	void 	afficher ()<br/>
*	void 	afficherPolonaise ()<br/>
*	void 	afficherSimple ()<br/>
*	void 	calculer ()<br/>
*
* \subsubsection pri_exp_detail_sec2 Fonctions membres priv�es
*	Operande * 	newOpaDigOrChar (char *exp)	Cr�ation d'un Operande, Constante ou Variable suivant si c'est un nombre ou pas. <br/>
*	Operateur * 	newOperateur (char *exp, Operande *A, Operande *B) 	Cr�ation d'un Operateur, suivant le caract�re de l'op�ration � r�aliser.<br/>
*
* \subsubsection att_exp_detail_sec2 Attributs priv�s
*	Operateur * 	_expression <br/>
*	Table_Variable * 	_tableV <br/>
*
*
* \subsection operande_detail_sec2 Classe Operande
*	Op�rande d'une op�ration.
* \subsubsection pub_operande_detail_sec2 Fonctions membres publiques
*	Operande ()<br/>
*	virtual 	~Operande ()<br/>
*	virtual void 	afficher ()=0 			Afficheur par d�faut de l'op�rande.<br/>
*	virtual void 	afficherPolonaise ()=0 	Afficheur de l'op�rande en version polonaise.<br/>
*	virtual void 	afficherSimple ()=0 	Afficheur de l'op�rande en mode simplifi�<br/>
*	virtual float 	calculer ()=0		 	Permet d'�ffectuer l'op�ration contenu.<br/>
*	
*
* \subsection const_detail_sec2 Classe Constante
*	H�ritage de Operande<br/>
*	Valeur d�finie d'une expression.
* \subsubsection pub_const_detail_sec2 Fonctions membres publiques
*	Constante (float value)<br/>
*	Constante (const Constante &o)<br/>
*	~Constante ()<br/>
*	void 	afficherPolonaise () 	Afficheur de l'op�rande en version polonaise.<br/>
*	void 	afficherSimple () 	Afficheur de l'op�rande en mode simplifi�.<br/>
*	float 	calculer () 	Permet d'�ffectuer l'op�ration contenu.<br/>
*
* \subsubsection att_const_detail_sec2 Attributs priv�s
*	float 	_valeur <br/>
*
*
* \subsection var_detail_sec2 Classe Variable
*	H�ritage de Operande<br/>
*	Valeur inconnue d'une expression La valeur assign� est d�fini � NULL par d�faut.
* \subsubsection pub_var_detail_sec2 Fonctions membres publiques
*	Variable (std::string name)	Constructeur par d�faut. <br/>
*	Variable (std::string name, float value)	Constructeur avanc�<br/>
*	~Variable () 	Destructeur.<br/>
*	void 	definir (float value) 	Assignation d'une valeur � la variable.<br/>
*	void 	afficher () 	Afficheur par d�faut de l'op�rande.<br/>
*	void 	afficherPolonaise () 	Afficheur de l'op�rande en version polonaise.<br/>
*	void 	afficherSimple () 	Afficheur de l'op�rande en mode simplifi�<br/>
*	float 	calculer () 	Permet d'�ffectuer l'op�ration contenu.<br/>
*
* \subsubsection att_var_detail_sec2 Attributs priv�s
*	std::string 	_name	<br/>
*	float 	_value = NULL	<br/>
*
*
* \subsection op_detail_sec2 Classe Operateur
*	H�ritage de Operande<br/>
*	Op�rateur d'une op�ration.
* \subsubsection pub_op_detail_sec2 Fonctions membres publiques
*	Operateur (void)<br/>
*	Operateur (Operande *op_gauche, Operande *op_droit)<br/>
*	Operateur (const Operateur &o)<br/>
*	virtual 	~Operateur ()<br/>
*	void 	afficher_expression () Affiche l'op�ration et son r�sultat.<br/>
*
* \subsubsection att_op_detail_sec2 Attributs prot�g�s
*	Operande * 	_op_gauche<br/>
*	Operande * 	_op_droit<br/>
*
*
* \subsection tblVar_detail_sec2 Classe Table_Variable
*	H�ritage de Singleton< Table_Variable ><br/>
*	Tableau des variables, association entre une lettre et une variable La gestion des variables se fait � l'aide d'une map qui associe une lettre avec un pointeur vers une variable.
* \subsubsection pub_tblVar_detail_sec2 Fonctions membres publiques
*	void 	setVariable (std::string name, float value) Assignation d'une valeur � une variable Recherche dans les variables enregistr�es (_listof) celle ayant comme nom 'name'. Assignation d'une valeur pour cette variable s'il elle existe, cr�ation de la variable dans le cas contraire.<br/>
*	Variable * 	getVariable (std::string name) 	Obtetion d'une variable Test l'existance d'une variable, la cr�e dans le cas contraire Et la retourne.<br/>
*	void 	destroyVariable (std::string name) 	Destruction d'une variable.<br/>
*	std::stack< std::string > 	getListVariableNonDef () 	Getter d'un la liste des variables n'ayant pas de valeur assigni�e Cr�ation d'un stack pour le retour (list). Parcours des variables enregistr�es (_listof). Ajout dans le stack des variables n'ayant pas de valeur assigni�e (item.second->calculer() == NULL). <br/>
*
* \subsubsection pri_tblVar_detail_sec2 Fonctions membres priv�es
*	Table_Variable ()<br/>
*	~Table_Variable ()<br/>
*
* \subsubsection att_tblVar_detail_sec2 Attributs priv�s
*	std::map< std::string, Variable * > 	_listof<br/>
*
*
* \section construc_sec2 Construction d'une expression � partir d'une chaine de caract�res
*	Voici le d�tail de la construction d'une expression � partir d'une chaine de caract�re.<br/>
*	Dans la version actuelle, ce programme ne sait traiter que les expressions sous forme polonaise invers�.<br/>
*	Nous utiliserons l'exemple <i>"10 X * 7 +"</i> <br/>
*	<i>( ( 10 * X ) + 7 )</i><br/>
*	<br/>
*	Je parcours ma chaine de gauche � droite, par bloc de trois.<br/>
*	Je trouverai ainsi, d'apr�s le sch�ma d'une notation polonaise invers� :<br/>
*	<ul>
*		<li>un premier op�rande</li>
*		<li>un second op�rande</li>
*		<li>un op�rateur</li>
*	</ul>
*	Pour chaque op�rande l'algorithme se demandera s'il s'agit d'une constante (nombre) ou d'une constante.<br/>
*	Dans le premier cas, il cr�era une nouvelle constante, dans le seconde, il utilisera la classe <b>Table_Variable</b> pour obtenir un pointeur vers une variable.<br/>
*	Ensuite, pour chaque op�rateur, un comparaison du caract�re permettra de connaitre l'op�ration � effectuer.<br/>
*	<br/>
*	Enfin, on recommence l'algorithme avec comme 1er op�rande, le pointeur vers l'op�rateur pr�c�demment cr�� ainsi que la suite de la chaine de caract�re.<br/>
*	<br/>
*	Voici une animation r�sumant l'algorithme:<br/>
*	<img alt="algo-construct" src="images/algo-construct.gif"/><br/>
*
*
* \section variables_sec2 Les variables
*	Les variables se comportent comme des constances, � l'exception pr�s que s'il n'y a pas de valeur d�fini, elles bloqueront le processus de calcul d'une expression.<br/>
*	Lors de leur initialisation, elle ne poss�de pas de valeur (d�fini � null dans le code) mais on pourra faire l'assignation � l'aide de la m�thode : void definir(float value)<br/>
*
* \subsection tbl_variables_sec2 Gestion avec la table des variables
*	Afin de mutualiser les variables, j'utilise un gestionnaire de variable. <br/>
*	Ce dernier sera un singleton afin qu'il n'y ai qu'une seule instance de la classe dans le programme.<br/>
*	Avec ceci, nous pourrons avoir une seule instance par variable m�me si nous utilisons plusieurs fois le m�me caract�re dans le programme.<br/>
*	<br/>
*	L'algorithme fonctionne � l'aide d'une map (sorte de tableau associatif) entre un caract�re (string) et une valeur (int).<br/>
*	Lors que l'on demande l'instance d'une variable avec son nom, le gestionnaire va regarder s'il poss�d� d�j� une variable avec ce nom.<br/>
*	Si c'est le cas, il retourne l'instance de la variable, sinon il cr�e une nouvelle instance, retient le pointeur et renvoit l'instance.<br/>
*
*
* \section parc_sec2 Parcours de l'expression
*	Afin d'afficher l'expression ou de calculer son r�sultat, il nous faut parcourir cette ensemble d'op�ration. Ce parcours va s'effectuer par r�cursivit�.<br/>
*	De mani�re g�n�rale, on demande l'information aux autres membres (op�rande gauche et droite), on ajoute notre information et on renvoie.<br/>
*	<br/>
*	Voici une  animation r�sumant l'algorithme:<br/>
*	<img alt="algo-affiche" src="images/algo-affiche.gif"/><br/>
*
* \subsection cal_parc_sec2 Cas de calculer
*	Lors de l'appel � la m�thode calculer, il y a aura quelques diff�rences de fonctionnement d� aux variables.<br/>
*	Comme vu pr�c�demment, par r�cursivit�, l'appel � la m�thode va se propager dans toute l'expression.<br/>
*	Pour une constante, la valeur de retour sera celle de la constante.<br/>
*	Pour un variable, si une valeur est assign�e, son comportement sera identique � une constante.<br/>
*	En revange, s'il n'y a pas de valeur assign�e, la valeur null sera renvoi� : la valeur est inconnue.<br/>
*	Enfin, pour un op�rateur, cela effectuera l'op�ration entre les deux op�randes, et retournera le r�sultat.<br/>
*	Une specificit� existe, s'il re�oit une valeur null d'un des deux op�randes, l'op�rateur renverra lui aussi la valeur null, afin d'indiquer que le calcul n'est pas possible.<br/>
*	De m�me une division par z�ro, retournera la valeur null pour les m�me raisons.<br/>
*	<br/>
*	Voici une  animation r�sumant l'algorithme dans le cas o� X a une valeur assign�e :<br/>
*	<img alt="algo-calculer" src="images/algo-calculer.gif"/><br/>
*	<br/>
*	Voici une  animation r�sumant l'algorithme dans le cas o� X n'a pas de une valeur assign�e :<br/>
*	<img alt="algo-calculer-null" src="images/algo-calculer-null.gif"/><br/>
*
*
* \section end_sec2 Cr�dits
*	Projet_Expression<br/>
*	Module d'ouverture C++<br/>
*	Isen-Toulon<br/>
*	Par Charles BONGIORNO<br/>
*
*
*
*  <br/><br/><br/><br/>
*/