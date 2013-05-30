/* 
 * File:   list.h
 * Author: augustin
 *
 * Created on 29 mai 2013, 13:40
 */

#ifndef LIST_H
#define	LIST_H
#define TAILLE_TAB 10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct strCode {
	unsigned char *valeur;
        int taille; // longueur de la chaine de caractere
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
Code* creationCodeInit(unsigned char* i,int taille);
        
int initialiser();


int afficherChaine(unsigned char* chaine,int taille);

int afficherListe();
int rechercher(Code prefix, char* mono, int *code);
int ajouterElement (Code prefix, char* mono);

int ajouterElement (Code prefix, char* mono);

int rechercher(Code prefix, char* mono, int *code);

unsigned char *codeVersChaine (int code, int* longueur);

Code sequenceVersCode (Code sequence, int longueur);

Code fusion (Code prefix, char* mono);
#endif
