/**
* Auteurs : Jérôme Barbier, Augustin Husson, Mehdi NS, David Levayer
* Date : 28/05/2013
* Projet : Compression
* Version : 1.0
**/

#include "lzw.h"

/**
*
*
**/
int compresser (FILE *fi, FILE *fo)
{
	Code w;
	char a;
	int code;
	
	// On récupère la taille du fichier à compresser
	//if (tailleFichier(fi, &nbOctets)!=0) return 1;

	// Initialisation du dictionnaire
	initialiser();

	// Initialisation des places disponibles dans le dictionnaire (pour un nombre de bits donné)
	int placesDisponibles = 512 - 256 - 10;

	w.valeur = malloc (sizeof(char));
	w.valeur[0] = fgetc(fi);
	w.taille = 1;
	while ((a = fgetc(fi)) != EOF)
	{

		if (rechercher(w,&a,&code))
		{
			w = fusion (w,&a); // w <--- w + a (avec taille++ inclu)
			continue;
		}
		else
		{
			rechercher(w,NULL,&code);
			//fprintf(fo,"%d.",code);
			ecrire(fo,code);

			placesDisponibles--;
			if (placesDisponibles==0) incNbBits();

			ajouterElement(w,&a);
			*w.valeur = a;
			w.taille = 1;
		}
		
	}
	rechercher(w,NULL,&code);
	//fprintf(fo,"%d",code);
	ecrire(fo,code);
	
	// Fin de fichier
	ecrire(fo,FIN);
	return 0;
}

/**
*
*
**/
int decompresser(FILE* fi, FILE* fo)
{

	int i,i2,lg,lg2;
	char a;
	Code w,w2;
	unsigned char *buffer;
	//unsigned char *buffer;
	
	// Initialisation du dictionnaire
	initialiser();
	
	// Traitement du premier caractère
	lire(fi,&i);
	//printf("Valeur de i : %d (hexa: %x)\n",i,i);
	a = codeVersChaine(i,&lg)[0];
	//printf("Valeur de a : %c\n",a);
	w.valeur = malloc(lg*sizeof(char));
	*w.valeur = a;
	w.taille = lg;
	//printf("w : %s (taille: %d)\n",w.valeur,w.taille);
	fwrite(w.valeur,1,1,fo);
	
	while (1)
	{
		
		lire(fi,&i2);

		if(i2==FIN) break;
		if(i2==INC) 
		{
			incNbBits();
			continue;
		}
		if(i2==RAZ) 
		{
			setNbBits(9);
			continue;
		}

		//printf("\nValeur de i' : %d (hexa: %x)\n",i2,i2);
		if (codeVersChaine(i2,&lg2)==NULL)
		{
			//printf("i' n'appartient pas à D\n");
			buffer = codeVersChaine(i,&lg);
			w2.valeur = malloc(lg*sizeof(char));
			w2.valeur = buffer;
			w2.taille = lg;
			w2 = fusion(w2,&a);
			//printf("w' : %s (taille: %d)\n",w2.valeur,w2.taille);
		}
		else
		{	
			//printf("i' appartient à D\n");
			buffer = codeVersChaine(i2,&lg2);
			w2.valeur = malloc(lg*sizeof(char));
			w2.valeur = buffer;
			w2.taille = lg2;
			//printf("w' : %s (taille: %d)\n",w2.valeur,w2.taille);
		}
		
		buffer = codeVersChaine(i,&lg);
		w.valeur = malloc(lg*sizeof(char));
		w.valeur = buffer;
		w.taille = lg;
		//printf("w : %s (taille: %d)\n",w.valeur,w.taille);

		fwrite(w2.valeur,w2.taille,1,fo);

		a = w2.valeur[0];
		//printf("Valeur de a : %c\n",a);
		//printf("Element ajouté au dico : %s%c\n",w.valeur,a);
		ajouterElement(w,&a);
		i = i2;
		lg = lg2;
		
		
	}
	return 0;
}
