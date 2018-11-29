/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my_hunter_create.c
*/

#include "my.h"

void create_sf(struct sfHunter *sf, sfVideoMode mode)
{
    sf->clock = sfClock_create();
    sf->window = sfRenderWindow_create(mode, "Hunter",
    sfResize | sfClose, NULL);
    sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
    sfSprite_setTexture(sf->sprite, sf->texture, sfFalse);
    sfSprite_scale(sf->sprite, sf->scaleDuck);
    sfSprite_setPosition(sf->spriteGround, sf->positionGround);
    sfSprite_setTexture(sf->spriteGround, sf->ground, sfFalse);
    sfSprite_scale(sf->spriteGround, sf->scaleDuck);
    sfSprite_setTexture(sf->spriteBackground, sf->background, sfTrue);
    sfSprite_setPosition(sf->spriteBackgroundMenu, sf->positionGround);
    sfSprite_setTexture(sf->spriteBackgroundMenu, sf->backgroundMenu, sfTrue);
    sfSprite_scale(sf->spriteBackgroundMenu, sf->scaleDuck);
    sfSprite_setTexture(sf->spriteBouton, sf->bouton, sfTrue);
    sfSprite_setTexture(sf->spriteScope, sf->scope, sfTrue);
    create_sf_2(sf);
}

void create_sf_2(struct sfHunter *sf)
{
    sf->font = sfFont_createFromFile("src/arial.ttf");
    sf->soundShot = sfMusic_createFromFile("music/soundShot.ogg");
    sf->sound = sfMusic_createFromFile("music/sound.ogg");
    sf->text = sfText_create();
    sfText_setString(sf->text, "50");
    sf->score = sfText_create();
    sfText_setString(sf->score, "00000");
    sf->lives = sfText_create();
    sfText_setString(sf->lives, "3");
    sf->over = sfText_create();
    sfText_setString(sf->over, "Game Over");
    sfText_setFont(sf->text, sf->font);
    sfText_setFont(sf->score, sf->font);
    sfText_setFont(sf->lives, sf->font);
    sfText_setFont(sf->over, sf->font);
    sfText_setCharacterSize(sf->text, 20);
    sfText_setCharacterSize(sf->text, 30);
    sfText_setPosition(sf->text, sf->positionText);
    sfText_setPosition(sf->over, sf->positionOver);
}

void create_sfvector(struct sfHunter *sf)
{
    sf->offset.x = 10.0;
    sf->offset.y = 20.0;
    sf->positionTree.x = 22.0;
    sf->positionTree.y = 135.0;
    sf->positionGround.x = 0.0;
    sf->positionGround.y = 80.0;
    sf->positionBouton.x = 335.0;
    sf->positionBouton.y = 150.0;
    sf->positionText.x = -100;
    sf->positionText.y = -100;
    sf->positionLives.x = 760;
    sf->positionLives.y = 0;
    create_sfvector_2(sf);
}

void create_sfvector_2(struct sfHunter *sf)
{
    sf->positionRestart.x = 335.0;
    sf->positionRestart.y = 350.0;
    sf->positionOver.x = 305.0;
    sf->positionOver.y = 100.0;
    sf->scaleGround.x = 0.50;
    sf->scaleGround.y = 0.50;
    sf->scaleDuck.x = 0.83;
    sf->scaleDuck.y = 0.83;
    sf->rect.top = 0;
    sf->rect.left = 0;
    sf->rect.width = 110;
    sf->rect.height = 110;
}