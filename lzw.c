/**
* Auteurs : Jérôme Barbier, Augustin Husson, Mehdi NS, David Levayer
* Date : 03/06/2013
* Projet : Compression
* Version : 1.0
**/

#include "lzw.h"

/*
 * Compresse le fichier fi dans le fichier fo avec l'algorithme LZW
 * @param fi le pointeur du fichier d'entrée
 * @param fo le pointeur du fichier de sortie
 * @return 0 si OK
 */
int compresser (FILE *fi, FILE *fo)
{
	Code w;
	int a;
	int code;
	int nbBitsCourant = 0;
	int nbOctetsCompresses = 0;
	int tailleFichierSortie = 0;

	// Initialisation du dictionnaire
	initialiser();

	// Initialisation des places disponibles dans le dictionnaire (pour un nombre de bits donné)
	int placesDisponibles = (1<<NB_BIT_INIT) - 256 - RESERVE; // 2^9 - 2^8 (mono-octets) - 10 (reservé)

	w.valeur = malloc (sizeof(char));
	w.valeur[0] = fgetc(fi);
	w.taille = 1;
	while ((a = fgetc(fi)) != EOF)
	{
		nbOctetsCompresses++;
		tailleFichierSortie+=getNbBits();

		if (rechercher(w,(char*)&a,&code))
			w = fusion (w,(char*)&a); // w <--- w + a (avec taille++ inclu)

		else
		{
			if(!rechercher(w,NULL,&code))
			{	
				printf("Erreur fatale\n");
				exit(0);
			}

			nbBitsCourant+=getNbBits();
			ecrire(fo,code);	

			if (placesDisponibles==0) 
			{
				if (getNbBits()<TAILLE_BIT_MAX+1)
				{
					placesDisponibles = 1 << getNbBits();
					nbBitsCourant+=getNbBits();
					ecrire(fo,INC);
					incNbBits();
				}
				else
				{
					placesDisponibles = (1<<NB_BIT_INIT) - 256 - RESERVE;
					ecrire(fo,RAZ);
					setNbBits(NB_BIT_INIT);
					reinitialiser();
				}
			}

			ajouterElement(w,(char*)&a);
			*w.valeur = a;
			w.taille = 1;
			placesDisponibles--;
		}
	}

	// Traiter dernier
	rechercher(w,NULL,&code);
	nbBitsCourant+=getNbBits();
	ecrire(fo,code);
	nbOctetsCompresses++;

	// Fin de fichier
	nbBitsCourant+=getNbBits();
	ecrire(fo,FIN);

	// Statistiques
	printf("Nombre d'octets traités : %d\n",nbOctetsCompresses);
	printf("Taille du ficher de sortie : %d (%d octets)\n",tailleFichierSortie,tailleFichierSortie/8);
	supprimerDico();	
	return 0;
}

/*
 * Decompresse le fichier fi dans le fichier fo avec l'algorithme LZW
 * @param fi le pointeur du fichier d'entrée
 * @param fo le pointeur du fichier de sortie
 * @return 0 si OK
 */
int decompresser(FILE* fi, FILE* fo)
{

	int i,i2,lg,lg2,j;
	int a;
	Code w,w2;
	unsigned char *buffer;

	int nbOctetsExtraits = 0;

	// Initialisation du dictionnaire
	initialiser();
	
	// Traitement du premier caractère
	lire(fi,&i); 
	a = codeVersChaine(i,&lg)[0];
	w.valeur = malloc(lg*sizeof(char));
	*w.valeur = a;
	w.taille = lg;
	fwrite(w.valeur,1,1,fo);
	
	while (1)
	{
		lire(fi,&i2); 
		nbOctetsExtraits++;

		if(i2==FIN) 
			break;
		
		else if(i2==INC) 
			incNbBits();

		else if(i2==RAZ) 
			setNbBits(NB_BIT_INIT);
		
		else 
		{
			buffer = codeVersChaine(i2,&lg2);
			if (lg2==0)
			{
				buffer = codeVersChaine(i,&lg);
				w2.valeur = malloc(lg*sizeof(char));

				w2.taille = lg;
				for(j=0;j<w2.taille;j++)
					w2.valeur[j] = buffer[j];
			
				w2 = fusion(w2,(char*)&a);
			}
			else
			{	
				w2.valeur = malloc(lg2*sizeof(char));		
				w2.taille = lg2;
				for(j=0;j<w2.taille;j++)
					w2.valeur[j] = buffer[j];

				buffer = codeVersChaine(i,&lg);
			}
		
			
			w.valeur = malloc(lg*sizeof(char));
		
			w.taille = lg;
			for(j=0;j<w.taille;j++)
				w.valeur[j] = buffer[j];

			for(j=0;j<w2.taille;j++)
			{
				fwrite(w2.valeur+j,1,1,fo);
			}

			a = w2.valeur[0];
			ajouterElement(w,(char*)&a);
			i = i2;
			lg = lg2;
		}
		
	}

	printf("Nombre d'octets traités : %d\n",nbOctetsExtraits);
	supprimerDico();
	return 0;
}
