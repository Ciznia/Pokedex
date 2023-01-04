/*
** EPITECH PROJECT, 2022
** char_lower.c
** File description:
** desc
*/

#include <t_char.h>

char char_lower(char c)
{
    if (!char_is_upper(c))
        return c;
    return (c + 32);
}
