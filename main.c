#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"
#include "lzw.h"



int main(int argc, char **argv)
{
    int i;
    int oper = 0;
    int sortie = 0;
    int entree = 0;
    char* fichierSortie;
    char* fichierEntree;
    FILE* fi;
    FILE* fo;

    if (argc==1) {
      fi = ouvrir("main",0);
      fo = ouvrir("mainCompr",1);
      compresser(fi,fo);
			fclose(fi);
			fclose(fo);
			FILE* fo2;
			fo = ouvrir("mainCompr",0);
			fo2 = ouvrir("mainDecompr",1);
			decompresser(fo,fo2);
			fclose(fo);
			fclose(fo2);
      return 0;
    }
    else if (argc==2 && strcmp("-h",argv[1])==0) {
      printf("\n//////////////////////////////////////\nPROGRAMME DE (DE)COMPRESSION LZW :\n//////////////////////////////////////\n\nOptions :\n-c : compression\n-d : decompression\n-o : utilisation d'un fichier de sortie\n-h : aide\n\n\nMode d'emploi : \n\n1) Pour compresser,\n\t-Un fichier  : \n\n\t\t./main fichier -c fichier -o fichierCompresse \n\t\t(Résultat dans le fichier fichierCompresse) \n\n\t\t./main fichier -c fichier \n\t\t(Resultat sur sortie standard)\n\n\t-Sur entree standard (apres avoir tape une des commandes suivantes, taper le texte a compresser, puis taper Ctrl-D deux fois pour valider et lancer la compression)\n\n\t\t./main fichier -c -o fichierCompresse \n\t\t(Résultat dans le fichier fichierCompresse) \n\t\t./main fichier -c \n\t\t(Resultat sur sortie standard) \n\n2) Pour decompresser, meme foctionnement que pour la compression avec l'option -d au lieu de -c\n\n");
	return 0;
}
else 
    {
    
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
    }

    if (oper!=0 && entree==1)
    {    fi = ouvrir(fichierEntree,0); printf("Input : %s\n",fichierEntree); }
    else if (oper!=0)
    {    fi = stdin; printf("Input : stdin\n"); }
    else
    {
        printf("PAS D'OPERATION A EFFECTUER\n");
        return 42;
    }
   
    if (sortie!=0)
    {    fo = ouvrir(fichierSortie,1); printf("Output : %s\n",fichierSortie);}
    else
    {    fo = stdout; printf("Output : stdout\n"); }




	if (oper==1)
		{printf("Compression...\n");compresser(fi,fo);}
	else if (oper==2)
		{printf("Decompression...\n");decompresser(fi,fo);}
   
    if (entree==1)
        fermer(fi);
    if (sortie==1)
        fermer(fo);
		

    return 0;
}
