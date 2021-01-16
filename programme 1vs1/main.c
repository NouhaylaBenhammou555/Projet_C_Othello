#include <stdio.h>
#include<stdlib.h>
/* Largeur de la grille */
#define N 8

/* Pions du jeu */
#define VIDE '.'
#define NOIR 'n'  /* joueur 1 */
#define BLANC 'b' /* joueur 2 */


void menu(){
    system("cls");
    printf("i-inserer vos informations personnelles \n");
    printf("c-commencer le jeu \n");
    printf("r-recommencer le jeu des le debut\n");   //ne sera fonctionnelle que si vous commencer le jeu
    printf("a-afficher la liste des joueurs \n");
    printf("t-top 10 meilleurs scores \n");
    printf("h-afficher historique des mouvements \n");
    printf("v-visualiser une partie sauvegardee precedemment\n");
    printf("q-quitter le jeu \n");
    printf("Veuillez choisir une option \n");
}

 // la structure

typedef struct ficheJoueur{
	J joueur;
    int score;      //score du joueur , initialisé par 0
    char nom[30];         // nom du joueur
    char mot_de_passe[10];        //mot de passe pour mieux sécuriser le jeu
    struct ficheJoueur *next;
}ficheJoueur;

// l'insersion dans un fichier


ficheJoueur* inserer(char* fiche_joueurs)
{
FILE* fichier= fopen("fiche_joueurs.txt","a");
if (fichier==NULL)
{
printf("le fichier est inexistant\n");
}
else
{
joueurs* liste_joueurs;
J joueur;
rewind(fichier);//ou fseek(fichier,0,SEEK_SET);
fscanf(fichier,"%s %s %d",joueur.nom,joueur.mdp,joueur.score);
liste_joueurs= add(joueur,liste_joueurs);
}
}
joueurs* add(J joueur , joueurs *liste_joueurs)
{
joueurs *save=(joueurs *)malloc(sizeof(joueurs));
joueurs *parcours;
strcpy(save->nom,joueur.nom);
strcpy(save->mdp,joueur.mdp);
strcpy(save->0,joueur.score);
save->next=NULL;
if(liste_joueurs==NULL)
{
liste_joueurs=save;
}
else
{
parcours=liste_joueurs;
while(parcours->next!=NULL)
{
parcours=parcours->next;
}
parcours->next=save;
}
}


// l'affichage

void afficherlistejoueurs()
{
   FILE* fichier = NULL;

    fichier = fopen("fiche_joueurs.txt", "r");
    fclose(fichier);
}



/* Type du plateau de jeu */
typedef char t_matrice[N][N];

/* Fonction pour initialiser la grille */
void init_matrice (t_matrice m) {
    int i, j;

    /* On met tout a vide */
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            m[i][j] = VIDE;

    /* On place les 4 premiers pions */
    m[N/2-1][N/2-1] = NOIR;
    m[N/2-1][N/2] = BLANC;
    m[N/2][N/2-1] = BLANC;
    m[N/2][N/2] = NOIR;
}

/* Fonction pour afficher la grille */
void afficher_matrice (t_matrice m) {
    int i, j;
    char a = 'A';

    /* Affichage des lettres */
    printf ("\n");
    for (i=0; i<N; i++) {
        printf ("  %c   ", a);
        a++;
    }

    /* Affichage de la grille */
    printf ("\n+");
    for (i=0; i<N; i++)
        printf ("-----+");
    printf ("\n");
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++)
            if (m[i][j] == BLANC){
                printf ("|");
                printf ("  %c  ", m[i][j]);}
            else{
                printf ("|");
                printf ("  %c  ", m[i][j]);}
        printf (" %d\n+", i+1);
        for (j=0; j<N; j++)
            {
            printf ("-----+");}
        printf ("|");
        printf ("\n");
    }
}

/* Fonction pour verifier qu'une case existe */
int case_existe (int lig, int col) {
    return ((col >= 0) && (col < N) && (lig >= 0) && (lig < N));
}

