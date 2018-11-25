/*
** EPITECH PROJECT, 2018
** d
** File description:
** d
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct framebuffer
{
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    int size = width * height * 4;
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->height = height;
    framebuffer->width = width;
    framebuffer->pixels = malloc(sizeof(sfUint8) * size);
    for (int i = 0; i < size; i++)
        framebuffer->pixels[i] = 0;
    return (framebuffer);
}

void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
    int index = (x + y * buffer->width) * 4;
    buffer->pixels[index] = color.r;
    buffer->pixels[index + 1] = color.g;
    buffer->pixels[index + 2] = color.b;
    buffer->pixels[index + 3] = color.a;
}

void my_draw_square(framebuffer_t *buffer, sfVector2u pos, unsigned int size, sfColor color)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            my_put_pixel(buffer, pos.x + i, pos.y + j, color);
        }
    }
}

void manage_mouse_click(sfMouseButtonEvent event, sfRenderWindow *window, sfVector2f positionSprite, sfVector2f *offset)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(window);
    if (position.x > positionSprite.x && position.x < positionSprite.x + 100) {
        if (position.y > positionSprite.y && position.y < positionSprite.y + 100) {
            offset->x = 9.0;
            offset->y = 50.0;
        }
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f positionSprite, sfVector2f *offset)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, window, positionSprite, offset);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value) {
        rect->left = 0;
    }
}

int rand_a_b(int a, int b) {
    return (rand() % (b-a) + a);
}

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfTexture *texture;
    sfTexture *background;
    sfTexture *tree;
    sfTexture *bouton;
    sfSprite *sprite;
    sfSprite *spriteBackground;
    sfSprite *spriteTree;
    sfSprite *spriteBouton;
    sfVector2f positionSprite;
    sfClock *clock;
    sfTime time;
    sfText *text;
    sfFont *font;
    float seconds;
    sfVector2u pos = {100, 100};
    sfVector2f offset = {10.0, 20.0};
    sfVector2f positionTree = {36.0, 20.0};
    sfVector2f positionText = {-100, -100};
    sfEvent event;
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    int bitsPerPixel = 32;
    int loop = 0;
    int angle = 1;
    int random = 0;
    sfVector2f scale = {2, 0.8};
    //texture = sfTexture_create(800, 600);
    clock = sfClock_create();
    sprite = sfSprite_create();
    spriteBackground = sfSprite_create();
    spriteTree = sfSprite_create();
    spriteBouton = sfSprite_create();
    framebuffer_t *buffer = framebuffer_create(800, 600);
    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    /* Start the game loop */
    texture = sfTexture_createFromFile("spritesheet.png", NULL);
    if (!texture)
        return EXIT_FAILURE;
    background = sfTexture_createFromFile("background.png", NULL);
    tree = sfTexture_createFromFile("tree.png", NULL);
    bouton = sfTexture_createFromFile("boutonjouer.png", NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTexture(spriteBackground, background, sfTrue);
    sfSprite_setTexture(spriteTree, tree, sfTrue);
    sfSprite_setTexture(spriteBouton, bouton, sfTrue);
    sfSprite_setPosition(spriteTree, positionTree);
    sfSprite_setScale(spriteBackground, scale);
    font = sfFont_createFromFile("arial.ttf");
    text = sfText_create();
    sfText_setString(text, "50");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, positionText);
    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            analyse_events(window, event, positionSprite, &offset);
        }
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.08)
        {
            if (scale.x - 0.005 >= 1 && scale.y + 0.001 <= 1) {
                scale.x -= 0.005;
                scale.y += 0.001;
            }
            sfSprite_setScale(spriteBackground, scale);
            loop++;
            if (loop == 2) {
                move_rect(&rect, 110, 330);
                loop = 0;
            }
            if (offset.y == 50.0 && offset.x == 9.0) {
                if (loop <= 1)
                    positionText = sfSprite_getPosition(sprite);
                loop = 4;
                if (angle < 50)
                    angle = angle + 6;
                sfSprite_setRotation(sprite, angle);
            } else {
                random = rand_a_b(-20, 20);
                positionSprite = sfSprite_getPosition(sprite);
                if (positionSprite.y >= 50.0 && positionSprite.y < 300.0)
                    offset.y += random;
                else if (positionSprite.y > 300.0 && offset.x != 9.0)
                    offset.y = -20.0;
                else if (positionSprite.y < 50.0)
                    offset.y = 20.0;
            }
            if (loop == 4) {
                sfText_setPosition(text, positionText);
            }
            if (loop == 5) {
                positionText.y = -100;
                sfText_setPosition(text, positionText);
            }
            positionSprite = sfSprite_getPosition(sprite);
            sfSprite_move(sprite, offset);
            random = rand_a_b(0, 100);
            if (random == 2 || positionSprite.x > 650) {
                if (offset.x != 9.0 && offset.x != 0.0) {
                    texture = sfTexture_createFromFile("spritesheet_reversed.png", NULL);
                    sfSprite_setTexture(sprite, texture, sfFalse);
                    offset.x = -10.0;
                }
            }
            if (random == 6 || positionSprite.x < 50) {
                if (offset.x != 9.0 && offset.x != 0.0) {
                    texture = sfTexture_createFromFile("spritesheet.png", NULL);
                    sfSprite_setTexture(sprite, texture, sfFalse);
                    offset.x = 10.0;
                }
            }
            /*
            if (positionSprite.y > 450) {
                //sfText_setPosition(text, positionText);
                offset.y = 0.0;
                offset.x = 0.0;
                //loop = 4;
            }
            */
            sfClock_restart(clock);
        }
        /* Clear the screen */
        sfRenderWindow_clear(window, sfBlack);
        //sfTexture_updateFromPixels(texture, buffer->pixels, 800, 600, 0, 0);
        //my_draw_square(buffer, pos, 100, sfRed);
        sfSprite_setTexture(spriteBackground, background, sfTrue);
        sfSprite_setTextureRect(sprite, rect);
        /* Update the window */
        sfRenderWindow_drawSprite(window, spriteBackground, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, spriteTree, NULL);
        //sfRenderWindow_drawSprite(window, spriteBouton, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        //sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);

    return EXIT_SUCCESS;
}
