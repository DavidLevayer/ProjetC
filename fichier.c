#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"

/**
*
*
**/
FILE* ouvrir (char* nomFichier)
{
	FILE* f = NULL;
	f = fopen(nomFichier, "r");	
		
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
