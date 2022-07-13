#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#include "functions.h"
#include "buttons.h"


// 0 ---> VIDE 
// 1 ---> BLANC
// 2 ---> NOIR 
// 3 ---> COUPS POSSIBLES 

void main(){

    int tab1[8][8], i, j, joueur = 2, nbr_case = 4,  les_coups;
    int *coup= (int*) malloc(120*sizeof(int));

    //INITIALISATION DU JEU : 
    tab_init(tab1);
    //data_backup(tab1);
    affichage_tableau(tab1);

    //JOUER A TOUR DE ROLE : 
    while( nbr_case < 65 ){

        switch(joueur){

            //LE TOUR DU NOIR :
            case 1 : 
                les_coups = coup_possible(tab1, 1, coup) ;
                newtab(tab1, coup, les_coups);
                affichage_tableau(tab1);
                jouer (tab1 , coup , 1) ;
                affichage_tableau(tab1);
                joueur = 2;
                nbr_case++;
                break;

            //LE TOUR DU BLANC :
            case 2 : 
                les_coups = coup_possible(tab1, 2, coup) ;
                newtab(tab1, coup, les_coups);
                affichage_tableau(tab1);
                jouer (tab1 , coup , 2) ;
                affichage_tableau(tab1);
                joueur = 1;
                nbr_case++;
                break;

        }

        Sauvgarder(tab1);

    }

    //BOUTTON RECOMMENCER : 
    //recommencer(tab1);     
    
}







    


