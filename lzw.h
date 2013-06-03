/**
* Auteurs : Jérôme Barbier, Augustin Husson, Mehdi NS, David Levayer
* Date : 28/05/2013
* Projet : Compression
* Version : 1.0
**/

#ifndef LZW_H
#define LZW_H
 
#include <stdlib.h>
#include <stdio.h>

#include "fichier.h"
#include "dictionnaire.h"

/*
 * Compresse le fichier fi dans le fichier fo avec l'algorithme LZW
 * @param fi le pointeur du fichier d'entrée
 * @param fo le pointeur du fichier de sortie
 * @return 0 si OK
 */
int compresser (FILE *fi, FILE *fo);

/*
 * Decompresse le fichier fi dans le fichier fo avec l'algorithme LZW
 * @param fi le pointeur du fichier d'entrée
 * @param fo le pointeur du fichier de sortie
 * @return 0 si OK
 */
int decompresser (FILE *fi, FILE *fo);

#endif
