/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** parsing
*/

#include "parsing.h"

void statattack(pokemon_t *node, char **stw)
{
    
}

void add_pars(pokemon_t **pokemon, sfTexture *texture, char **stw, int nb)
{
    pokemon_t *node = malloc(sizeof(pokemon_t));
    node->prev = NULL;
    if (*pokemon == NULL)
        node->next = NULL;
    else
        node->next = (*pokemon)->next;
    statattack(node, stw);
}

pars_t parsing(void)
{
    pars_t pars = {0};
    FILE *fp = fopen("assets/Pokemonsss.csv", "r");
    char *buff = NULL;
    size_t size = 1;
    int nb = 0;

    pars.texture = sfTexture_createFromFile("assets/18618.png", NULL);
    pars.pokemon = NULL;
    while (getline(&buff, &size, fp) != -1)
        add_pars(pars.pokemon, pars.texture, str_to_words(buff), nb++);
    return pars;
}