/* Fonction pour verifier qu'un coup est valide */
int coup_valide (t_matrice m, int lig, int col, int joueur) {
    int i, j, ok;
    char cj, ca;

    /* On definit la couleur du joueur et celle de l'adversaire */
    if (joueur == 1) {
        cj = NOIR;
        ca = BLANC;
    } else {
        cj = BLANC;
        ca = NOIR;
    }
    if (!case_existe(lig, col) || m[lig][col] != VIDE) return 0;

    /* Vertical vers le haut */
    i = lig - 1;
    ok = 0;
    while (case_existe(i, col) && m[i][col] == ca) {
        i--;
        ok = 1;
    }
    if (case_existe(i, col) && m[i][col] == cj && ok == 1) return 1;

    /* Vertical vers le bas */
    i = lig + 1;
    ok = 0;
    while (case_existe(i, col) && m[i][col] == ca) {
        i++;
        ok = 1;
    }
    if (case_existe(i, col) && m[i][col] == cj && ok == 1) return 1;

    /* Horizontal vers la gauche */
    j = col - 1;
    ok = 0;
    while (case_existe(lig, j) && m[lig][j] == ca) {
        j--;
        ok = 1;
    }
    if (case_existe(lig, j) && m[lig][j] == cj && ok == 1) return 1;

    /* Horizontal vers la droite */
    j = col + 1;
    ok = 0;
    while (case_existe(lig, j) && m[lig][j] == ca) {
        j++;
        ok = 1;
    }
    if (case_existe(lig, j) && m[lig][j] == cj && ok == 1) return 1;

    /* Diagonal \ vers le haut */
    i = lig - 1;
    j = col - 1;
    ok = 0;
    while (case_existe(i, j) && m[i][j] == ca) {
        i--;
        j--;
        ok = 1;
    }
    if (case_existe(i, j) && m[i][j] == cj && ok == 1) return 1;

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col + 1;
    ok = 0;
    while (case_existe(i, j) && m[i][j] == ca) {
        i++;
        j++;
        ok = 1;
    }
    if (case_existe(i, j) && m[i][j] == cj && ok == 1) return 1;

    /* Diagonal / vers le haut */
    i = lig - 1;
    j = col + 1;
    ok = 0;
    while (case_existe(i, j) && m[i][j] == ca) {
        i--;
        j++;
        ok = 1;
    }
    if (case_existe(i, j) && m[i][j] == cj && ok == 1) return 1;

    /* Diagonal / vers le bas */
    i = lig + 1;
    j = col - 1;
    ok = 0;
    while (case_existe(i, j) && m[i][j] == ca) {
        i++;
        j--;
        ok = 1;
    }
    if (case_existe(i, j) && m[i][j] == cj && ok == 1) return 1;

    return 0;
}

/* Fonction qui determine si un joueur peut encore jouer */
int peut_jouer (t_matrice m, int joueur) {
    int i, j;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            if (coup_valide(m, i, j, joueur)) return 1; /* Le joueur peut encore jouer */

    /* Le joueur ne peut plus jouer */
    return 0;
}

/* Renvoie le numero du joueur suivant */
int joueur_suivant (int joueur) {
    return (joueur %2 + 1);
}

/* Permet au joueur de choisir un coup */
void choisir_coup (t_matrice m, int *lig, int *col, int joueur) {
    char c;
    if (joueur==1)
        printf ("\nC'est au tour du joueur %d de jouer(noir)\n", joueur);
    else
        printf ("\nC'est au tour du joueur %d de jouer(blanc)\n", joueur);
    printf ("Choisissez une case (ex: A1) :\n");
    scanf ("\n%c", &c);
    if(c=='q') exit(0);
    /* On change les minuscules en majuscules */
    else if ((c >= 'a') && (c < 'a'+N))
        c = c + 'A' - 'a';
    (*col) = c - 'A';
    scanf ("%d", lig);
    (*lig)--;

    /* On redemande de choisir tant que le coup n'est pas accepte */
    while (!coup_valide (m, *lig, *col, joueur)) {
        printf ("\nCe coup n'est pas valide\n");
        printf ("Choisissez une autre case (ex: A1) :\n");
        scanf ("\n%c", &c);
        /* On change les minuscules en majuscules */
        if ((c >= 'a') && (c < 'a'+N))
            c = c + 'A' - 'a';
        (*col) = c - 'A';
        scanf ("%d", lig);
        (*lig)--;
    }
    const  int k=(*lig);
    // sauvgarder chaque pour visualiser la partie dans un fichier
      FILE *fichier;
      fichier = fopen("sauvegarde_Mouvements.txt", "a");
           if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }

           fprintf(fichier,"%c%d\n",c,(k+1));

     fclose(fichier);

}




