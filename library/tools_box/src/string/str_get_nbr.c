/*
** EPITECH PROJECT, 2022
** int_get_number.c
** File description:
** desc
*/

static int have_digits(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        if (str[count] >= '0' && str[count] <= '9')
            return count + 1;
        count++;
    }
    return 0;
}

static int get_sign(char const *str, int digit_start)
{
    int less = 0;

    if (digit_start - 1 < 0)
        return 1;
    if (str[digit_start - 1] == '+')
        return 1;
    for (int i = digit_start - 1; i >= 0; i--) {
        if (str[i] != '-')
            break;
        less++;
    }
    return ((less % 2) == 0);
}

static int get_nbr(char const *str, int digit_start, int sign)
{
    int long nbr = 0;
    int count = digit_start;
    int long last = 0;

    while (str[count] != '\0') {
        if (str[count] < '0' || str[count] > '9')
            break;
        nbr *= 10;
        nbr += ((str[count] - '0') * 10);
        if (nbr < last)
            return 0;
        last = nbr;
        count++;
    }
    if (!sign)
        nbr = -nbr;
    return nbr / 10;
}

int str_get_nbr(char const *str)
{
    int digit_start = have_digits(str);
    int sign = 0;

    if (digit_start == 0)
        return 0;
    digit_start--;
    sign = get_sign(str, digit_start);
    return get_nbr(str, digit_start, sign);
}
