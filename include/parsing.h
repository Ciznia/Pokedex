/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** parsing
*/

#ifndef _PARSING_H__
    #define _PARSING_H__
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    #include <unistd.h>
    #include <stdio.h>
    #define SEP(a) (a == ' ' || a == '\n')

    typedef struct stat_s {
        int attack;
        int defense;
        int hp;
        int sp_attack;
        int sp_defense;
        int speed;
        int weight;
        int kg;
        int height;
        int generation;
        int en_legend;
    } stat_t;

    typedef struct pokemon_s {
        struct pokemon_s *next;
        struct pokemon_s *prev;
        int number;
        char *name;
        char *jap_name;
        char *type_1;
        char *type_2;
        char *classfication;
        sfSprite *sprite;
        stat_t stat;
    } pokemon_t;

    typedef struct pars_s {
        pokemon_t **pokemon;
        sfTexture *texture;
    } pars_t;

    char **str_to_words(char *str);

#endif /* !PARSING */
