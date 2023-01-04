/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "includes/intro.h"

void init_intro(frame_t *frame)
{
    frame->frame_texture = sfTexture_createFromFile("intro/0.png", NULL);
    frame->frame = sfSprite_create();
    frame->frame_pos = (sfVector2f){-100, 175};
    frame->frame_scale = (sfVector2f){1.2, 1};
    frame->frame_clock = sfClock_create();
}

void set_intro(frame_t *frame)
{
    sfSprite_setTexture(frame->frame, frame->frame_texture, sfFalse);
    sfSprite_setPosition(frame->frame, frame->frame_pos);
    sfSprite_setScale(frame->frame, frame->frame_scale);
}

static void step1(frame_t *frames, sfRenderWindow *window)
{
    int i = 1;
    init_intro(frames);
    set_intro(frames);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (i <= 267) {
        frames->frame_seconds = sfClock_getElapsedTime(frames->frame_clock).
        microseconds / 1000000.0;
        sfRenderWindow_clear(window, sfBlack);
        if (frames->frame_seconds > 0.08) {
            frames->frame_texture = sfTexture_createFromFile
            (my_strcomb((my_strcomb("assets/", my_itoa(i))),".png"), NULL);
            sfSprite_setTexture(frames->frame, frames->frame_texture, sfFalse);
            sfRenderWindow_drawSprite(window, frames->frame, NULL);
            sfRenderWindow_display(window);
            sfClock_restart(frames->frame_clock);
            i++;
        }
    }
}

static void step2(frame_t *frames, sfRenderWindow *window, sfView *view)
{
    int i = 1;
    sfView_setCenter(view, (sfVector2f){250, 350});
    sfView_setSize(view, (sfVector2f){500, 700});
    while (i <= 100) {
        frames->frame_seconds = sfClock_getElapsedTime(frames->frame_clock).
        microseconds / 1000000.0;
        sfRenderWindow_clear(window, sfBlack);
        if (frames->frame_seconds > 0.01) {
            sfView_zoom(view, 0.95);
            sfView_rotate(view, 10);
            sfRenderWindow_drawSprite(window, frames->frame, NULL);
            sfRenderWindow_setView(window, view);
            sfRenderWindow_display(window);
            sfClock_restart(frames->frame_clock);
            i++;
            }
    }
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
}

int lunch_intro(frame_t *frames, sfRenderWindow *window)
{
    sfMusic *music = sfMusic_createFromFile("assets/intro.wav");
    sfMusic_play(music);
    sfMusic_setVolume(music, 100);
    sfView *view = sfView_create();
    step1(frames, window);
    step2(frames, window, view);
    sfMusic_destroy(music);
    free(frames);
}
