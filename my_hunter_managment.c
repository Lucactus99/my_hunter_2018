/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my_hunter_managment
*/

#include "my.h"

void manage_mouse_click2(struct sfHunter *sf, sfVector2i position)
{
    if (position.y > sf->positionSprite.y &&
    position.y < sf->positionSprite.y + 100) {
        sf->scoreInt += 50;
        sf->offset.x = 9.0;
        sf->offset.y = 50.0;
    } else {
        sf->livesInt--;
    }
}

void manage_mouse_click(struct sfHunter *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    sfMusic_play(sf->soundShot);
    if (position.x > sf->positionSprite.x &&
    position.x < sf->positionSprite.x + 100) {
        manage_mouse_click2(sf, position);
    } else {
        sf->livesInt--;
    }
}

int analyse_events_over2(struct sfHunter *sf, int value)
{
    if (value == 1)
        sfRenderWindow_close(sf->window);
    else if (value == 2)
        return (3);
    return (0);
}

int analyse_events_over(struct sfHunter *sf)
{
    int value = 0;

    if (sf->event.type == sfEvtClosed)
        sfRenderWindow_close(sf->window);
    if (sf->event.type == sfEvtMouseButtonPressed) {
        value = check_button_pressed(sf);
        return (analyse_events_over2(sf, value));
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