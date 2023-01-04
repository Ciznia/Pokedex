/*
** EPITECH PROJECT, 2023
** window_manager.c
** File description:
** desc
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

void init_window()
{


    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {

        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}

void destroy_window_elements()
{

}