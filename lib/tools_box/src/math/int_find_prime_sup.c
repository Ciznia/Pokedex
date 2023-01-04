/*
** EPITECH PROJECT, 2022
** int_find_prime_sup.c
** File description:
** desc
*/

#include <t_math.h>

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        return 0;
    if (nb > 2 && nb % 2 == 0)
        nb = nb + 1;
    while (!int_is_prime(nb)) {
        nb = nb + 2;
    }
    return nb;
}
