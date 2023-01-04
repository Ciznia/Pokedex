/*
** EPITECH PROJECT, 2023
** new_sprite.c
** File description:
** desc
*/

#include <poke_window.h>
#include <stdlib.h>
#include <stdio.h>

sprite_s *new_sprite(window_s *window_data, char *path, char *key)
{
    sprite_s *sprite_datas = malloc(sizeof(sprite_s));

    if (sprite_datas == NULL)
        return NULL;
    sprite_datas->sf_sprite = sfSprite_create();
    sprite_datas->sf_texture = sfTexture_createFromFile(path, NULL);
    if (sprite_datas->sf_texture == NULL) {
        sfSprite_destroy(sprite_datas->sf_sprite);
        free(sprite_datas);
        return NULL;
    }
    sprite_datas->is_clickable = false;
    sfSprite_setTexture(sprite_datas->sf_sprite, sprite_datas->sf_texture, sfTrue);
    tmap_add(window_data->map_sprite, key, sprite_datas);
    return sprite_datas;
}

void center_sprite(sprite_s *sprite_datas)
{
    sfFloatRect sprite_bounds = sfSprite_getLocalBounds(sprite_datas->sf_sprite);
    sfVector2f scale = sfSprite_getScale(sprite_datas->sf_sprite);
    if (scale.x <= 0 || scale.y <= 0)
        return;
    sfSprite_setOrigin(sprite_datas->sf_sprite, (sfVector2f){(sprite_bounds.width / 2) * scale.x, (sprite_bounds.height / 2) * scale.y});
}
