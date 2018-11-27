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
            sf->scoreInt += 50;
            sf->offset.x = 9.0;
            sf->offset.y = 50.0;
        } else {
            sf->livesInt--;
        }
    } else {
        sf->livesInt--;
    }
}

int check_button_pressed(struct sfHunter *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    sf->positionBouton = sfSprite_getPosition(sf->spriteBouton);
    if (position.x > sf->positionBouton.x &&
    position.x < sf->positionBouton.x + 100) {
        if (position.y > sf->positionBouton.y &&
        position.y < sf->positionBouton.y + 100) {
            return (1);
        }
    }
    return (0);
}

int analyse_events_menu(struct sfHunter *sf)
{
    if (sf->event.type == sfEvtClosed)
        sfRenderWindow_close(sf->window);
    if (sf->event.type == sfEvtMouseButtonPressed)
        return (check_button_pressed(sf));
    return (0);
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
    sfSprite_setPosition(sf->spriteBackgroundMenu, sf->positionGround);
    sfSprite_setTexture(sf->spriteBackgroundMenu, sf->backgroundMenu, sfTrue);
    sfSprite_scale(sf->spriteBackgroundMenu, sf->scaleGround);
    sfSprite_setTexture(sf->spriteBouton, sf->bouton, sfTrue);
    sf->font = sfFont_createFromFile("arial.ttf");
    sf->text = sfText_create();
    sfText_setString(sf->text, "50");
    sf->score = sfText_create();
    sfText_setString(sf->score, "00000");
    sf->lives = sfText_create();
    sfText_setString(sf->lives, "3");
    sfText_setFont(sf->text, sf->font);
    sfText_setFont(sf->score, sf->font);
    sfText_setFont(sf->lives, sf->font);
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
    sf->positionBouton.x = 300.0;
    sf->positionBouton.y = 200.0;
    sf->positionText.x = -100;
    sf->positionText.y = -100;
    sf->positionLives.x = 760;
    sf->positionLives.y = 0;
    sf->scaleGround.x = 0.63;
    sf->scaleGround.y = 0.63;
    sf->rect.top = 0;
    sf->rect.left = 0;
    sf->rect.width = 110;
    sf->rect.height = 110;
}