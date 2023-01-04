/*
** EPITECH PROJECT, 2023
** events_manager.c
** File description:
** desc
*/

#include "poke_window.h"

void events_manager(window_s *window_datas)
{
    if (window_datas->event.type == sfEvtClosed)
        sfRenderWindow_close(window_datas->window);
    if (window_datas->event.type != sfEvtMouseButtonPressed)
        return;
    map_foreach(window_datas->map_sprite, node) {
        if (((sprite_s *)node->value)->is_clickable)
            ((sprite_s *)node->value)->event_function(node, window_datas);
    }
}