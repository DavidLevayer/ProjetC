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

