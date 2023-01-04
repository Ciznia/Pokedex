/*
** EPITECH PROJECT, 2022
** tmath.h
** File description:
** desc
*/
#ifndef TOOLS_BOX_TMATH_H
    #define TOOLS_BOX_TMATH_H
    #include "t_ctype.h"
    int int_is_prime(int nb);
    int int_power(int nb, int p);
    int int_square(int nb);
    int int_find_prime_sup(int nb);
    int int_len(int nbr);
    double double_modulo(long double nb, double div);
    int double_len(long double nb, int precision);
    long double double_abs(long double nb);
    char *int_to_base(int number, int base, int max_digits);

#endif //TOOLS_BOX_TMATH_H
