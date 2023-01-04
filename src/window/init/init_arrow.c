/*
** EPITECH PROJECT, 2023
** init_arrow.c
** File description:
** desc
*/

#include <poke_functions.h>

void init_arrow(window_s *window_datas)
{
    sprite_s *arrow_right = new_sprite(window_datas, "assets/ui/arrow-right.png", "arrow_right");
    sfSprite_setPosition(arrow_right->sf_sprite, (sfVector2f){ 450.0, 260.0});
    sfSprite_scale(arrow_right->sf_sprite, (sfVector2f){0.1, 0.1});
    center_sprite(arrow_right);
    arrow_right->is_clickable = true;
    arrow_right->event_function = event_arrow_click;

    sprite_s *arrow_left = new_sprite(window_datas, "assets/ui/arrow-left.png", "arrow_left");
    sfSprite_setPosition(arrow_left->sf_sprite, (sfVector2f){ 10.0, 260.0});
    sfSprite_scale(arrow_left->sf_sprite, (sfVector2f){0.1, 0.1});
    center_sprite(arrow_left);
    arrow_left->is_clickable = true;
    arrow_left->event_function = event_arrow_click;
}
