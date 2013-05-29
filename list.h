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
	char *valeur;
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

Dico initialiser();
void afficherListe(Dico l);

#endif

