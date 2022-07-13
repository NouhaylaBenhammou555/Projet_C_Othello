#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//COUPS POSSIBLES : 
int coup_possible ( int Tab[8][8], int joueur, int coup[120]){

    int i, j, r , s , m=0, k, nbre_coups = 0;    

    for ( k=0 ; k<120 ; k++){
        coup[k] = 0;
    }

        for ( i=0 ; i<8 ; i++){
            for ( j=0 ; j<8 ; j++){

                int joueur1, joueur2;

                switch(joueur){
                    case 1: joueur1 = 1; joueur2 = 2; break;
                    case 2: joueur1 = 2; joueur2 = 1; break;
                }

                if ( Tab[i][j] == joueur1) {
                    
                    //PARCOURIR A DROITE : 
                    r=i ;
                    s=j+1 ;
                    while ( s<7 && Tab[r][s] == joueur2){
                        s+=1 ;
                    }
                    if (Tab[r][s]== 0 && s!= j+1){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4;
                        nbre_coups++;
                    }

                    //PARCOURIR A GAUCHE : 
                    r=i ;
                    s=j-1 ;
                    while (  s>0 && Tab[r][s] == joueur2){
                        s-=1 ;
                    }
                    if (Tab[r][s] == 0 && s!= j-1 ){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4 ;
                        nbre_coups++;
                    }
                
                    //PARCOURIR EN BAS : 
                    r=i+1 ;
                    s=j ;
                    while ( r<7 && Tab[r][s] == joueur2 ){
                        r+=1 ;
                    }
                    if (Tab[r][s] == 0 && r!= i+1){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4 ;
                        nbre_coups++;
                    }

                    //PARCOURIR EN HAUT :
                    r=i-1 ;
                    s=j ;
                    while ( r>0 && Tab[r][s] == joueur2){
                        r-=1 ;
                    }
                    if (Tab[r][s] == 0 && r!= i-1){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4 ;
                        nbre_coups++;
                    }

                    //PARCOURIR DIAGINALEMENT  EN BAS A DROITE : 
                    r=i+1 ;
                    s=j+1 ;
                    while (  r<7 &&  s<7 && Tab[r][s] == joueur2 ){
                        s+=1 ;
                        r+=1 ;
                    }
                    if (Tab[r][s] == 0 && s!= j+1 && r!= i+1){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4 ;
                        nbre_coups++;
                    }

                    //PARCOURIR DIAGONALEMENT  EN HAUT A GAUCHE : 
                    r=i-1 ;
                    s=j-1 ;
                    while (  r>0 &&  s>0 && Tab[r][s] == joueur2){
                        s-=1 ;
                        r-=1 ;
                    }
                    if (Tab[r][s] == 0 && s!= j-1 && s!= j-1){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4 ;
                        nbre_coups++;
                    }

                    //PARCOURIR DIAGONALEMENT EN HAUT A DROITE : 
                    r=i-1 ;
                    s=j+1 ;
                    while (  r>0 && s<7 && Tab[r][s] == joueur2){
                        s+=1 ;
                        r-=1 ;
                    }
                    if (Tab[r][s] == 0 && s!= j+1 && r!= i-1){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4 ;
                        nbre_coups++;
                    }

                    //PARCOURIR EN BAS A GOUCHE : 
                    r=i+1 ;
                    s=j-1 ;
                    while (s>0 && r<7 && Tab[r][s] == joueur2){
                        s-=1 ;
                        r+=1 ;
                    }
                    if (Tab[r][s] == 0 && s!= j-1 && s!= i+1){
                        coup[m]=i ;
                        coup[m+1]= j ;
                        coup[m+2]= r ;
                        coup[m+3]= s ;
                        m+=4 ;
                        nbre_coups++;
                    }             
                }
            }
        }

    return  nbre_coups;
}

//REMPLISSAGE DU TABLEAU AVEC LES COUPS POSSIBLES : 
void newtab(int Tab[8][8], int coup[120], int nbre_coups){
    for (int i =2 ; i < 4*nbre_coups - 1 ; i+=4){
        Tab[coup[i]][coup[i+1]] = 3 ;  
    }
}

//AFFICHAGE DU TABLEAU QLQ : 
void affichage_tableau(int Tab[8][8]){

    int i,j;
    printf("\n");
    printf("\t\nVoici le tableau de jeu : \n");
    printf("\n");
    for(i=0;i<8;i++){
        printf("\t---------------------------------------------------------------\n");
        printf("\t---------------------------------------------------------------\n");
        for(j=0;j<8;j++){
            printf("\t");
            printf("|  %d  |", Tab[i][j]);
        }
        printf("\n");
    }
    printf("\t---------------------------------------------------------------\n");
    printf("\t---------------------------------------------------------------\n");
    printf("\n");

}

