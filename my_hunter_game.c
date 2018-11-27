/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my_hunter_game
*/

#include "my.h"

int game_over(struct sfHunter *sf)
{
    int value = 0;

    sfRenderWindow_setMouseCursorVisible(sf->window, sfTrue);
    sf->bouton = sfTexture_createFromFile("images/croix.png", NULL);
    sfSprite_setTexture(sf->spriteBouton, sf->bouton, sfTrue);
    sfSprite_setScale(sf->spriteBouton, sf->scaleDuck);
    sfSprite_setPosition(sf->spriteBouton, sf->positionBouton);
    sf->boutonRestart = sfTexture_createFromFile("images/restart.png", NULL);
    sfSprite_setTexture(sf->spriteBoutonRestart, sf->boutonRestart, sfTrue);
    sfSprite_setScale(sf->spriteBoutonRestart, sf->scaleDuck);
    sfSprite_setPosition(sf->spriteBoutonRestart, sf->positionRestart);
    while (value != 3 && sfRenderWindow_isOpen(sf->window)) {
        while (sfRenderWindow_pollEvent(sf->window, &sf->event))
            value = analyse_events_over(sf);
        display_over(sf);
    }
    return (3);
}

int menu(struct sfHunter *sf)
{
    int value = 0;

    sf->livesInt = 3;
    sf->bouton = sfTexture_createFromFile("images/boutonjouer.png", NULL);
    sfSprite_setTexture(sf->spriteBouton, sf->bouton, sfTrue);
    sfSprite_setScale(sf->spriteBouton, sf->scaleDuck);
    sfSprite_setPosition(sf->spriteBouton, sf->positionBouton);
    while (sfRenderWindow_pollEvent(sf->window, &sf->event))
        value = analyse_events_menu(sf);
    display_menu(sf);
    if (value == 1)
        return (1);
    return (0);
}

char *itos(int score)
{
    int digit;
    int i = 4;
    int tmp = score;
    char *string = malloc(sizeof(char) * 4);

    for (i = 4; i >= 0 && tmp > 0; i--) {
        digit = tmp % 10;
        tmp = tmp / 10;
        string[i] = '0' + digit;
    }
    for (int j = i; j >= 0; j--) {
        string[j] = '0';
    }
    string[5] = '\0';
    return (string);
}

void opened_window(struct sfHunter *sf)
{
    sfRenderWindow_setMouseCursorVisible(sf->window, sfFalse);
    while (sfRenderWindow_pollEvent(sf->window, &sf->event))
        analyse_events(sf);
    sf->time = sfClock_getElapsedTime(sf->clock);
    sf->seconds = sf->time.microseconds / 1000000.0;
    sf->scoreStr = itos(sf->scoreInt);
    sf->livesStr[0] = sf->livesInt + 48;
    sfText_setString(sf->score, sf->scoreStr);
    sfText_setString(sf->lives, sf->livesStr);
    if (sf->seconds > 0.08) {
        sf->loop++;
        check_loop(sf);
        check_position(sf);
        sf->positionSprite = sfSprite_getPosition(sf->sprite);
        sfSprite_move(sf->sprite, sf->offset);
        sf->random = rand_a_b(0, 20);
        turn_duck(sf);
        sfClock_restart(sf->clock);
    }
    display_sf(sf);
}