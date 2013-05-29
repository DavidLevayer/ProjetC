#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"

/**
*
* mode = 0 --< fichier existe "r" sinon "w"
**/
FILE* ouvrir (char* nomFichier, int mode)
{
	FILE* f = NULL;
	if (mode==0) f = fopen(nomFichier, "r");	
	else f = fopen(nomFichier, "w");
	
	if (f != NULL)
  {
  	return f;
  }
	else
	{
		printf("Erreur lors de l'ouverture du fichier %s\n",nomFichier);
		return NULL;
	}
}



/**
*
*
**/
int fermer (FILE* fichier)
{
	fclose(fichier);
}


int tailleFichier(FILE* f, long* taille)
{
	{
    /* Cette fonction retourne 0 en cas de succes, une valeur differente dans le cas contraire. */
    /* La taille du fichier, si elle a pu etre calculee, est retournee dans *taille                */

    int ret = 0;  

    if (f != NULL)
    {
        fseek(f, 0, SEEK_END); /* aller a la fin du fichier */
        *taille = ftell(f); /* lire l'offset de la position courante par rapport au debut du fichier */
 				rewind(f);
    }
    else
        ret = 1;
 
    return ret;
	}
}
