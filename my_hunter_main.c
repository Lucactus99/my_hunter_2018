/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my_hunter_main.c
*/

#include "my.h"

int rand_a_b(int a, int b)
{
    return (rand() % (b-a) + a);
}

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./hunter\n");
    my_putstr("DESCRIPTION\n");
}

void move_rect(struct sfHunter *sf, int offset, int max_value)
{
    sf->rect.left += offset;
    if (sf->rect.left == max_value) {
        sf->rect.left = 0;
    }
}

int main(int ac, char **av)
{
    sfVideoMode mode = {800, 600, 32};
    struct sfHunter *sf = malloc(sizeof(struct sfHunter));
    int value = 0;

    sf->livesStr = malloc(sizeof(char));
    sf->loop = 0;
    sf->angle = 1;
    sf->random = 0;
    sf->livesInt = 3;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return (84);
    }
    create_sfVector(sf);
    create_sfSprite(sf);
    create_sfTexture(sf);
    create_sf(sf, mode);
    while (sfRenderWindow_isOpen(sf->window)) {
        sfMusic_play(sf->sound);
        if (sf->livesInt == 0) {
            value = game_over(sf);
            if (value == 3)
                value = 0;
        }
        if (value == 0)
            value = menu(sf);
        if (value == 1)
            opened_window(sf);
    }
    destroy_sf(sf);
    return (0);
}

void analyse_events(struct sfHunter *sf)
{
    sfVector2i position;

    if (sf->event.type == sfEvtClosed)
        sfRenderWindow_close(sf->window);
    if (sf->event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(sf);
    if (sf->event.type == sfEvtMouseMoved) {
        position = sfMouse_getPositionRenderWindow(sf->window);
        sf->positionScope.x = position.x - 70;
        sf->positionScope.y = position.y - 70;
        sfSprite_setPosition(sf->spriteScope, sf->positionScope);
    }
}