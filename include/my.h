/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct sfHunter {
    sfRenderWindow* window;
    sfTexture *texture;
    sfTexture *background;
    sfTexture *backgroundMenu;
    sfTexture *ground;
    sfTexture *bouton;
    sfTexture *boutonQuit;
    sfSprite *sprite;
    sfSprite *spriteBackground;
    sfSprite *spriteBackgroundMenu;
    sfSprite *spriteGround;
    sfSprite *spriteBouton;
    sfText *text;
    sfText *lives;
    sfText *score;
    sfFont *font;
    sfEvent event;
    sfIntRect rect;
    sfVector2f positionSprite;
    sfVector2f offset;
    sfVector2f positionTree;
    sfVector2f positionGround;
    sfVector2f positionBouton;
    sfVector2f positionText;
    sfVector2f positionLives;
    sfVector2f scaleGround;
    sfVector2u size;
    sfClock *clock;
    sfTime time;
    float seconds;
    int loop;
    int angle;
    int random;
    int scoreInt;
    int livesInt;
    char *scoreStr;
    char *livesStr;
};

void my_putchar(char);
int my_putstr(char const *);
int my_strcmp(char const *, char const *);
void manage_mouse_click(struct sfHunter *);
void analyse_events(struct sfHunter *);
void move_rect(struct sfHunter *, int, int);
void destroy_sf(struct sfHunter *);
void check_loop(struct sfHunter *);
void create_sfVector(struct sfHunter *);
void create_sfSprite(struct sfHunter *);
void create_sfTexture(struct sfHunter *);
void check_position(struct sfHunter *);
void create_sf(struct sfHunter *, sfVideoMode);
void opened_window(struct sfHunter *);
void turn_duck(struct sfHunter *);
int rand_a_b(int, int);
void help();
int menu(struct sfHunter *);
int analyse_events_menu(struct sfHunter *sf);

#endif //MY_H_
