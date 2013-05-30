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
#include "list.h"

#endif

/**
*
*
**/
int compresser (FILE *fi, FILE *fo);

/**
*
*
**/
int decompresser (FILE *fi, FILE *fo);
