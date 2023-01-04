/*
** EPITECH PROJECT, 2022
** str_to_word_array.c
** File description:
** desc
*/

#include <stdlib.h>

static int is_alpha(char src)
{
    if (!(src >= 'a' && src <= 'z') && !(src >= 'A' && src <= 'Z'))
        return 0;
    return 1;
}

static int get_nbr_of_word(char const *str)
{
    int i = 0;
    int word = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && is_alpha(str[i - 1]) == 1)
            word++;
    }
    return word;
}

static int get_size_of_word(char const *str, int index)
{
    int i = 0;
    int nbr = 0;

    for (i = index; is_alpha(str[i]) == 1 && str[i] != '\0'; i++)
        nbr++;
    return nbr + 1;
}

char **tstr_to_word_array(char const *str)
{
    int a = 0;
    int b = 0;
    char **arr = malloc(sizeof(char*) * get_nbr_of_word(str) + 1);

    arr[a] = malloc(sizeof(char) * get_size_of_word(str, 0));
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && is_alpha(str[i - 1])) {
            arr[a][b] = '\0';
            a++;
            b = 0;
            arr[a] = malloc(sizeof(char) * get_size_of_word(str, i + 1));
        }
        if (is_alpha(str[i]) == 1) {
            arr[a][b] = str[i];
            b++;
        }
    }
    arr[a + 1] = NULL;
    return arr;
}
