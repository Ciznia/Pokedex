/*
** EPITECH PROJECT, 2023
** events_add.c
** File description:
** desc
*/

#include <stdlib.h>
#include "poke_window.h"

bool sprite_add_event(sprite_s *self, sfEventType type
        , void (*event_function)(sprite_s *sprite_pointer
        , window_s *window_datas))
{
    event_s *new_event = malloc(sizeof(event_s));

    new_event->type = type;
    new_event->event_function = event_function;
    if (tlist_add(self->list_event, new_event) == NULL) {
        free(new_event);
        return false;
    }
    return true;
}
