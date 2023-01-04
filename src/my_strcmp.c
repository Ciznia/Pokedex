/*
** EPITECH PROJECT, 2023
** B-MUL-100-REN-1-1-myradar-hugo.murat
** File description:
** my_strcmp
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}