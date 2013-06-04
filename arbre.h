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
#include <string.h>

#define FIN 0x100
#define INC 0x101
#define RAZ 0x102

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
    //unsigned char *valeur;
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

Code* creationCodeInit(unsigned char* car,int taille);

int ajouterElement (Code prefix,unsigned char* mono);

int initialiser();

int rechercher(Code prefix, unsigned char* mono, int *code);

unsigned char *codeVersChaine (int code, int* longueur);

int afficherArbre();
#endif	/* ARBRE_H */

