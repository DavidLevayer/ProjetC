/**
* Auteurs :
* Date :
* Projet :
* Version :
**/

#ifndef FICHIER_H
#define FICHIER_H

#include <stdlib.h>
#include <stdio.h>
#include "dictionnaire.h"

#endif

/**
*
*
**/
FILE* ouvrir (char* nomFichier,int mode);

/**
*
*
**/
int fermer (FILE* fichier);


/**
*
*
**/
int tailleFichier(FILE* f, long* taille);

/**
*
*
**/
int ecrire(FILE* f, int v);
int creerMasque (int nbUn);

/**
*
*
**/
int lire (FILE* f, int* value);

int setNbBits(int valeur);
int incNbBits();
