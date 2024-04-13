/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include <stdio.h>

int json_get_array_size(json_props_t *json)
{
    int i = 0;

    if (json == NULL)
        return -1;
    if (json->type != JSON_ARRAY)
        return -1;
    while (((json_props_t **)json->data)[i] != NULL)
        i++;
    return i;
}

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
