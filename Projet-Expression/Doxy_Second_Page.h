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
*	Notre objectif principal était de traiter des expressions mathématiques simple.<br/>
*	Exemple : ( ( ( 6.5 * 2 ) - 8 ) + 7 )<br/>
*	<br/>
*	Ces expressions se limiteront aux opérateurs arithmétiques simple (addition, soustraction, multiplication, division)
*	avec des constantes flottantes et des variables.<br/>
*	Dans un premier temps, ces expressions seront créées en dur dans le code.<br/>
*	Pour ensuite être construite à partir d'une chaine de caractères.<br/>
*	<br/>
*
*
* \section usecase_sec2 Cas d'utilisation
*	Lors du lancement du programme, vous serez invité à entrer une expression algorithmique simple, en notation polonaise inversé.<br/>
*	Actuellement, il n'y a pas de traitement en cas d'erreur de saisie, merci de vérifier vos entrées.<br/>
*	Le programme va ensuite afficher l'expression sous différentes formes.<br/>
*	De l'hypothèse où vous avez entré des variables nommées, il vous sera proposé de leur assigner une valeur.<br/>
*	La programme affichera alors l'expression, avec un résultat.<br/>
*
*
*
*
* \section class_sec2 Représentation des classes
*	Afin de répondre au sujet, nous avons effectué une recherche sur un ensemble de classe pour matérialiser une expression mathématique.<br/>
*	Une expression est constitué (au minimum) d'un opérateur entre deux nombres.<br/>
*	Par exemple : <i>( 5 + 7 )</i> <br/>
*	<img alt="Diapositive1" src="images/Diapositive1.png"/><br/>
*	<br/>
*	Ici le + est l'opérateur (encadré en bleu) et les constances des opérandes (encadré en violet).<br/>
*	<i>(nota: nous utiliserons le même code couleur pour les exemples suivants, et le vert sera utilisé pour les variables)</i><br/>
*	<br/>
*	Les opérateurs qui seront utilisés dans ce projet sont addition, soustraction, multiplication, division.<br/>
*	Nous allons donc avoir une classe mère 'opérateur' composé de deux opérandes (droite et gauche) et des classes qui en hériterons (+ - * /).<br/>
*	De même, nous aurons une classe générique 'opérande' et des classes filles 'constante' et 'variable'.<br/>
*	<br/>
*	<br/>
*	Maintenant, prenons le cas d'une expression plus longue : <i>( ( 13 - 8 ) + 7 )</i> <br/>
*	<img alt="Diapositive2" src="images/Diapositive2.png"/><br/>
*	<br/>
*	Dans cette exemple, l'opérateur '-' a remplacé l'opérande '5'.<br/>
*	Nous généralisons donc un opérateur comme une sorte d'opérande.<br/>
*	Ainsi nous pouvons cascadé les opérateurs les uns sous les autres afin de construire de longue expression.<br/>
*	<img alt="Diapositive3" src="images/Diapositive3.png"/><br/>
*	<br/>
*	<br/>
*	Nous arrivons donc à la représentation statique des classes :<br/>
*	<img height="500px" alt="DiagramClassStatique.png" src="images/DiagramClassStatique.png"/>
*	<a href="images/DiagramClassStatique" TARGET=_BLANK><SMALL>(voir l'image)</SMALL></a><br/>
*
*
* \section detail_sec2 Détails des classes
*
* \subsection exp_detail_sec2 Classe Expression
*	Fonction de création d'une expression à partir d'une chaine de caractére Cette classe fait office d'interface pour l'utilisation des expressions.
* \subsubsection pub_exp_detail_sec2 Fonctions membres publiques
*			Expression (std::string exp) Création de la classe Expression. Permet d'analyser une expression sous forme d'une chaine de caractère et d'en construire l'opérande associée.<br/>
*	void 	afficher_expression ()<br/>
*	void 	afficher ()<br/>
*	void 	afficherPolonaise ()<br/>
*	void 	afficherSimple ()<br/>
*	void 	calculer ()<br/>
*
* \subsubsection pri_exp_detail_sec2 Fonctions membres privées
*	Operande * 	newOpaDigOrChar (char *exp)	Création d'un Operande, Constante ou Variable suivant si c'est un nombre ou pas. <br/>
*	Operateur * 	newOperateur (char *exp, Operande *A, Operande *B) 	Création d'un Operateur, suivant le caractère de l'opération à réaliser.<br/>
*
* \subsubsection att_exp_detail_sec2 Attributs privés
*	Operateur * 	_expression <br/>
*	Table_Variable * 	_tableV <br/>
*
*
* \subsection operande_detail_sec2 Classe Operande
*	Opérande d'une opération.
* \subsubsection pub_operande_detail_sec2 Fonctions membres publiques
*	Operande ()<br/>
*	virtual 	~Operande ()<br/>
*	virtual void 	afficher ()=0 			Afficheur par défaut de l'opérande.<br/>
*	virtual void 	afficherPolonaise ()=0 	Afficheur de l'opérande en version polonaise.<br/>
*	virtual void 	afficherSimple ()=0 	Afficheur de l'opérande en mode simplifié<br/>
*	virtual float 	calculer ()=0		 	Permet d'éffectuer l'opération contenu.<br/>
*	
*
* \subsection const_detail_sec2 Classe Constante
*	Héritage de Operande<br/>
*	Valeur définie d'une expression.
* \subsubsection pub_const_detail_sec2 Fonctions membres publiques
*	Constante (float value)<br/>
*	Constante (const Constante &o)<br/>
*	~Constante ()<br/>
*	void 	afficherPolonaise () 	Afficheur de l'opérande en version polonaise.<br/>
*	void 	afficherSimple () 	Afficheur de l'opérande en mode simplifié.<br/>
*	float 	calculer () 	Permet d'éffectuer l'opération contenu.<br/>
*
* \subsubsection att_const_detail_sec2 Attributs privés
*	float 	_valeur <br/>
*
*
* \subsection var_detail_sec2 Classe Variable
*	Héritage de Operande<br/>
*	Valeur inconnue d'une expression La valeur assigné est défini à NULL par défaut.
* \subsubsection pub_var_detail_sec2 Fonctions membres publiques
*	Variable (std::string name)	Constructeur par défaut. <br/>
*	Variable (std::string name, float value)	Constructeur avancé<br/>
*	~Variable () 	Destructeur.<br/>
*	void 	definir (float value) 	Assignation d'une valeur à la variable.<br/>
*	void 	afficher () 	Afficheur par défaut de l'opérande.<br/>
*	void 	afficherPolonaise () 	Afficheur de l'opérande en version polonaise.<br/>
*	void 	afficherSimple () 	Afficheur de l'opérande en mode simplifié<br/>
*	float 	calculer () 	Permet d'éffectuer l'opération contenu.<br/>
*
* \subsubsection att_var_detail_sec2 Attributs privés
*	std::string 	_name	<br/>
*	float 	_value = NULL	<br/>
*
*
* \subsection op_detail_sec2 Classe Operateur
*	Héritage de Operande<br/>
*	Opérateur d'une opération.
* \subsubsection pub_op_detail_sec2 Fonctions membres publiques
*	Operateur (void)<br/>
*	Operateur (Operande *op_gauche, Operande *op_droit)<br/>
*	Operateur (const Operateur &o)<br/>
*	virtual 	~Operateur ()<br/>
*	void 	afficher_expression () Affiche l'opération et son résultat.<br/>
*
* \subsubsection att_op_detail_sec2 Attributs protégés
*	Operande * 	_op_gauche<br/>
*	Operande * 	_op_droit<br/>
*
*
* \subsection tblVar_detail_sec2 Classe Table_Variable
*	Héritage de Singleton< Table_Variable ><br/>
*	Tableau des variables, association entre une lettre et une variable La gestion des variables se fait à l'aide d'une map qui associe une lettre avec un pointeur vers une variable.
* \subsubsection pub_tblVar_detail_sec2 Fonctions membres publiques
*	void 	setVariable (std::string name, float value) Assignation d'une valeur à une variable Recherche dans les variables enregistrées (_listof) celle ayant comme nom 'name'. Assignation d'une valeur pour cette variable s'il elle existe, création de la variable dans le cas contraire.<br/>
*	Variable * 	getVariable (std::string name) 	Obtetion d'une variable Test l'existance d'une variable, la crée dans le cas contraire Et la retourne.<br/>
*	void 	destroyVariable (std::string name) 	Destruction d'une variable.<br/>
*	std::stack< std::string > 	getListVariableNonDef () 	Getter d'un la liste des variables n'ayant pas de valeur assigniée Création d'un stack pour le retour (list). Parcours des variables enregistrées (_listof). Ajout dans le stack des variables n'ayant pas de valeur assigniée (item.second->calculer() == NULL). <br/>
*
* \subsubsection pri_tblVar_detail_sec2 Fonctions membres privées
*	Table_Variable ()<br/>
*	~Table_Variable ()<br/>
*
* \subsubsection att_tblVar_detail_sec2 Attributs privés
*	std::map< std::string, Variable * > 	_listof<br/>
*
*
* \section construc_sec2 Construction d'une expression à partir d'une chaine de caractères
*	Voici le détail de la construction d'une expression à partir d'une chaine de caractère.<br/>
*	Dans la version actuelle, ce programme ne sait traiter que les expressions sous forme polonaise inversé.<br/>
*	Nous utiliserons l'exemple <i>"10 X * 7 +"</i> <br/>
*	<i>( ( 10 * X ) + 7 )</i><br/>
*	<br/>
*	Je parcours ma chaine de gauche à droite, par bloc de trois.<br/>
*	Je trouverai ainsi, d'après le schéma d'une notation polonaise inversé :<br/>
*	<ul>
*		<li>un premier opérande</li>
*		<li>un second opérande</li>
*		<li>un opérateur</li>
*	</ul>
*	Pour chaque opérande l'algorithme se demandera s'il s'agit d'une constante (nombre) ou d'une constante.<br/>
*	Dans le premier cas, il créera une nouvelle constante, dans le seconde, il utilisera la classe <b>Table_Variable</b> pour obtenir un pointeur vers une variable.<br/>
*	Ensuite, pour chaque opérateur, un comparaison du caractère permettra de connaitre l'opération à effectuer.<br/>
*	<br/>
*	Enfin, on recommence l'algorithme avec comme 1er opérande, le pointeur vers l'opérateur précédemment créé ainsi que la suite de la chaine de caractère.<br/>
*	<br/>
*	Voici une animation résumant l'algorithme:<br/>
*	<img alt="algo-construct" src="images/algo-construct.gif"/><br/>
*
*
* \section variables_sec2 Les variables
*	Les variables se comportent comme des constances, à l'exception près que s'il n'y a pas de valeur défini, elles bloqueront le processus de calcul d'une expression.<br/>
*	Lors de leur initialisation, elle ne possède pas de valeur (défini à null dans le code) mais on pourra faire l'assignation à l'aide de la méthode : void definir(float value)<br/>
*
* \subsection tbl_variables_sec2 Gestion avec la table des variables
*	Afin de mutualiser les variables, j'utilise un gestionnaire de variable. <br/>
*	Ce dernier sera un singleton afin qu'il n'y ai qu'une seule instance de la classe dans le programme.<br/>
*	Avec ceci, nous pourrons avoir une seule instance par variable même si nous utilisons plusieurs fois le même caractère dans le programme.<br/>
*	<br/>
*	L'algorithme fonctionne à l'aide d'une map (sorte de tableau associatif) entre un caractère (string) et une valeur (int).<br/>
*	Lors que l'on demande l'instance d'une variable avec son nom, le gestionnaire va regarder s'il possédé déjà une variable avec ce nom.<br/>
*	Si c'est le cas, il retourne l'instance de la variable, sinon il crée une nouvelle instance, retient le pointeur et renvoit l'instance.<br/>
*
*
* \section parc_sec2 Parcours de l'expression
*	Afin d'afficher l'expression ou de calculer son résultat, il nous faut parcourir cette ensemble d'opération. Ce parcours va s'effectuer par récursivité.<br/>
*	De manière générale, on demande l'information aux autres membres (opérande gauche et droite), on ajoute notre information et on renvoie.<br/>
*	<br/>
*	Voici une  animation résumant l'algorithme:<br/>
*	<img alt="algo-affiche" src="images/algo-affiche.gif"/><br/>
*
* \subsection cal_parc_sec2 Cas de calculer
*	Lors de l'appel à la méthode calculer, il y a aura quelques différences de fonctionnement dû aux variables.<br/>
*	Comme vu précédemment, par récursivité, l'appel à la méthode va se propager dans toute l'expression.<br/>
*	Pour une constante, la valeur de retour sera celle de la constante.<br/>
*	Pour un variable, si une valeur est assignée, son comportement sera identique à une constante.<br/>
*	En revange, s'il n'y a pas de valeur assignée, la valeur null sera renvoié : la valeur est inconnue.<br/>
*	Enfin, pour un opérateur, cela effectuera l'opération entre les deux opérandes, et retournera le résultat.<br/>
*	Une specificité existe, s'il reçoit une valeur null d'un des deux opérandes, l'opérateur renverra lui aussi la valeur null, afin d'indiquer que le calcul n'est pas possible.<br/>
*	De même une division par zéro, retournera la valeur null pour les même raisons.<br/>
*	<br/>
*	Voici une  animation résumant l'algorithme dans le cas où X a une valeur assignée :<br/>
*	<img alt="algo-calculer" src="images/algo-calculer.gif"/><br/>
*	<br/>
*	Voici une  animation résumant l'algorithme dans le cas où X n'a pas de une valeur assignée :<br/>
*	<img alt="algo-calculer-null" src="images/algo-calculer-null.gif"/><br/>
*
*
* \section end_sec2 Crédits
*	Projet_Expression<br/>
*	Module d'ouverture C++<br/>
*	Isen-Toulon<br/>
*	Par Charles BONGIORNO<br/>
*
*
*
*  <br/><br/><br/><br/>
*/