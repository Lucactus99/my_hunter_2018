/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my_hunter_check
*/

#include "my.h"

void create_sfTexture(struct sfHunter *sf)
{
    sf->texture = sfTexture_createFromFile("spritesheet.png", NULL);
    if (!sf->texture)
        exit(84);
    sf->background = sfTexture_createFromFile("background.png", NULL);
    sf->backgroundMenu = sfTexture_createFromFile("groundMenu.png", NULL);
    sf->ground = sfTexture_createFromFile("ground.png", NULL);
    sf->bouton = sfTexture_createFromFile("boutonjouer.png", NULL);
    sf->scope = sfTexture_createFromFile("scope.png", NULL);
}

void create_sfSprite(struct sfHunter *sf)
{
    sf->sprite = sfSprite_create();
    sf->spriteGround = sfSprite_create();
    sf->spriteBackground = sfSprite_create();
    sf->spriteBackgroundMenu = sfSprite_create();
    sf->spriteBouton = sfSprite_create();
    sf->spriteBoutonRestart = sfSprite_create();
    sf->spriteScope = sfSprite_create();
}

void check_loop(struct sfHunter *sf)
{
    if (sf->loop == 2) {
        move_rect(sf, 110, 330);
        sf->loop = 0;
    }
    if (sf->loop == 4) {
        sfText_setPosition(sf->text, sf->positionText);
    }
    if (sf->loop == 6) {
        sf->positionText.y = -100;
        sfText_setPosition(sf->text, sf->positionText);
    }
}

int check_button_pressed2(struct sfHunter *sf, sfVector2i position)
{
    if (position.y > sf->positionBouton.y &&
    position.y < sf->positionBouton.y + 150) {
        return (1);
    }
    if (position.y > sf->positionRestart.y &&
    position.y < sf->positionRestart.y + 150) {
        return (2);
    }
    return (0);
}

int check_button_pressed(struct sfHunter *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    sf->positionBouton = sfSprite_getPosition(sf->spriteBouton);
    if (position.x > sf->positionBouton.x &&
    position.x < sf->positionBouton.x + 150) {
        return (check_button_pressed2(sf, position));
    }
    if (position.x > sf->positionRestart.x &&
    position.x < sf->positionRestart.x + 150) {
        return (check_button_pressed2(sf, position));
    }
    return (0);
}