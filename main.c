/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** d
*/

#include "my.h"

int rand_a_b(int a, int b)
{
    return (rand() % (b-a) + a);
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
    sf->loop = 0;
    sf->angle = 1;
    sf->random = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return (84);
    }
    create_sfVector(sf);
    create_sfSprite(sf);
    create_sfTexture(sf);
    create_sf(sf, mode);
    while (sfRenderWindow_isOpen(sf->window))
        opened_window(sf);
    destroy_sf(sf);
    return (0);
}