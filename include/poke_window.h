/*
** EPITECH PROJECT, 2023
** poke_window.h
** File description:
** desc
*/
#ifndef poke_window
    #define poke_window
    #include <SFML/Graphics.h>
    #include <t_list.h>
    #include <t_map.h>

    typedef struct window {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;
        t_map *map_sprite;
        t_map *map_text;
    } window_s;

    typedef struct sprite {
        sfSprite *sf_sprite;
        sfTexture *sf_texture;
        t_list *list_event;
        bool is_clickable;
        void (*event_function)(t_map_node *node_sprite, window_s *window_datas);
    } sprite_s;

    typedef struct text {
        sfText *sf_text;
        sfFont *sf_font;
        sfColor sf_color;
    } text_s;

    typedef struct event {
        sfEventType type;
        void (*event_function)(sprite_s *self, window_s *window_datas);
    } event_s;

#endif //poke_window
