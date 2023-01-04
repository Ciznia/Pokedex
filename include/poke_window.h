/*
** EPITECH PROJECT, 2023
** poke_window.h
** File description:
** desc
*/
#ifndef poke_window
    #define poke_window

    #include

    typedef struct window {
        sfVideoMode mode = {800, 600, 32};
        sfRenderWindow* window;
        sfEvent event;

    } window_s;

#endif //poke_window
