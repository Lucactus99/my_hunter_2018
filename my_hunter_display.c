/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my_hunter_display
*/

#include "my.h"

void display_over(struct sfHunter *sf)
{
    sfRenderWindow_clear(sf->window, sfBlack);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackgroundMenu, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBouton, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBoutonRestart, NULL);
    sfRenderWindow_drawText(sf->window, sf->over, NULL);
    sfRenderWindow_drawText(sf->window, sf->score, NULL);
    sfRenderWindow_display(sf->window);
}

void display_menu(struct sfHunter *sf)
{
    sfRenderWindow_clear(sf->window, sfBlack);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackgroundMenu, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBouton, NULL);
    sfSprite_setPosition(sf->spriteBouton, sf->positionBouton);
    sfRenderWindow_display(sf->window);
}

void display_sf(struct sfHunter *sf)
{
    sfRenderWindow_clear(sf->window, sfBlack);
    sfSprite_setTexture(sf->spriteBackground, sf->background, sfTrue);
    sfSprite_setTextureRect(sf->sprite, sf->rect);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->sprite, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteScope, NULL);
    sfRenderWindow_drawText(sf->window, sf->text, NULL);
    sfRenderWindow_drawText(sf->window, sf->score, NULL);
    sfRenderWindow_drawText(sf->window, sf->lives, NULL);
    sfText_setPosition(sf->lives, sf->positionLives);
    sfRenderWindow_display(sf->window);
}

void destroy_sf(struct sfHunter *sf)
{
    sfMusic_destroy(sf->soundShot);
    sfMusic_destroy(sf->sound);
    sfRenderWindow_destroy(sf->window);
    sfTexture_destroy(sf->texture);
    sfTexture_destroy(sf->background);
    sfTexture_destroy(sf->bouton);
    sfSprite_destroy(sf->sprite);
    sfSprite_destroy(sf->spriteGround);
    sfSprite_destroy(sf->spriteBackground);
    sfText_destroy(sf->text);
    sfFont_destroy(sf->font);
}