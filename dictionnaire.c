#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionnaire.h"


Code creationMot(int i,int taille){
    Code mot;
    mot.taille=taille;
    *mot.valeur=i;
    return mot;
}