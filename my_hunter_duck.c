/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my_hunter_duck
*/

#include "my.h"

void check_dead_position(struct sfHunter *sf)
{
    if (rand_a_b(0, 2) == 1) {
        sf->positionRandom.x = -100;
        sfSprite_setPosition(sf->sprite, sf->positionRandom);
    } else {
        sf->positionRandom.x = 900;
        sfSprite_setPosition(sf->sprite, sf->positionRandom);
    }
    sf->offset.x = 10.0;
    sf->offset.y = 20.0;
    sfSprite_setRotation(sf->sprite, 0);
    sf->loop = 0;
    sf->positionText.x = -110;
    sf->positionText.y = -110;
    sfText_setPosition(sf->text, sf->positionText);
}

void dead_duck(struct sfHunter *sf)
{
    if (sf->loop <= 1)
        sf->positionText = sfSprite_getPosition(sf->sprite);
    sf->loop = 4;
    check_loop(sf);
    if (sf->angle < 50)
        sf->angle = sf->angle + 6;
    sfSprite_setRotation(sf->sprite, sf->angle);
}

void alive_duck(struct sfHunter *sf)
{
    sf->random = rand_a_b(-20, 20);
    sf->positionSprite = sfSprite_getPosition(sf->sprite);
    if (sf->positionSprite.y >= 50.0 && sf->positionSprite.y < 300.0)
        sf->offset.y += sf->random;
    if (sf->positionSprite.y > 300.0 && sf->offset.x != 9.0)
        sf->offset.y = -20.0;
    if (sf->positionSprite.y < 50.0)
        sf->offset.y = 20.0;
}

void check_position(struct sfHunter *sf)
{
    if (sf->offset.y == 50.0 && sf->offset.x == 9.0)
        dead_duck(sf);
    else
        alive_duck(sf);
    if (sf->positionSprite.y > 1100.0)
        check_dead_position(sf);
}

void turn_duck(struct sfHunter *sf)
{
    if (sf->random == rand_a_b(0, 20) || sf->positionSprite.x > 700.0) {
        if (sf->offset.x != 9.0 && sf->offset.x != 0.0) {
            sf->texture = sfTexture_createFromFile(
            "images/spritesheet_reversed.png", NULL);
            sfSprite_setTexture(sf->sprite, sf->texture, sfFalse);
            sf->offset.x = -10.0;
        }
    }
    if (sf->random == rand_a_b(0, 20) || sf->positionSprite.x < 50.0) {
        if (sf->offset.x != 9.0 && sf->offset.x != 0.0) {
            sf->texture = sfTexture_createFromFile(
            "images/spritesheet.png", NULL);
            sfSprite_setTexture(sf->sprite, sf->texture, sfFalse);
            sf->offset.x = 10.0;
        }
    }
}