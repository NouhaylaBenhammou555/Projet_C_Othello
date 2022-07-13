#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"jeu1vs1.h"
#include"jeu1vsMachine.h"
#include"sauvegarde.h"
#include"securite.h"



void menu(){
  printf("choisisser le mode que vous voulez:\n");
  printf("tapez 1 pour le mode: 1 vs 1\n");
  printf("tapez 2 pour le mode: 1 vs Machine\n");
}


/* Le main */
int main()
{ time_t t;
  srand((unsigned) time(&t));
  char nom1[20],nom2[20],nom[20],rep;
  char *nomF;
    nomF=(char*)malloc(70*sizeof(char));
  int n;
do{menu();
  scanf("%d",&n);
}while(n!=1 && n!=2);
    char *compte=(char*)malloc(sizeof(char)*20);
int a=1;
if(n==1){
for(int i=0;i<2;i++){
do{
printf("  %d joueur etes vous nouveau ou vous avez deja un compte ?(new/old)\n",a);
scanf("%s",compte);
getchar();
if(strcmp(compte,"new")==0){
        FichierSignIn(nom,a);
        break;}
else if(strcmp(compte,"old")==0){
        FichierSignUp(nom,a);
        break;}
}while(strcmp(compte,"new")!=0 || strcmp(compte,"old")!=0);
if(i==0) strcpy(nom1,nom);
else if(i==1)strcpy(nom2,nom);
a++;}
}
if(n==2){
do{
printf(" %d joueur etes vous nouveau ou vous avez deja un compte ?(new/old)\n",a);
scanf("%s",compte);
getchar();
if(strcmp(compte,"new")==0){
        FichierSignIn(nom,a);
        break;}
else if(strcmp(compte,"old")==0){
        FichierSignUp(nom,a);
        break;}
}while(strcmp(compte,"new")!=0 || strcmp(compte,"old")!=0);
 strcpy(nom1,nom);
 strcpy(nom2,"Machine");
}
   printf("voulez vous chargez une partie deja sauvegarder?:(y/n)\n");
   scanf("%c",&rep);
   getchar();
   if(rep=='y'){
   printf("donnez le nom du fichier(sauvgardeMouvementXXX)\n");
   scanf("%s",nomF);
   getchar();
   ChargePartieSauvegarder(nom1,nom2,nomF,n);}
   char rep1;
   printf("voulez vous sauvgarder la partie:(y/n)\n");
   scanf("%c",&rep1);
   getchar();
   if(rep1=='y' && rep !='y') {printf("donnez le nom ou vous voulez sauvgarder votre fichier:\n");
                  printf("le nom sera comme suit: sauvgardeMouvementXXXX\n");
                   scanf("%s",nomF);
                    getchar();}
    if(rep!='y') nomF="aSupprimer";
   printf("on commence le jeu:\n");
   if(n==1 && rep!='y') demarerLeJeu(nom1,nom2,nomF,n);
   else if(n==2 && rep!='y') demarerLeJeuVsMachine(nom1,nom2,nomF,n);
   visualiser(nomF);
   remove("sauvgardeMouvementaSupprimer.txt");
   return 0;
}
