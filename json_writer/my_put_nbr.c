/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "utilities.h"
#include <stdlib.h>

char *my_put_nbr_to_str(int nb, int index)
{
    char *tmp = NULL;

    if (nb < 0) {
        tmp = my_strcat("-", my_put_nbr_to_str(-nb, index + 1));
    } else if (nb > 9) {
        tmp = my_strcat(my_put_nbr_to_str(nb / 10, index + 1),
                        my_put_nbr_to_str(nb % 10, index + 1));
    } else {
        return char_to_str(nb + '0');
    }
    return tmp;
}

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;
    int neg = 1;

    if (str[0] == '-') {
        neg = -1;
        i++;
    }
    for (; str[i] != 0; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return nb * neg;
}

char *char_to_str(char c)
{
    char *str = malloc(sizeof(char) * 2);

    if (str == NULL)
        return NULL;
    str[0] = c;
    str[1] = 0;
    return str;
}

int my_str_isnum(char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    if (str[0] == '-')
        i++;
    for (; str[i] != 0; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