/* Verifie si la partie est terminee */
int partie_terminee (t_matrice m) {
    int i, j, nb_noir, nb_blanc, cpt;


    /* On compte les pions noirs et les blancs */
    nb_noir = 0;
    nb_blanc = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (m[i][j] == VIDE && (peut_jouer(m, 1) || peut_jouer(m, 2))) {
                return 0; /* La partie n'est pas finie */
            } else {
                if (m[i][j] == NOIR) nb_noir++;
                else if (m[i][j] == BLANC) nb_blanc++;
            }
        }
    }

    /* La partie est terminee, on affiche le gagnant */
    if (nb_noir > nb_blanc)
        printf ("\nLe joueur 1 a gagne !!!\n");
    else if (nb_blanc > nb_noir)
        printf ("\nLe joueur 2 a gagne !!!\n");
    else printf ("\nLes deux joueurs sont a egalite\n");


    /* On range les pions par couleur et on affiche la grille */
    cpt = 0;
    for (i=0; i<N; i++)
        for (j=0; j<N; j++) {
            if (cpt < nb_noir)
                m[i][j] = NOIR;
            else if ((cpt >= nb_noir) && (cpt < nb_noir + nb_blanc -1))
                m[i][j] = BLANC;
            else m[i][j] = VIDE;
                cpt++;
        }
    afficher_matrice (m);
    printf ("\n");
    return 1;
}

/* Fonction qui permet de jouer un coup */
void jouer_coup (t_matrice m, int lig, int col, int joueur) {
    int i, j;
    char cj, ca;

    if (joueur == 1) {
        cj = NOIR;
        ca = BLANC;
    } else {
        cj = BLANC;
        ca = NOIR;
    }
    m[lig][col] = cj;

    /* Vertical vers le haut */
    i = lig - 1;
    while (case_existe(i, col) && m[i][col] == ca) i--;
    if (case_existe(i, col) && m[i][col] == cj) {
        i = lig - 1;
        while (m[i][col] == ca) {
            m[i][col] = cj;
            i--;
        }
    }

    /* Vertical vers le bas */
    i = lig + 1;
    while (case_existe(i, col) && m[i][col] == ca) i++;
    if (case_existe(i, col) && m[i][col] == cj) {
        i = lig + 1;
        while (m[i][col] == ca) {
            m[i][col] = cj;
            i++;
        }
    }

    /* Horizontal vers la gauche */
    j = col - 1;
    while (case_existe(lig, j) && m[lig][j] == ca) j--;
    if (case_existe(lig, j) && m[lig][j] == cj) {
        j = col - 1;
        while (m[lig][j] == ca) {
            m[lig][j] = cj;
            j--;
        }
    }

    /* Horizontal vers la droite */
    j = col + 1;
    while (case_existe(lig, j) && m[lig][j] == ca) j++;
    if (case_existe(lig, j) && m[lig][j] == cj) {
        j = col + 1;
        while (m[lig][j] == ca) {
            m[lig][j] = cj;
            j++;
        }
    }

    /* Diagonal \ vers le haut */
    i = lig - 1;
    j = col - 1;
    while (case_existe(i, j) && m[i][j] == ca) {
        i--;
        j--;
    }
    if (case_existe(i, j) && m[i][j] == cj) {
        i = lig - 1;
        j = col - 1;
        while (m[i][j] == ca) {
            m[i][j] = cj;
            i--;
            j--;
        }
    }

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col + 1;
    while (case_existe(i, j) && m[i][j] == ca) {
        i++;
        j++;
    }
    if (case_existe(i, j) && m[i][j] == cj) {
        i = lig + 1;
        j = col + 1;
        while (m[i][j] == ca) {
            m[i][j] = cj;
            i++;
            j++;
        }
    }

    /* Diagonal / vers le haut */
    i = lig - 1;
    j = col + 1;
    while (case_existe(i, j) && m[i][j] == ca) {
        i--;
        j++;
    }
    if (case_existe(i, j) && m[i][j] == cj) {
        i = lig - 1;
        j = col + 1;
        while (m[i][j] == ca) {
            m[i][j] = cj;
            i--;
            j++;
        }
    }

    /* Diagonal \ vers le bas */
    i = lig + 1;
    j = col - 1;
    while (case_existe(i, j) && m[i][j] == ca) {
        i++;
        j--;
    }
    if (case_existe(i, j) && m[i][j] == cj) {
        i = lig + 1;
        j = col - 1;
        while (m[i][j] == ca) {
            m[i][j] = cj;
            i++;
            j--;
        }
    }
}


