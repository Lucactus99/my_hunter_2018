/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** d
*/

#include "my.h"

void check_position(struct sfHunter *sf)
{
    if (sf->offset.y == 50.0 && sf->offset.x == 9.0) {
        if (sf->loop <= 1)
            sf->positionText = sfSprite_getPosition(sf->sprite);
        sf->loop = 4;
        check_loop(sf);
        if (sf->angle < 50)
            sf->angle = sf->angle + 6;
        sfSprite_setRotation(sf->sprite, sf->angle);
    } else {
        sf->random = rand_a_b(-20, 20);
        sf->positionSprite = sfSprite_getPosition(sf->sprite);
        if (sf->positionSprite.y >= 50.0 && sf->positionSprite.y < 300.0)
            sf->offset.y += sf->random;
        else if (sf->positionSprite.y > 300.0 && sf->offset.x != 9.0)
            sf->offset.y = -20.0;
        else if (sf->positionSprite.y < 50.0)
            sf->offset.y = 20.0;
    }
}

void turn_duck(struct sfHunter *sf)
{
    if (sf->random == 2 || sf->positionSprite.x > 650) {
        if (sf->offset.x != 9.0 && sf->offset.x != 0.0) {
            sf->texture = sfTexture_createFromFile("spritesheet_reversed.png",
            NULL);
            sfSprite_setTexture(sf->sprite, sf->texture, sfFalse);
            sf->offset.x = -10.0;
        }
    }
    if (sf->random == 6 || sf->positionSprite.x < 50) {
        if (sf->offset.x != 9.0 && sf->offset.x != 0.0) {
            sf->texture = sfTexture_createFromFile("spritesheet.png", NULL);
            sfSprite_setTexture(sf->sprite, sf->texture, sfFalse);
            sf->offset.x = 10.0;
        }
    }
}

void create_sfTexture(struct sfHunter *sf)
{
    sf->texture = sfTexture_createFromFile("spritesheet.png", NULL);
    if (!sf->texture)
        exit(84);
    sf->background = sfTexture_createFromFile("background.png", NULL);
    sf->ground = sfTexture_createFromFile("ground.png", NULL);
    sf->tree = sfTexture_createFromFile("tree.png", NULL);
    sf->bouton = sfTexture_createFromFile("boutonjouer.png", NULL);
}

void create_sfSprite(struct sfHunter *sf)
{
    sf->sprite = sfSprite_create();
    sf->spriteGround = sfSprite_create();
    sf->spriteBackground = sfSprite_create();
    sf->spriteTree = sfSprite_create();
    sf->spriteBouton = sfSprite_create();
}