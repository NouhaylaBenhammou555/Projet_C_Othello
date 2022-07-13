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

/* Retourne 1 si le nom et le mpd sont trouvée dans le fichier specifié, sinon 0 */
int chercherDansFichier(char *fileName,char *search,char *searchm) {

  FILE *f;
  int trouve=0;
  f = fopen(fileName,"r");
  char *buffn;
  char *buffmdp;
  buffn=(char*)malloc(45*sizeof(char));
  buffmdp=(char*)malloc(45*sizeof(char));
       if (f == NULL)
            {
               exit(EXIT_FAILURE);
            }
         while(!feof(f)){
         fscanf(f,"%s\n",buffn);
         fscanf(f,"%s\n",buffmdp);
         if(strcmp(buffn,search)==0 && strcmp(buffmdp,searchm)==0){
            trouve=1;
            break;}
         }

  fclose(f);
  return trouve;
}
/*si le joueur a deja un compte*/
void FichierSignUp(char *nom,int i){
    int k=0;
    char *mdp;
    mdp=(char*)malloc(45*sizeof(char));

  /*******************************************/
    FILE *fichier;
      fichier = fopen("ficheJoueurs.txt","a");
           if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }
         char *nomfichier;
         nomfichier="ficheJoueurs.txt";
         /***************************************/
    do{ k++;
      if(k>1) printf("le nom ou le mpd est incorrect\n");
    printf("donner le nom du %der joueur:\n",i);
    scanf("%s",nom);
    getchar();
    printf("donner votre mdp %s:\n",nom);
    scanf("%s",mdp);
    getchar();
  }while(chercherDansFichier(nomfichier,nom,mdp)!=1);

     fclose(fichier);
 }
/*si le joueur est nouveau*/
void FichierSignIn(char *nom,int i){
char *mdp;
int k=0;
    mdp=(char*)malloc(45*sizeof(char));

  /*******************************************/
    FILE *fichier;
      fichier = fopen("ficheJoueurs.txt","a");
           if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }
         char *nomfichier;
         nomfichier="ficheJoueurs.txt";
         /******************************/
          do{ k++;
      if(k>1) printf("le nom existe deja\n");
    printf("donner le nom du %der joueur:\n",i);
    scanf("%s",nom);
    getchar();
    printf("donner votre nouveau mdp %s:\n",nom);
    scanf("%s",mdp);
    getchar();
}while(chercherDansFichier(nomfichier,nom,mdp)==1);

    fprintf(fichier,"%s\n",nom);
    fprintf(fichier,"%s\n",mdp);


    fclose(fichier);
}
