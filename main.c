
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

int main(int argc, char **argv)
{
	#ifdef DEBUG
	printf("Salutations voyageur paix et guerison sur ton peuple\n");
	#endif
	int i;
	int oper = 0;
	int sortie = 0;
	int entree = 0;
	char* fichierSortie;
	char* fichierEntree;
	FILE* fi;
	FILE* fo;

	for(i=1;i<argc;i++) 
	{
		if (strcmp("-c",argv[i]) == 0) 
  			oper = 1;
		else if (strcmp("-d",argv[i]) == 0)
  			oper = 2;
		else if (strcmp("-o",argv[i]) == 0) 
		{
			fichierSortie = argv[i+1];
			i++;
			sortie = 1;
		}
		else
		{
			fichierEntree =  argv[i];
			entree = 1;
		}
	}		

	if (oper!=0 && entree==1) 
		fi = ouvrir(fichierEntree,0);
	else if (oper!=0)
		fi = stdin;
	else
	{
		printf("PAS D'OPERATION A EFFECTUER\n");
		return 42;
	} 
	
	if (sortie!=0)
		fo = ouvrir(fichierSortie,1);
	else 
		fo = stdout;


	if (oper==1)
		printf("Compression(fi,fo)\n");
	else if (oper==2)
		printf("Decompression(fi,fo)\n");

	
	if (entree==1)
		fermer(fi);
	if (sortie==1)
		fermer(fo);


	return 0;
}

