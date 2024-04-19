/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdlib.h>

char *json_get_key(json_props_t *json)
{
    if (json == NULL)
        return NULL;
    return json->key;
}

int json_get_type(json_props_t *json, char *key)
{
    json_props_t *tmp = NULL;

    if (json == NULL)
        return -1;
    if (key == NULL)
        return json->type;
    tmp = json_get_props(json, key);
    if (tmp == NULL)
        return -1;
    return tmp->type;
}

int json_get_bool(json_props_t *json, char *key)
{
    json_props_t *tmp = NULL;

    if (json == NULL)
        return -1;
    if (key == NULL) {
        if (json->type != JSON_BOOL)
            return -1;
        else
            return *((int *) (json->data));
    }
    tmp = json_get_props(json, key);
    if (tmp == NULL)
        return -1;
    if (tmp->type != JSON_BOOL)
        return -1;
    return *((int *)(tmp->data));
}

char *json_get_string(json_props_t *json, char *key)
{
    json_props_t *tmp = NULL;

    if (json == NULL)
        return NULL;
    if (key == NULL) {
        if (json->type != JSON_STRING)
            return NULL;
        else
            return (char *)(json->data);
    }
    tmp = json_get_props(json, key);
    if (tmp == NULL)
        return NULL;
    if (tmp->type != JSON_STRING)
        return NULL;
    return (char *)(tmp->data);
}

int json_get_int(json_props_t *json, char *key)
{
    json_props_t *tmp = NULL;

    if (json == NULL)
        return 0;
    if (key == NULL) {
        if (json->type != JSON_INT)
            return 0;
        else
            return *((int *) (json->data));
    }
    tmp = json_get_props(json, key);
    if (tmp == NULL)
        return 0;
    if (tmp->type != JSON_INT)
        return 0;
    return *((int *)(tmp->data));
}