/* La fonction visualiser */
void visualiser ()
  {
     char t1;
     printf("voulez vous visualiser vos parties ?si oui tapez oui\n");
     getchar();
     t1=getchar();
     if (t1=='o')
     {
       FILE *fichier;
       fichier = fopen("sauvegarde_Mouvements.txt", "r");
       char  buff[255];
       if (fichier == NULL)
            {
               exit(EXIT_FAILURE);
            }
         while(!feof(fichier))
         {fscanf(fichier,"%s",buff);
         printf("%s \n",buff);}

       fclose(fichier);
      }
  }






/* Le main */
int main()
{

    liste_joueur L1=NULL ;
    t_matrice m;
    int lig, col,score, joueur = 1;
    char nom[30];
    char mdp[10];
    int i,n,x;
    char touche;
    puts("donner le nombre des elements de la liste :");
    scanf("%d",&x);
    puts("donner les elements de la liste dans l'ordre nom-mpd :");
    for(i=0;i<x;i++){
        scanf("%s",&nom);
        scanf("%s",&mdp);

        insererNouveauJoueur(&L1,score,nom,mdp);
    }
    int tr=1;
  do
  {
    int  c , d  ;
    char mdp[10],nom[30],choix;
    menu();
    scanf("%c",&choix);
    switch(choix){
        case 'i':



                        system("cls");
                        puts("donner le joueur a inserer :");
                        scanf("%s",&nom);
                        scanf("%s",&mdp);

                        insererNouveauJoueur(&L1,score,nom,mdp);

                        break;

        case 'c':


            /* Initialisation du jeu */
            init_matrice (m);
            afficher_matrice (m);
            printf("si vous desirez quitter la partie, appuyer sur la touche q a tout moment\n");
            /* Deroulement d'une partie */
            while (!partie_terminee (m)) {
                 choisir_coup (m, &lig, &col, joueur);
                 jouer_coup (m, lig, col, joueur);
                 afficher_matrice (m);
                 printf("si vous desirez recommencer la partie, appuyer sur la touche r ,sinon cliquer sur entrer\n");
                 getchar();
                 touche=getchar();
                 printf("**************\n");
                 if(touche=='r'){ menu();
                                break;}
                 if (peut_jouer(m, joueur_suivant(joueur)))
                    joueur = joueur_suivant (joueur);
                 else printf ("\nLe joueur %d passe son tour\n", joueur_suivant(joueur));

           }

          break;

        case 'a':
              system("cls");
              afficherListeJoueurs(L1);

        break;

        case 'v':

             visualiser();
             printf("***\n");

        break;

        case'q':
            exit(0);
        break;

    }
    scanf("%d",&tr);
  }
   while(tr==1);

}
