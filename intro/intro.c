/*
** EPITECH PROJECT, 2023
** Pokedex
** File description:
** intro
*/

#include "includes/intro.h"

char *my_strcomb(char *str1, char* str2)
{
    char *str = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    int i = 0;
    int j = 0;
    for (int n = 0; n < strlen(str1) + strlen(str2); n++) {
        if (n < strlen(str1)) {
            str[n] = str1[n];
        } else {
            str[n] = str2[j];
            j++;
        }
    }
    str[strlen(str1) + strlen(str2)] = '\0';
    return str;
}

char *my_itoa(int nb)
{
    if (nb == 0)
        return "0";
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * 10);

    while (nb > 0) {
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    for (j = 0; j < i / 2; j++) {
        k = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = k;
    }
    return (str);
}
