/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** d
*/

#include "my.h"

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./hunter\n");
    my_putstr("DESCRIPTION\n");
}

void display_sf(struct sfHunter *sf)
{
    sfRenderWindow_clear(sf->window, sfBlack);
    sfSprite_setTexture(sf->spriteBackground, sf->background, sfTrue);
    sfSprite_setTextureRect(sf->sprite, sf->rect);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->sprite, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteTree, NULL);
    sfRenderWindow_drawText(sf->window, sf->text, NULL);
    sfRenderWindow_display(sf->window);
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

void opened_window(struct sfHunter *sf)
{
    while (sfRenderWindow_pollEvent(sf->window, &sf->event))
        analyse_events(sf);
    sf->time = sfClock_getElapsedTime(sf->clock);
    sf->seconds = sf->time.microseconds / 1000000.0;
    if (sf->seconds > 0.08) {
        sf->loop++;
        check_loop(sf);
        check_position(sf);
        sf->positionSprite = sfSprite_getPosition(sf->sprite);
        sfSprite_move(sf->sprite, sf->offset);
        sf->random = rand_a_b(0, 100);
        turn_duck(sf);
        sfClock_restart(sf->clock);
    }
    display_sf(sf);
}

void destroy_sf(struct sfHunter *sf)
{
    sfRenderWindow_destroy(sf->window);
    sfTexture_destroy(sf->texture);
    sfTexture_destroy(sf->background);
    sfTexture_destroy(sf->tree);
    sfTexture_destroy(sf->bouton);
    sfSprite_destroy(sf->sprite);
    sfSprite_destroy(sf->spriteGround);
    sfSprite_destroy(sf->spriteBackground);
    sfSprite_destroy(sf->spriteTree);
    sfText_destroy(sf->text);
    sfFont_destroy(sf->font);
}