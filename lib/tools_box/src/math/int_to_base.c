/*
** EPITECH PROJECT, 2022
** int_to_base.c
** File description:
** desc
*/

#include <t_math.h>
#include <stdio.h>
#include <stdlib.h>
#include "t_list.h"
#include <t_string.h>
#include "t_ctype.h"

char *int_to_base(int number, int base, int max_digits)
{
    char *number_str = malloc(1);
    int size = 0;
    while (number > 0) {
        number_str = tstr_concat(number_str, tstr_number(number % base));
        number /= base;
        size++;
    }
    for (int i = size; i < max_digits; ++i)
        number_str = tstr_concat(number_str, "0");
    return tstr_rev(number_str);
}
