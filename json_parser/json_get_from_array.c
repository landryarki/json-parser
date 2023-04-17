/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-marius.pain
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser.h"
#include "utilities.h"
#include <stdlib.h>

int json_get_type_from_array(json_props_t *json, int index)
{
    json_props_t *tmp = NULL;
    if (json == NULL)
        return -1;
    if (index < 0)
        return json->type;
    tmp = json_get_props_from_array(json, index);
    if (tmp == NULL)
        return -1;
    return tmp->type;
}

int json_get_bool_from_array(json_props_t *json, int index)
{
    json_props_t *tmp = NULL;
    if (json == NULL)
        return -1;
    if (index < 0)
        return -1;
    tmp = json_get_props_from_array(json, index);
    if (tmp == NULL)
        return -1;
    if (tmp->type != JSON_BOOL)
        return -1;
    return *((int*)(tmp->data));
}

char *json_get_string_from_array(json_props_t *json, int index)
{
    json_props_t *tmp = NULL;
    if (json == NULL)
        return NULL;
    if (index < 0)
        return NULL;
    tmp = json_get_props_from_array(json, index);
    if (tmp == NULL)
        return NULL;
    if (tmp->type != JSON_STRING)
        return NULL;
    return (char*)(tmp->data);
}

int json_get_int_from_array(json_props_t *json, int index)
{
    json_props_t *tmp = NULL;
    if (json == NULL)
        return -1;
    if (index < 0)
        return -1;
    tmp = json_get_props_from_array(json, index);
    if (tmp == NULL)
        return -1;
    if (tmp->type != JSON_INT)
        return -1;
    return *((int*)(tmp->data));
}

json_props_t *json_get_object_from_array(json_props_t *json, int index)
{
    json_props_t *tmp = NULL;
    if (json == NULL)
        return NULL;
    if (index < 0)
        return NULL;
    tmp = json_get_props_from_array(json, index);
    if (tmp == NULL)
        return NULL;
    if (tmp->type != JSON_OBJECT)
        return NULL;
    return (json_props_t*)(tmp->data);
}
