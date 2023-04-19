/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include <unistd.h>
#include "utilities.h"

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
