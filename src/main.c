/*
** EPITECH PROJECT, 2022
** B-MUL-100-REN-1-1-whut-hugo.murat
** File description:
** whut
*/

#include "search_bar.h"

int window_draw_sprite(void) // Your fonction to draw your sprites is empty, it's just for the exemple
{
    return 0;
}

int window_event(sfEvent event, sfRenderWindow *window) // Basic game events to close the window
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    return 0;
}

int main(void)                                  // Basic csfml window
{
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;

    search_t sb = sb_init(sb);                  // Add this line at the start of your code to init sb
                                                // sb = search-bar
    mode = (sfVideoMode) {500, 700, 32};
    window = sfRenderWindow_create(mode, "", sfResize | sfClose, NULL);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            window_event(event, window);
            sb = sb_events(sb, event);           // Add this line to get search-bar events
        }
        sfRenderWindow_clear(window, sfBlack);
        window_draw_sprite();
        sb = sb_draw(sb, window);               // Add this line to draw the search-bar
        sfRenderWindow_display(window);
    }
    return 0;
}
