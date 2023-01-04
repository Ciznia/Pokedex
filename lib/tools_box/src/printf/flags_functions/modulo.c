/*
** EPITECH PROJECT, 2022
** modulo.c
** File description:
** desc
*/
#include <stdarg.h>
#include <unistd.h>
void modulo_flag(va_list args __attribute__((unused)))
{
    write(1, "%", 1);
}
