/*
 * Auteurs : Jérôme Barbier, Augustin Husson, David Levayer, Mehdi NS
 * Date : 03/06/2013
 * Projet : Compression de fichiers
 * Version : 1.0
 */

#ifndef FICHIER_H
#define FICHIER_H

#include <stdlib.h>
#include <stdio.h>
#include "dictionnaire.h"

/*
 * Ouvre le fichier dont le nom est passé en paramètre avec le mode souhaité
 * @param nomFichier le nom du fichier à ouvrir
 * @param mode le mode d'ouverture : 0 pour lecture, 1 pour écriture
 * @return le pointeur de fichier
 */
FILE* ouvrir (char* nomFichier,int mode);

/*
 * Ferme le fichier
 * @param fichier le pointeur de fichier à fermer
 * @return 0 si la fermeture s'est bien déroulée, != 0 sinon
 */
int fermer (FILE* fichier);

/*
 * Ecrit (en binaire) l'entier v dans le fichier pointé par f
 * @param f le pointeur sur le fichier (le fichier doit etre ouvert !)
 * @param v l'entier à écrire
 * @return 0 si OK
 */
int ecrire(FILE* f, int v);

int creerMasque (int nbUn);

/*
 * Lit (en binaire) la valeur courante présente dans le fichier pointé par f
 * @param f le pointeur sur le fichier (le fichier doit etre ouvert !)
 * @param value la valeur de l'entier lu
 * @return 0 si OK
 */
int lire (FILE* f, int* value);

/*
 * Modifie la valeur de nbBits
 * @param valeur la nouvelle valeur de nbBits
 * @return 0 si OK
 */
int setNbBits(int valeur);

/*
 * Incrémente nbBits
 * @return 0 si OK
 */
int incNbBits();

/*
 * Récupère la valeur de nbBits
 * @return nbBits
 */
int getNbBits ();

#endif
