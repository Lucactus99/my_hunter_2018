/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** d
*/

#include "my.h"

void manage_mouse_click(struct sfHunter *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);
    if (position.x > sf->positionSprite.x &&
    position.x < sf->positionSprite.x + 100) {
        if (position.y > sf->positionSprite.y &&
        position.y < sf->positionSprite.y + 100) {
            sf->offset.x = 9.0;
            sf->offset.y = 50.0;
        }
    }
}

void analyse_events(struct sfHunter *sf)
{
    if (sf->event.type == sfEvtClosed)
        sfRenderWindow_close(sf->window);
    if (sf->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(sf);
}

void create_sf(struct sfHunter *sf, sfVideoMode mode)
{
    sf->clock = sfClock_create();
    sf->window = sfRenderWindow_create(mode, "Hunter",
    sfResize | sfClose, NULL);
    sfSprite_setTexture(sf->sprite, sf->texture, sfFalse);
    sfSprite_scale(sf->sprite, sf->scaleGround);
    sfSprite_setPosition(sf->spriteGround, sf->positionGround);
    sfSprite_setTexture(sf->spriteGround, sf->ground, sfFalse);
    sfSprite_scale(sf->spriteGround, sf->scaleGround);
    sfSprite_setTexture(sf->spriteBackground, sf->background, sfTrue);
    sfSprite_setPosition(sf->spriteTree, sf->positionTree);
    sfSprite_setTexture(sf->spriteTree, sf->tree, sfTrue);
    sfSprite_scale(sf->spriteTree, sf->scaleGround);
    sfSprite_setTexture(sf->spriteBouton, sf->bouton, sfTrue);
    sf->font = sfFont_createFromFile("arial.ttf");
    sf->text = sfText_create();
    sfText_setString(sf->text, "50");
    sfText_setFont(sf->text, sf->font);
    sfText_setCharacterSize(sf->text, 20);
    sfText_setPosition(sf->text, sf->positionText);
}

void create_sfVector(struct sfHunter *sf)
{
    sf->offset.x = 10.0;
    sf->offset.y = 20.0;
    sf->positionTree.x = 22.0;
    sf->positionTree.y = 135.0;
    sf->positionGround.x = 0.0;
    sf->positionGround.y = 120.0;
    sf->positionText.x = -100;
    sf->positionText.y = -100;
    sf->scaleGround.x = 0.63;
    sf->scaleGround.y = 0.63;
    sf->rect.top = 0;
    sf->rect.left = 0;
    sf->rect.width = 110;
    sf->rect.height = 110;
}