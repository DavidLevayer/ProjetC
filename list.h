/* 
 * File:   list.h
 * Author: augustin
 *
 * Created on 29 mai 2013, 13:40
 */

#ifndef LIST_H
#define	LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct strCode {
	unsigned char *valeur;
        int longueur; // longueur de la chaine de caractere
} Code; 

typedef struct strucList{
    struct strCode* mot;
    int val;
    struct strucList* nextp;
}List;

typedef struct strDico{
    struct strucList* beginp;
    struct strucList* finalp;
}Dico;

//static Dico d;
Code* creationCodeInit(char i);
        
int initialiser();

int afficherListe();

int ajouterElement (Code prefix, char* mono);

int rechercher(Code prefix, char* mono, int *code);

char *codeVersChaine (Code code, int longueur);

Code sequenceVersCode (Code sequence, int longueur);

Code fusion (Code prefix, char* mono);
#endif