/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_writer_back.h"
#include "utilities.h"
#include <stdlib.h>

json_props_t *json_init_object(char *key)
{
    json_props_t *json = json_create_props(my_strdup(key), JSON_OBJECT, NULL);
    return json;
}

json_props_t *json_init_array(char *key)
{
    json_props_t *json = json_create_props(my_strdup(key), JSON_ARRAY, NULL);
    return json;
}

void json_add_int(json_props_t *json, char *key, int value)
{
    int *a = malloc(sizeof(int));
    if (a == NULL)
        return;
    *a = value;
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    json_props_t *new = json_create_props(my_strdup(key), JSON_INT, a);
    append_json_object((json_props_t ***)(&(json->data)), new);
}

void json_add_string(json_props_t *json, char *key, char *value)
{
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    json_props_t *new = json_create_props(my_strdup(key), JSON_STRING,
    my_strdup(value));
    append_json_object((json_props_t ***)(&(json->data)), new);
}

void json_add_bool(json_props_t *json, char *key, int value)
{
    int *a = malloc(sizeof(int));
    if (a == NULL)
        return;
    *a = value;
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    json_props_t *new = json_create_props(my_strdup(key), JSON_BOOL, a);
    append_json_object((json_props_t ***)(&(json->data)), new);
}

void json_add_null(json_props_t *json, char *key)
{
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    json_props_t *new = json_create_props(my_strdup(key), JSON_NULL, NULL);
    append_json_object((json_props_t ***)(&(json->data)), new);
}

void json_add_object(json_props_t *json, char *key, json_props_t *obj)
{
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    append_json_object((json_props_t ***)(&(json->data)), obj);
}

void json_add_array(json_props_t *json, char *key, json_props_t *array)
{
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    append_json_object((json_props_t ***)(&(json->data)), array);
}
