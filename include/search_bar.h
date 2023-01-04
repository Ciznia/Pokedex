/*
** EPITECH PROJECT, 2022
** B-MUL-100-REN-1-1-myhunter-hugo.murat
** File description:
** SEARCH BAR
*/

#ifndef SEARCH_BAR_H_
    #define SEARCH_BAR_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/System.h>
    #include <SFML/Window/Keyboard.h>
    #include <time.h>

    typedef struct search_s {
        sfRectangleShape *search_bar_line;
        sfText *textbox;
        sfFont *pokemon;
        char text[50];
        int nav_index;
    } search_t;

    search_t sb_init(search_t sb);
    search_t sb_draw(search_t sb, sfRenderWindow *w);
    search_t sb_events(search_t sb, sfEvent ev);

    int my_strcmp(char *s1, char *s2);

#endif /* !SEARCH_BAR_H_ */
