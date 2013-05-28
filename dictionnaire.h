/**
* Auteurs : Augustin & Jerome
* Date : 28/05/2013
* Projet : Compression
* Version :
**/

#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
int ajouterElement (Code prefix, char* mono);

/*
 * 0 si pas trouver 1 sinon modifie int *code pour permettre la recuperation du code et renvoi 1
 */
int rechercher(Code prefix, char* mono, int *code);

/**
*
*
**/
char *codeVersChaine (Code code, int longueur);

/**
*
*
**/
Code sequenceVersCode (Code sequence, int longueur);

/**
*
*
**/
Code fusion (Code prefix, char* mono);
