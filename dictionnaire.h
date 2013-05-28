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
} Code; 

/**
*
*
**/
int initialiser ();

/**
*
*
**/
int ajouterElement (Code element, Code mono, Code *longueur);

/**
*
*
**/
char *codeVersChaine (Code code, int longueur);

/**
*
*
**/
Code sequenceVersCode (char *sequence, int longueur);
