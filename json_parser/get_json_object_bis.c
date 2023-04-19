/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-marius.pain
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include <stdio.h>

json_props_t *json_get_array(json_props_t *json, char *key)
{
    json_props_t *tmp = json_get_props(json, key);

    if (tmp == NULL)
        return NULL;
    if (tmp->type != JSON_ARRAY)
        return NULL;
    return tmp;
}

json_props_t *json_get_array_from_array(json_props_t *json, int index)
{
    json_props_t *tmp = json_get_props_from_array(json, index);

    if (tmp == NULL)
        return NULL;
    if (tmp->type != JSON_ARRAY)
        return NULL;
    return tmp;
}
