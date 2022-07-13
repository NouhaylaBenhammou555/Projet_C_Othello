#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define window_heigt 600
#define window_width 600
#define rect_height  
#define rect_width 
#define button_x 210
#define button_y 37
#define but_table_x 94
#define but_table_y 45
#define table_case 65


#define menu "menu.bmp"
#define othellier "othellier.bmp"
#define inscription "inscription.bmp"
#define databackup1 "databackup1.bmp"
#define databackup "databackup.bmp"
#define choix "choix.bmp"
#define sauvgarde "sauvgarde.bmp"

int insert_img(SDL_Texture *texture1, SDL_Renderer *renderer1, SDL_Surface *background, char path[20], SDL_Rect rect);
int coup_joue(SDL_Event event, int table_x[9], int table_y[9], SDL_Rect rect, SDL_Texture *texture, SDL_Renderer *renderer, SDL_Surface *image);
int insert_coin(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Surface *image, char path[20], SDL_Rect rect);
void affichage_sdl(int tab[8][8], int table_x[9], int table_y[9], SDL_Texture *texture, SDL_Renderer *renderer, SDL_Surface *image, SDL_Rect rect);


int main(int argc, char* argv[]){

    SDL_Window *window ; 
    SDL_Renderer *renderer ; 
    SDL_Surface *image = NULL ; 
    SDL_Texture *texture = NULL ;
    SDL_Rect rect;

    int button_1vs1 = 0, button_vscomputer = 0, button_signin , button_sauvgarde, button_quit, table_x[9], table_y[9], coin_played = 0;

    //INITIALISATION DE LA SDL : 
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("OTHELLO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_heigt, NULL);
    renderer = SDL_CreateRenderer(window, -1, NULL);

    //GAME MENU INTERFACE :  
    insert_img(texture, renderer, image, choix, rect);


    SDL_bool game_launched = SDL_TRUE;

    while(game_launched){
        
        SDL_Event event;
        while(SDL_PollEvent(&event)){

            switch(event.type){

                case SDL_QUIT : 
                    game_launched = SDL_FALSE;
                    break;  

                case SDL_MOUSEBUTTONDOWN : 

                        //1VS1  BUTTON : 
                        while(event.button.x >= 245 && event.button.x <= 245 + button_x && event.button.y <= 428+button_y 
                           && event.button.y >= 428 && event.button.button == SDL_BUTTON_LEFT && button_1vs1 == 0){
                               //INITIALISATION DU JEU : 
                               insert_img(texture, renderer, image, menu, rect); 
                               button_1vs1 = 1;
                               button_vscomputer = 1;
                               button_signin = 0;
                        }
                        //VS COMPUTER BUTTON : 
                        while(event.button.x >= 210 && event.button.x <= 210 + button_x && event.button.y <= 478+button_y 
                           && event.button.y >= 478 && event.button.button == SDL_BUTTON_LEFT && button_vscomputer == 0){
                               insert_img(texture, renderer, image, menu, rect);
                               button_1vs1 = 1;
                               button_vscomputer = 1;
                               button_signin = 0;
                               break;
                        }
                        //SIGN IN  BUTTON : 
                        while(event.button.x >= 250 && event.button.x <= 250 + 196 && event.button.y <= 428+37 
                           && event.button.y >= 428 && event.button.button == SDL_BUTTON_LEFT && button_signin == 0){
                               insert_img(texture, renderer, image, inscription, rect);
                               button_1vs1 = 1;
                               button_vscomputer = 1;
                               button_signin = 1;
                               button_sauvgarde = 0;
                               
                        }
                        //INSCRIPTION BUTTON : 
                        while(event.button.x >= 169 && event.button.x <= 169 + 353 && event.button.y <= 428+37 
                           && event.button.y >= 428 && event.button.button == SDL_BUTTON_LEFT && button_sauvgarde == 0){
                               insert_img(texture, renderer, image, sauvgarde, rect);
                               button_1vs1 = 1;
                               button_vscomputer = 1;
                               button_signin = 1;
                               button_sauvgarde = 1;
                        }
                        break;

                default : 
                    break;
            }      
        }
    }

    
        
    SDL_FreeSurface(image);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;

}

//FONCTION PERMETTANT D'INSERE UNE IMAGE DE FORMAT BMP : 
int insert_img(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Surface *image, char path[20], SDL_Rect rect){

    image = SDL_LoadBMP(path);   
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = (window_width - rect.w)/2;
    rect.y = (window_heigt - rect.h)/2;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(image);
    SDL_RenderPresent(renderer);
    return 0;

}

int insert_coin(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Surface *image, char path[20], SDL_Rect rect){

    image = SDL_LoadBMP(path);   
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(image);
    SDL_RenderPresent(renderer);
    return 0;

}



    