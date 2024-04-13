/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdbool.h>

void json_destroy(json_props_t *json)
{
    json_props_t **child = NULL;

    if (json == NULL)
        return;
    if (json->key != NULL)
        free(json->key);
    if ((json->type != JSON_OBJECT && json->type != JSON_ARRAY) &&
    json->data != NULL)
        free(json->data);
    if ((json->type == JSON_OBJECT || json->type == JSON_ARRAY) &&
    json->data != NULL) {
        child = (json_props_t **)(json->data);
        for (int i = 0; child[i] != NULL; i++)
            json_destroy(child[i]);
        free(child);
    }
    free(json);
}

json_props_t *json_get_props(json_props_t *json, char *key)
{
    json_props_t **child = NULL;

    if (json == NULL || key == NULL)
        return NULL;
    if (json->type != JSON_OBJECT)
        return NULL;
    child = (json_props_t **)(json->data);
    for (int i = 0; child[i] != NULL; i++) {
        if (my_strcmp(child[i]->key, key) == 0)
            return child[i];
    }
    if (json->key != NULL)
        json_error_key_not_found(json->key, key);
    else
        json_error_key_not_found("props", key);
    return NULL;
}

json_props_t *json_get_object(json_props_t *json, char *key)
{
    json_props_t *tmp = json_get_props(json, key);

    if (tmp == NULL)
        return NULL;
    if (tmp->type != JSON_OBJECT)
        return NULL;
    return tmp;
}

json_props_t *json_get_props_from_array(json_props_t *array, int index)
{
    json_props_t **child = NULL;
    int len = 0;

    if (array == NULL)
        return NULL;
    if (array->type != JSON_OBJECT && array->type != JSON_ARRAY)
        return NULL;
    child = (json_props_t **)(array->data);
    for (; child[len] != NULL; len++);
    if (index < 0 || index >= len) {
        json_error_index_out_of_range(array->key, index);
        return NULL;
    }
    return child[index];
}

json_props_t *json_find_object(json_props_t *json, char **keys)
{
    if (json == NULL)
        return NULL;
    if (json->type != JSON_OBJECT)
        return NULL;
    for (int i = 0; keys[i] != NULL; i++) {
        json = json_get_props(json, keys[i]);
        if (json == NULL ||
        json->type != JSON_OBJECT || json->type != JSON_ARRAY)
            return NULL;
    }
    return json;
}
