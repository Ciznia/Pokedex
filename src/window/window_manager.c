/*
** EPITECH PROJECT, 2023
** window_manager.c
** File description:
** desc
*/
#include "poke_window.h"
#include "poke_functions.h"
#include "t_list.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

void destroy_window_elements(window_s *window_datas)
{
    /*list_foreach(window_datas->list_sprite, node)

    list_foreach(window_datas->list_text, node)*/

    sfRenderWindow_destroy(window_datas->window);
}

void kill_window(window_s *window_datas)
{
    if (window_datas->event.type == sfEvtClosed)
        sfRenderWindow_close(window_datas->window);
}

void new_window(window_s *window_datas)
{
    sfColor background_color = sfColor_fromRGB(39, 174, 96);

    while (sfRenderWindow_isOpen(window_datas->window))
    {
        while (sfRenderWindow_pollEvent(window_datas->window, &window_datas->event)) {
            events_manager(window_datas);
        }
        sfRenderWindow_clear(window_datas->window, background_color);
        map_foreach(window_datas->map_sprite, node)
            sfRenderWindow_drawSprite(window_datas->window
                , ((sprite_s *) node->value)->sf_sprite, NULL);
        map_foreach(window_datas->map_text, node)
            sfRenderWindow_drawText(window_datas->window
                    , ((text_s *)node->value)->sf_text, NULL);
        sfRenderWindow_display(window_datas->window);
    }
    destroy_window_elements(window_datas);
}

window_s *init_window(void)
{
    window_s *window_datas = malloc(sizeof(window_s));
    window_datas->map_sprite = tmap_new();
    window_datas->map_text = tmap_new();
    window_datas->mode = (sfVideoMode){500, 700, 32};
    window_datas->window = sfRenderWindow_create(window_datas->mode, "Pokedex"
        , sfClose, NULL);

    if (!window_datas->window)
        return NULL;
    return  window_datas;
}
