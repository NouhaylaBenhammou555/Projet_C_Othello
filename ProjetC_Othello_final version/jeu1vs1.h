#define N 8
typedef char t_matrice[N][N];

void init_matrice (t_matrice m);
void afficher_matrice (t_matrice m);
int case_existe (int lig, int col);
int coup_valide (t_matrice m, int lig, int col, int joueur);
int peut_jouer (t_matrice m, int joueur);
int joueur_suivant (int joueur);
void choisir_coup (t_matrice m, int *lig, int *col, int joueur,char *nom1,char *nom2,char *nomF,int n);
int partie_terminee (t_matrice m,char *nom1,char *nom2) ;
void jouer_coup (t_matrice m, int lig, int col, int joueur);
void demarerLeJeu(char *nom1,char *nom2,char *nomF,int n);


