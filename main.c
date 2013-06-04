#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"
#include "lzw.h"


int main(int argc, char **argv)
{
	int i;
	int oper = 0;
	int sortie = 0; //sortie = 1 : fichier de sortie, sortie = 0 : sortie standard
	int entree = 0; //entree = 1 : fichier d'entree, entree = 0 : entree standard
	char* fichierSortie;
	char* fichierEntree;
	FILE* fi;
	FILE* fo;

	if (argc==2 && strcmp("-h",argv[1])==0) 
	{
		printf("\n//////////////////////////////////////\n");
		printf("PROGRAMME DE (DE)COMPRESSION LZW :");
		printf("\n//////////////////////////////////////\n");
		printf("\nOptions :\n");
		printf("-c : compression\n");
		printf("-d : decompression\n");
		printf("-o : utilisation d'un fichier de sortie\n");
		printf("-h : aide\n\n\n");
		printf("Mode d'emploi : \n\n");
		printf("1) Pour compresser,\n");
		printf("\t-Un fichier  : \n\n");
		printf("\t\t./main fichier -c fichier -o fichierCompresse \n\t\t(Résultat dans le fichier fichierCompresse\n\n");
		printf("\t\t./main fichier -c fichier \n\t\t(Resultat sur sortie standard)\n\n");
		printf("\t-Sur entree standard (apres avoir tape une des commandes suivantes, taper le texte a compresser, puis taper Ctrl-D deux fois pour valider\n\n");
		printf("\t\t./main fichier -c -o fichierCompresse \n\t\t(Résultat dans le fichier fichierCompresse\n");
		printf("\t\t./main fichier -c \n\t\t(Resultat sur sortie standard) \n\n");
		printf("2) Pour decompresser, meme fonctionnement que pour la compression avec l'option -d au lieu de -c\n\n");
		return 0;
	}
	else 
	{
		//Gestion des options
		for(i=1;i<argc;i++)
		{
			if (argv[i][0]=='-')
				switch (argv[i][1])
				{
					case 'c': 
						oper = 1;
						break;
					case 'd':
						oper = 2;
						break;
					case 'o':
						fichierSortie = argv[i+1];
						i++;
						sortie = 1;
						break;
					default:
						printf("\nErreur : pour plus de renseignements, './main -h'\n");	
						return 0;		
				}					
			else
			{
				fichierEntree = argv[i];
				entree = 1;
			}
		}     
	}

	// Ouverture du flux d'entree
	if (oper!=0 && entree==1)
	{
		fi = ouvrir(fichierEntree,0);
		printf("Input : %s\n",fichierEntree); 
	}
	else if (oper!=0) // et entree==0
	{    
		fi = stdin;
		printf("Input : stdin\n"); 
	}
	else //oper==0
	{
		printf("Erreur : pour plus de renseignements, './main -h'\n");	
		return 42;
	}

	//Ouverture du flux de sortie
	if (sortie!=0)
	{
		fo = ouvrir(fichierSortie,1);
		printf("Output : %s\n",fichierSortie);
	}
	else
	{
		fo = stdout;
		printf("Output : stdout\n"); 
	}


	//Choix de l'operation a effectuer
	if (oper==1)
	{
		printf("Compression...\n");
		compresser(fi,fo);
	}
	else if (oper==2)
	{
		printf("Decompression...\n");
		decompresser(fi,fo);
	}

	//Fermeture du flux d'entree 
	if (entree==1)
		fermer(fi);

	//Fermeture du flux de sortie
	if (sortie==1)
		fermer(fo);

	return 0;
}