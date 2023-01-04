/*
** EPITECH PROJECT, 2023
** Pokedex
** File description:
** input_sound
*/

#include "sound.h"

void background_sound(void)
{
    sfMusic *music = sfMusic_createFromFile("assets/sounds/background.ogg");
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}
//music de fond si aucun conflit avec l'intro de valentin

void pokemon_cry(int pokemon_id) //donner l'id du pokemon en question pour appeler le bon cri
{
    sfMusic *music;
    char id[1024];
    sprintf(id, "assets/sounds/cry/%i.wav", pokemon_id);
    music = sfMusic_createFromFile(id);
    sfMusic_play(music);
}
//fonction qui sert a générer le bruit des pokémon lors du changement de page du pokédex
