/*
** EPITECH PROJECT, 2023
** new_text.c
** File description:
** desc
*/

/*
** EPITECH PROJECT, 2023
** new_sprite.c
** File description:
** desc
*/

#include <poke_window.h>
#include <stdlib.h>
#include <stdio.h>

text_s *new_text(window_s *window_data, char *content, char *key)
{
    text_s *text_datas = malloc(sizeof(text_s));

    if (text_datas == NULL)
        return NULL;
    text_datas->sf_text = sfText_create();
    if (text_datas->sf_text == NULL) {
        free(text_datas);
        return NULL;
    }
    text_datas->sf_font = sfFont_createFromFile("assets/font/KGRedHands.ttf");
    sfText_setString(text_datas->sf_text, content);
    sfText_setFont(text_datas->sf_text, text_datas->sf_font);
    sfText_setColor(text_datas->sf_text, sfWhite);
    sfText_setCharacterSize(text_datas->sf_text, 12);
    tmap_add(window_data->map_text, key, text_datas);
    return text_datas;
}
