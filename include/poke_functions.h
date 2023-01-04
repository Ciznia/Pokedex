/*
** EPITECH PROJECT, 2023
** poke_functions.h
** File description:
** desc
*/
#ifndef poke_functions
    #define poke_functions
    #include <poke_window.h>
    window_s *init_window(void);
    void new_window(window_s *window_datas);
    void events_manager(window_s *new_window);
    sprite_s *new_sprite(window_s *window_data, char *path, char *key);
    text_s *new_text(window_s *window_data, char *content, char *key);
    void center_sprite(sprite_s *sprite_datas);
    void init_arrow(window_s *window_datas);
    bool sprite_is_mouse_click(sprite_s *sprite_datas, sfEvent *event_datas);
    void event_arrow_click(t_map_node *node_sprite, window_s *window_datas);
#endif //poke_functions
