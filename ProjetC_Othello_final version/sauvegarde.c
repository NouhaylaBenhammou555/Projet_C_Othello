#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jeu1vs1.h"
#include"jeu1vsMachine.h"
#include"sauvegarde.h"
#include"securite.h"

/* Largeur de la grille */
#define N 8

/* Pions du jeu */
#define VIDE ' '
#define NOIR 'n'  /* joueur 1 */
#define BLANC 'b' /* joueur 2 */

/*fonction qui charge une partie sauvegarder*/
void ChargePartieSauvegarder(char *nom1,char *nom2,char *nomF,int n){
  t_matrice m;
  int lig, col, joueur = 1;
 FILE *fichier;
      char *chemin=(char*)malloc(sizeof(char)*200);
      strcpy(chemin,"sauvgardeMouvement");
      strcat(chemin,nomF);
      strcat(chemin,".txt");
      fichier = fopen(chemin,"r");
      int buff1;
      int buff2;
       init_matrice (m);
       if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }
         while(!feof(fichier))
         {fscanf(fichier,"%d %d",&buff1,&buff2);
              jouer_coup (m, buff2,buff1,joueur);
              joueur = joueur_suivant (joueur);}
              fclose(fichier);
              afficher_matrice (m);
         if(n==1){
         while (!partie_terminee (m,nom1,nom2)) {
                 choisir_coup (m, &lig, &col,joueur,nom1,nom2,nomF,n);
                 jouer_coup (m, lig, col, joueur);
                 afficher_matrice (m);
                 if (peut_jouer(m, joueur_suivant(joueur)))
                    joueur = joueur_suivant (joueur);
                 else printf ("\nLe joueur %d passe son tour\n", joueur_suivant(joueur));}
               }
           else if(n==2){
            while (!partie_terminee (m,nom1,nom2)) {
                 if(joueur==1)
                 choisir_coup (m, &lig, &col,joueur,nom1,nom2,nomF,n);
                 else if(joueur==2)
                 choisir_coupMachine (m,&lig,&col,joueur,nomF);
                 jouer_coup (m, lig, col, joueur);
                 afficher_matrice (m);
                 if (peut_jouer(m, joueur_suivant(joueur)))
                    joueur = joueur_suivant (joueur);
                 else printf ("\nLe joueur %d passe son tour\n", joueur_suivant(joueur));}

           }

}

/**********************************************************************************************************************/

int hscore[10];
/*fonction qui fait le trie pour avoir le top des 10 meilleures score*/
void top10scores(){
  int *T=(int*)malloc(sizeof(int));
  char *buffna;
  buffna=(char*)malloc(sizeof(char)*50);
  int buffs;
  int k=0;
   FILE *fi;
      fi = fopen("fichierScoreJoueur.txt","r");
           if (fi == NULL)
            {
               exit(EXIT_FAILURE);
            }
    while(!feof(fi)){
      fscanf(fi,"%s %d\n",buffna,&buffs);
       *(T+k)=buffs;
       k++;
    }
    fclose(fi);
    int tmp;
    for (int i=1 ; i <=k-1; i++) {
    int j = i;

    while (j > 0 && T[j-1] < T[j]) {
      tmp = T[j];
      T[j] = T[j-1];
      T[j-1] = tmp;
      j--;
    }
  }


  for(int n=0;n<10;n++){
    *(hscore+n)=*(T+n);
  }

  FILE *lefi;
      lefi= fopen("fichiertop10Score.txt","a");
           if (lefi == NULL)
            {
               exit(EXIT_FAILURE);
            }
    for(int t=0;t<10;t++){
    fprintf(lefi,"%d\n",hscore[t]);
    }
    fclose(lefi);
}

/* La fonction visualiser pour voir ll'historique de la partie */
void visualiser (char *nomF)
  {
     int t1;
     do{printf("voullez vous visualiser votre parties ?si oui tapez 1\n");
     printf("voullez vous visualiser les 10 top meilleures scores ?si oui tapez 2\n");
     printf("si vous voullez quitter appuyer ? si oui tapez 3\n ");
     scanf("%d",&t1);
     if (t1==1)
     {
       FILE *fichier;
       char *chemin=(char*)malloc(sizeof(char)*200);
      strcpy(chemin,"sauvgardeMouvement");
      strcat(chemin,nomF);
      strcat(chemin,".txt");
      fichier = fopen(chemin,"r");
      int buff1,buff2;
       if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }
         while(!feof(fichier))
         {fscanf(fichier,"%d %d",&buff1,&buff2);
         printf("%d %d\n",buff1,buff2);}

       fclose(fichier);
      }
      else if (t1==2){ top10scores();
         FILE *lefi;
         int buffer;
      lefi= fopen("fichiertop10Score.txt","r");
           if (lefi == NULL)
            {
               exit(EXIT_FAILURE);
            }
        while(!feof(lefi))
         {fscanf(lefi,"%d",&buffer);
         printf("%d \n",buffer);}
    fclose(lefi);
      }
      remove("fichiertop10Score.txt");
     }while(t1 !=3);
      printf("au revoir :)\n");

  }
