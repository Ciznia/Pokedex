/*
** EPITECH PROJECT, 2022
** int_power.c
** File description:
** desc
*/

#include <t_ctype.h>
#include <limits.h>

int int_power(int nb, int p)
{
    int64_t value = nb;

    if (nb < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 1)
        return (value * int_power(value * 10, p - 1)) / 10;
    if (value > INT_MAX || value < INT_MIN)
        return 0;
    return nb;
}
