/*
** EPITECH PROJECT, 2023
** arrow_click.c
** File description:
** desc
*/

#include <poke_window.h>
#include <poke_functions.h>
#include <t_map.h>
#include <t_string.h>

void event_arrow_click(t_map_node *node_sprite, window_s *window_datas) {
    if (!sprite_is_mouse_click(node_sprite->value, &window_datas->event))
        return;

    if (tstr_cmp(node_sprite->key, "arrow_right") == 0) {
        printf("right \n");
    }

    if (tstr_cmp(node_sprite->key, "arrow_left") == 0) {
        printf("left \n");
    }
}