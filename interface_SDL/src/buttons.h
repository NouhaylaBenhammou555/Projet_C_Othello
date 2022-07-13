#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FONCTION RECOMMENCER : 
void recommencer(int tab1[8][8]){

    tab_init(tab1);

}

//FONCTION D'INITIALISATION DU TABLEAU : 
void tab_init(int tab[8][8]){
    int i, j;

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            tab[i][j] = 0 ;
        }
    }

    tab[3][3] = 1 ;
    tab[4][4] = 1 ;
    tab[3][4] = 2 ;
    tab[4][3] = 2 ;
}

//FONCTION DE BACKUP DES SAUVGARDES : 
void data_backup(int tab[8][8]){

    int i, j, k=0;
    int Tab[64];
    FILE *fp;
    fp = fopen("datasave.txt", "rb");
    fread(Tab, sizeof(int), 64, fp); 
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){ 
            tab[i][j] = Tab[k] ;
            k++;
        }
    } 
    fclose(fp);

    return ;
}

//FONCTION DE SAUVGARDE DU JEU EN TOUT MOMENT : 
void Sauvgarder(int Tab[8][8]){
    
    int i, j;
    FILE *fp;
    fp = fopen("datasave.txt", "wb");
    fwrite(Tab, sizeof(int), 64, fp);
    printf("\t\n---------------------------------------------------------------");
    printf("\t\n---------------->  Data stored successfuly  <------------------");
    printf("\t\n---------------------------------------------------------------");
    fclose(fp);

}