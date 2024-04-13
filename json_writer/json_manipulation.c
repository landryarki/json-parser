/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_writer_back.h"
#include "utilities.h"
#include <stdlib.h>

int find_json_object(json_props_t **json, char *key)
{
    int i = 0;

    if (json == NULL || key == NULL)
        return -1;
    for (; json[i] != NULL; i++) {
        if (my_strcmp(json[i]->key, key) == 0)
            return i;
    }
    return -1;
}

void json_add_int(json_props_t *json, char *key, int value)
{
    json_props_t *new;
    int *a = malloc(sizeof(int));

    if (a == NULL)
        return;
    *a = value;
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    if (find_json_object((json_props_t **)json->data, key) != -1)
        json_remove_props(json, key);
    new = json_create_props(my_strdup(key), JSON_INT, a);
    append_json_object((json_props_t ***)(&(json->data)), new);
}

void json_add_string(json_props_t *json, char *key, char *value)
{
    json_props_t *new;

    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    if (find_json_object((json_props_t **)json->data, key) != -1)
        json_remove_props(json, key);
    new = json_create_props(my_strdup(key), JSON_STRING,
    my_strdup(value));
    append_json_object((json_props_t ***)(&(json->data)), new);
}

void json_add_bool(json_props_t *json, char *key, int value)
{
    json_props_t *new;
    int *a = malloc(sizeof(int));

    if (a == NULL)
        return;
    *a = value;
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    if (find_json_object((json_props_t **)json->data, key) != -1)
        json_remove_props(json, key);
    new = json_create_props(my_strdup(key), JSON_BOOL, a);
    append_json_object((json_props_t ***)(&(json->data)), new);
}

void json_add_null(json_props_t *json, char *key)
{
    json_props_t *new;

    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    if (find_json_object((json_props_t **)json->data, key) != -1)
        json_remove_props(json, key);
    new = json_create_props(my_strdup(key), JSON_NULL, NULL);
    append_json_object((json_props_t ***)(&(json->data)), new);
}
