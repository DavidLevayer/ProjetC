/**
* Auteurs :
* Date :
* Projet :
* Version :
**/

#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <stdlib.h>
#include <stdio.h>

#endif

typedef struct strCode {
	char *valeur;
        int taille;
} Code; 

/*
 * @mot : chaine de caractere ascii + taille de la chaine
 * @param : num est le numero du mot 
 */

typedef struct strCellule{
    Code mot;
    int num;
    struct Cellule* nextp;
}Cellule;
/*
 * @param : beginp : pointeur de debut de chaine
 * @param : finalp : pointeur vers la dernière cellule
 */
typedef struct strDico{
    Cellule* beginp;
    Cellule* finalp;
}Dico;
/**
*
*
**/
Dico initialiser ();

/**
*ajoute l'élément s'il n'est pas présent ne fait rien sinon... retourne le numero du code que l'on souhaite ajouter
*
**/
int ajouterElement (Code element, char* mono);

/*
 * 0 si pas trouver 1 sinon
 */
int rechercher(Code mot);

/**
*
*
**/
char *codeVersChaine (Code code, int longueur);

/**
*
*
**/
char* sequenceVersCode (Code sequence, int longueur);
