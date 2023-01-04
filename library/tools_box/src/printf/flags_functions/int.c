/*
** EPITECH PROJECT, 2022
** int.c
** File description:
** desc
*/

#include <stdarg.h>
#include <t_print.h>

void int_flag(va_list args)
{
    print_nbr(va_arg(args, int));
}
