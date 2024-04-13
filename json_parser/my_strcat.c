/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include <stdlib.h>

int my_strlen(char *str)
{
    int len = 0;

    if (str == NULL)
        return 0;
    for (; str[len] != 0; len++);
    return len;
}

char *my_strcat(char *sa, char *sb)
{
    char *tmp = malloc(my_strlen(sa) + my_strlen(sb) + 1);
    int i = 0;
    int j = 0;

    if (tmp == NULL)
        return NULL;
    if (sa != NULL)
        for (; sa[i] != 0; i++)
            tmp[i] = sa[i];
    if (sb != NULL)
        for (; sb[j] != 0; j++)
            tmp[i + j] = sb[j];
    tmp[i + j] = 0;
    return tmp;
}

char *my_strdup(char *str)
{
    char *tmp = malloc(my_strlen(str) + 1);
    int i = 0;

    if (tmp == NULL || str == NULL)
        return NULL;
    for (; str[i] != 0; i++)
        tmp[i] = str[i];
    tmp[i] = 0;
    return tmp;
}

char *my_strdup_ij(char *str, int i, int j)
{
    char *tmp = malloc(j - i + 1);
    int k = 0;

    if (tmp == NULL || str == NULL)
        return NULL;
    for (; i < j; i++) {
        tmp[k] = str[i];
        k++;
    }
    tmp[k] = 0;
    return tmp;
}

int my_strcmp(char *sa, char *sb)
{
    int i = 0;

    if (sa == NULL || sb == NULL)
        return 0;
    for (; sa[i] != 0 && sb[i] != 0; i++)
        if (sa[i] != sb[i])
            return sa[i] - sb[i];
    return sa[i] - sb[i];
}
