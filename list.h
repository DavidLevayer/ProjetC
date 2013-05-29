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

typedef struct strucList{
    int val;
    struct strucList* nextp;
}List;

List* initialiser();
void afficherListe(List* l);

#endif

