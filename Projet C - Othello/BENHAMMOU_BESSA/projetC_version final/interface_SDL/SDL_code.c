#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/functions.h"
#include "src/buttons.h"
#include "src/headers.h"

#define window_heigt 600
#define window_width 600
#define rect_height  
#define rect_width 
#define button_x 231
#define button_y 51

int insert_img();

int main(int argc, char* argv[]){

    SDL_Window *window ; 
    SDL_Renderer *renderer ; 


    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(window_heigt, window_width, 0, &window, &renderer);
    SDL_Surface *image = SDL_LoadBMP("menu.png") ; 
    SDL_Texture *texture = NULL ;

    SDL_Rect rect;

    insert_img(texture, renderer, image);

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = (window_width - rect.w)/2;
    rect.y = (window_heigt - rect.h)/2;
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
    SDL_FreeSurface(image);

    SDL_bool game_launched = SDL_TRUE; 

    while(game_launched){
        
        SDL_Event event;
        while(SDL_PollEvent(&event)){

            switch(event.type){

                case SDL_QUIT : 
                    game_launched = SDL_FALSE;
                    break;  

                case SDL_MOUSEBUTTONDOWN : 

                        if( event.button.x <= 416 && event.button.x >= 185 && event.button.y <= 310 && 
                            event.button.y >= 259 && event.button.button == SDL_BUTTON_LEFT){

                                /*-----------------------BACKGROUND-----------------------*/
                                /*image = SDL_LoadBMP("gametable.bmp");
                                texture = SDL_CreateTextureFromSurface(renderer, image);
                                SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
                                rect.x = (window_width - rect.w)/2;
                                rect.y = (window_heigt - rect.h)/2;
                                SDL_RenderCopy(renderer, texture, NULL, &rect);
                                SDL_RenderPresent(renderer);
                                SDL_FreeSurface(image);
                                /*--------------------------------------------------------*/                      
                        //}*/

                        /*else if(event.button.x <= 415 && event.button.x >= 184 && event.button.y <= 442 && 
                                event.button.y >= 391 && event.button.button == SDL_BUTTON_LEFT){

                                    int back = 0;
                                    while(back == 0){ 
                                        /*-----------------------BACKGROUND-----------------------*/
                                       /* image = SDL_LoadBMP("about.bmp");
                                        texture = SDL_CreateTextureFromSurface(renderer, image);
                                        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
                                        rect.x = (window_width - rect.w)/2;
                                        rect.y = (window_heigt - rect.h)/2;
                                        SDL_RenderCopy(renderer, texture, NULL, &rect);
                                        SDL_FreeSurface(image);
                                        SDL_RenderPresent(renderer);
                                        /*--------------------------------------------------------*/
                                    //}*/
                                    
                                //}
                            /*else if(event.button.x <= 184 + button_x && event.button.x >= 184 && event.button.y <= 325 + button_y 
                                    && event.button.y >= 325 && event.button.button == SDL_BUTTON_LEFT){

                                            /*-----------------------BACKGROUND-----------------------*/
                                            /*image = SDL_LoadBMP("gametable.bmp");
                                            texture = SDL_CreateTextureFromSurface(renderer, image);
                                            SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
                                            rect.x = (window_width - rect.w)/2;
                                            rect.y = (window_heigt - rect.h)/2;
                                            SDL_RenderCopy(renderer, texture, NULL, &rect);
                                            SDL_FreeSurface(image);
                                            SDL_RenderPresent(renderer);
                                            /*--------------------------------------------------------*/
                                       // }*/
                        //break;
                        //default : 
                           // break;
               // }      
        //}
    //}*/

    SDL_FreeSurface(image);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;

}

int insert_img(SDL_Texture *texture1, SDL_Renderer *renderer1, SDL_Surface *background){
   
    SDL_Rect rect1;
    texture1 = SDL_CreateTextureFromSurface(renderer1, background);
    SDL_QueryTexture(texture1, NULL, NULL, &rect1.w, &rect1.h);
    rect1.x = (window_width - rect1.w)/2;
    rect1.y = (window_heigt - rect1.h)/2;
    SDL_RenderCopy(renderer1, texture1, NULL, &rect1);
    SDL_FreeSurface(background);
    SDL_RenderPresent(renderer1);
    return 0;

}
