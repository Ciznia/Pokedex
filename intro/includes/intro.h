/*
** EPITECH PROJECT, 2023
** Pokedex
** File description:
** intro
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

#ifndef INTRO_H_
    #define INTRO_H_
        typedef struct window_s {
        sfRenderWindow* window;
        sfVideoMode video_mode;
        sfEvent event;
    } window_t;

    typedef struct frame_s {
        sfSprite* frame;
        sfTexture* frame_texture;
        sfVector2f frame_pos;
        sfVector2f frame_scale;
        sfClock *frame_clock;
        sfTime frame_time;
        float frame_seconds;
    } frame_t;

        typedef struct sfcontain_s {
        sfRenderWindow* w;
        sfVideoMode video_mode;
        sfEvent event;
        sfTexture* background;
        sfSprite* sprite_background;
        sfVector2f scale_background;
        sfVector2f my_pos_background;
        sfClock *global_clock;
        sfClock *clock;
        sfClock *clock_sprite;
        sfClock *background_clock;
        sfTime time;
        sfTime time_sprite;
        sfTime global_time;
        sfTime background_time;
        sfFont *font;
        sfText *text;

        float global_second;
        float seconds;
        float seconds_sprite;
        float background_second;
        int frame_nb;
    } sfcontain_t;
    void close_window(window_t *window);
    void analyse_events(window_t *window);
    window_t *init_window(void);
    void init_intro(frame_t *frame);
    void set_intro(frame_t *frame);
    int lunch_intro(frame_t *frames, sfRenderWindow *window);
    int main(int ac, char **av);
    char *my_strcomb(char *str1, char* str2);
    char *my_itoa(int nb);
    void init_pokedex(sfcontain_t *sfcontain);
    void intro_son(window_t *window);
#endif /* !INTRO_H_ */
