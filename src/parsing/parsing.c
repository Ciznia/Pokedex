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
    if (*pokemon == NULL) {
        node->next = NULL;
        node->prev = NULL;
    }
    else {
        (*pokemon)->prev->next = node;
        node->prev = (*pokemon)->prev;
        (*pokemon)->prev = node;
        node->next = *pokemon;
    }
    printf("%s\n",stw[0]);
    node->number = atoi(stw[0]);
    node->name = stw[1];
    node->type_1 = stw[2];
    node->type_2 = stw[3];
    node->classfication = stw[4];
    node->rect = (sfIntRect){80 * nb,0,80, 80};
    statattack(node, stw);
}

void add_theme(char *name, char *str, theme_t theme[18], int nb)
{
    theme[nb].texture = sfTexture_createFromFile(str, NULL);
    theme[nb].sprite = sfSprite_create();
    sfSprite_setTexture(theme[nb].sprite, theme[nb].texture, sfFalse);
}

void init_theme(theme_t theme[18])
{
    add_theme("bug", "assets/bug.png", theme, 0);
    add_theme("normal", "assets/colorless.png", theme, 1);
    add_theme("dark", "assets/dark.png", theme, 2);
    add_theme("Dragon", "assets/dragon.png", theme, 3);
    add_theme("electric", "assets/electric.png", theme, 4);
    add_theme("fairy", "assets/fairy.png", theme, 5);
    add_theme("fighting", "assets/fighting.png", theme, 6);
    add_theme("fire", "assets/fire.png", theme, 7);
    add_theme("flying", "assets/flying.png", theme, 8);
    add_theme("ghost", "assets/ghost.png", theme, 9);
    add_theme("grass", "assets/grass.png", theme, 10);
    add_theme("ground", "assets/ground.png", theme, 11);
    add_theme("ice", "assets/ice.png", theme, 12);
    add_theme("psychic", "assets/physic.png", theme, 13);
    add_theme("poison", "assets/poison.png", theme, 14);
    add_theme("rock", "assets/rock.png", theme, 15);
    add_theme("steel", "assets/steel.png", theme, 16);
    add_theme("water", "assets/water.png", theme, 17);
}

pars_t parsing(void)
{
    pars_t pars = {0};
    FILE *fp = fopen("assets/Pokemonsss.csv", "r");
    pokemon_t *pokemon = NULL;
    char *buff = NULL;
    size_t size = 1;
    int nb = 0;
    theme_t theme[18] = {0};

    init_theme(theme);
    pars.texture = sfTexture_createFromFile("assets/18618.png", NULL);
    pars.pokemon = &pokemon;
    while (getline(&buff, &size, fp) != -1)
        add_pars(pars.pokemon, pars.texture, str_to_words(buff), nb++);
    return pars;
}