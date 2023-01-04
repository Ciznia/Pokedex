/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** parsing
*/

#include "parsing.h"

void statattack(pokemon_t *node, char **stw)
{
    node->stat.attack = atoi(stw[4]);
    node->stat.defense = atoi(stw[5]);
    node->stat.hp = atoi(stw[6]);
    node->stat.sp_attack = atoi(stw[7]);
    node->stat.sp_defense = atoi(stw[8]);
    node->stat.speed = atoi(stw[9]);
    node->stat.weight = atoi(stw[10]);
    node->stat.height = atof(stw[12]);
    node->stat.en_legend = atoi(stw[14]);
}

void add_pars(pokemon_t **pokemon, sfTexture *texture, char **stw, int nb)
{
    pokemon_t *node = malloc(sizeof(pokemon_t));
    node->prev = NULL;
    if (*pokemon == NULL)
        node->next = NULL;
    else
        node->next = (*pokemon)->next;
    printf("%s\n",stw[0]);
    node->number = atoi(stw[0]);
    node->name = stw[1];
    node->type_1 = stw[2];
    node->type_2 = stw[3];
    node->classfication = stw[4];
    statattack(node, stw);
}

pars_t parsing(void)
{
    pars_t pars = {0};
    FILE *fp = fopen("assets/Pokemonsss.csv", "r");
    pokemon_t *pokemon = NULL;
    char *buff = NULL;
    size_t size = 1;
    int nb = 0;

    pars.texture = sfTexture_createFromFile("assets/18618.png", NULL);
    pars.pokemon = &pokemon;
    while (getline(&buff, &size, fp) != -1)
        add_pars(pars.pokemon, pars.texture, str_to_words(buff), nb++);
    return pars;
}