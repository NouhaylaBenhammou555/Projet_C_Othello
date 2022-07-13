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


void choisir_coupMachine (t_matrice m,int *lig,int *col,int joueur,char *nomF) {
    *lig=rand() % (7 + 1 - 0) + 0; //rand() % (max_number + 1 - minimum_number) + minimum_number
    *col=rand() % (7 + 1 - 0) + 0;
    /* On redemande de choisir tant que le coup n'est pas accepte */
    while (!coup_valide (m, *lig, *col, joueur)) {
       *lig=rand()% 8;
       *col=rand()%8;
   }

    // sauvgarder chaque coup pour visualiser la partie dans un fichier
      FILE *fichier;
      char *chemin=(char*)malloc(sizeof(char)*200);
      strcpy(chemin,"sauvgardeMouvement");
      strcat(chemin,nomF);
      strcat(chemin,".txt");
      fichier = fopen(chemin,"a");
           if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }
            fprintf(fichier,"%d %d\n",*col,*lig);
     fclose(fichier);

}
/*pour jouer contre la machine*/
void demarerLeJeuVsMachine(char *nom1,char *nom2,char *nomF,int n)
 {
 /* Initialisation du jeu */
            t_matrice m;
            int lig, col, joueur = 1;
            init_matrice (m);
            afficher_matrice (m);
            printf("si vous desirez quitter la partie, appuyer sur la touche q a tout moment\n");
            printf("si vous desirez recommencer la partie, appuyer sur la touche r a tout moment\n");
            /* Deroulement d'une partie */
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


