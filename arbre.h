/* 
 * File:   arbre.h
 * Author: augustin
 *
 * Created on 31 mai 2013, 09:27
 */

#ifndef ARBRE_H
#define	ARBRE_H

#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TAB 256
#define TAILLE_TAB 10

#define FIN 0x100
#define INC 0x101
#define RAZ 0x102
#define NB_BIT_INIT 9
#define RESERVE 10
#define TAILLE_BIT_MAX 15


/*
 * valeur : chaine de caractere en non signé --->permet d'avoir les 255 caractères ascii
 * taille: longueur de la chaine de caractère
 */

typedef struct strCode {
	unsigned char *valeur;
        int taille;
} Code; 

typedef struct strArbre{
    struct strCode* mot;
    int val;
    struct strArbre* filsg;
    struct strArbre* filsd;
    struct strArbre* pere;
}Arbre;
/*
 * finalp : pointeur de fin d'arbre qui sert juste à faire une insertion en temps constant à l'initialisation
 */
typedef struct strDico{
    struct strArbre* beginp;
    struct strArbre* finalp;
}Dico;

Code* creationCodeInit(unsigned char* i,int taille);
        
int initialiser();
int supprimerDico();

int afficherChaine(unsigned char* chaine,int taille);

int rechercher(Code prefix, char* mono, int *code);
int ajouterElement (Code prefix, char* mono);

int rechercher(Code prefix, char* mono, int *code);

unsigned char *codeVersChaine (int code, int* longueur);

Code fusion (Code prefix, char* mono);

int reinitialiser();

int supprimerDico();
#endif	/* ARBRE_H */