//CHANGEMENT DES COUPS : 
void changement ( int Tab[8][8] , int coup[120] ,int joueur, int x , int y ){
    int a , b ;
    for ( int i=2 ; i<120 ; i+=4 ){
        if (coup[i] == x && coup[i+1] == y ){
            a=coup[i-2];
            b=coup[i-1];

            //VERTICALEMENT : 
            if ( b==y ){
                if ( a > x) {
                    for ( int j=x+1 ; j<a ; j++){
                        Tab[j][y] = joueur ;
                    }
                }
                else {
                    for ( int j=a+1 ; j<x ; j++){
                        Tab[j][y] = joueur ;
                    }                
                }
            }

            //HORIZONTALEMENT :
            if ( a==x ){
                if ( b > y) {
                    for ( int j=y+1 ; j<b ; j++){
                        Tab[x][j] = joueur ;
                    }
                }
                else {
                    for ( int j=b+1 ; j<y ; j++){
                        Tab[x][j] = joueur ;
                    }                
                }
            }

            //DIAONALE NORMALE : 
            if (a-x==b-y){
                if ( b > y ){
                    for ( int j=y+1 ; j<b ; j++){
                        x+=1 ;
                        Tab[x][j] = joueur;
                    }
                    x=coup[i] ;
                }
                else {
                    for ( int j=y+1 ; j<b ; j--){
                        x-=1 ;
                        Tab[x][j]=2;
                    }
                    x=coup[i] ;
                }
            }

            //DIAGONALE INVERSE : 
            if (a-x==y-b){
                if ( b > y ){
                    for ( int j=y+1 ; j<b ; j++){
                        x-=1 ;
                        Tab[x][j]=joueur;
                    }
                    x=coup[i] ;
                }
                else {
                    for ( int j=y+1 ; j<b ; j--){
                        x+=1 ;
                        Tab[x][j]=joueur;
                    }
                    x=coup[i] ;
                }
            }
        }   
    }
}

//LE COUP JOUE PAR LE JOUEUR :  
void jouer(int Tab[8][8] , int coup[120] , int joueur ){

    int x ,y , n , a=0, k, j;

    suppression_coups_possibles(Tab);
    
    switch(joueur){
        case 2 : 
            while(a == 0){ 
                printf("\n ------------------------->  C'est le tour du NOIR  <-------------------------\n ");
                printf("\n Donner x : ");
                scanf("%d" , &x);
                printf("\n Donner y : ");
                scanf("%d", &y);
                for ( int i=2 ; i<120 ; i+=4 ){
                    if (coup[i] == x && coup[i+1] == y ){
                        Tab[x][y] = 2 ;
                        a=1 ;
                        break ;
                    }              
                } 
                if( a == 0){
                    printf("\t\nXXXXXXXXXX  Oups !!! cordonnees invalides  XXXXXXXXXX") ;
                    printf("\t\nXXXXXXXXXX      Veuillez reessayer svp     XXXXXXXXXX\n");
                }
            }
            break;

        case 1 : 
            while(a == 0){ 
                printf("\n ------------------------->  C'est le tour du BLANC  <-------------------------\n ");
                printf("\n Donner x : ");
                scanf("%d" , &x);
                printf("\n Donner y : ");
                scanf("%d", &y);
                for ( int i=2 ; i<120 ; i+=4 ){
                    if (coup[i] == x && coup[i+1] == y ){
                        Tab[x][y] = 1 ;
                        a=1 ;
                        break ;
                    }              
                } 
                if( a == 0){
                    printf("\t\nXXXXXXXXXX  Oups !!! cordonnees invalides  XXXXXXXXXX") ;
                    printf("\t\nXXXXXXXXXX      Veuillez reessayer svp     XXXXXXXXXX\n");
                }
            }
            break;
    }


    changement(Tab, coup, joueur, x, y );

    score(Tab);

}

void suppression_coups_possibles(int Tab[8][8]){

    int i, j;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(Tab[i][j] == 3) Tab[i][j] = 0;
        }
    }

}

void score(int Tab[8][8]){

    int i, j, BLANC = 0, NOIR = 0;
    
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(Tab[i][j] == 1) BLANC++ ;
            if(Tab[i][j] == 2) NOIR++ ;
        }
    }
    printf("\t\n----------------->   TABLEAU DU SCORE :  NOIR : %d  |  BLANC : %d   <-----------------", NOIR, BLANC );
}



