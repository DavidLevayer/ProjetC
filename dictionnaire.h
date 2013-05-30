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

#define MAX_TAB 256
#define TAILLE_TAB 10

#define FIN 0x100
#define INC 0x101
#define RAZ 0x102


typedef struct strCode {
	unsigned char *valeur;
        int taille;
} Code; 



typedef struct strDico{
    Code* table;
    int taille;
	int indice;
}Dico;
/**
*
*
**/
int initialiser ();

void afficher ();
void afficherCode(Code c);
int compareCode(Code c1, Code c2);
/**
*ajoute l'élément s'il n'est pas présent ne fait rien sinon... retourne le numero du code que l'on souhaite ajouter
*
**/
int ajouterElement (Code prefix, char* mono);

/*
 * 0 si pas trouver 1 sinon
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

#endif
