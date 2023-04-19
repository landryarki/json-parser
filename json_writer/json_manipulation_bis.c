/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_writer_back.h"
#include "utilities.h"
#include <stdlib.h>

void json_add_object(json_props_t *json, char *key, json_props_t *obj)
{
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    if (find_json_object((json_props_t **)json->data, key) != -1)
        json_remove_props(json, key);
    append_json_object((json_props_t ***)(&(json->data)), obj);
}

void json_add_array(json_props_t *json, char *key, json_props_t *array)
{
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    if (json->type == JSON_ARRAY)
        key = NULL;
    if (find_json_object((json_props_t **)json->data, key) != -1)
        json_remove_props(json, key);
    append_json_object((json_props_t ***)(&(json->data)), array);
}

void json_remove_props(json_props_t *json, char *key)
{
    json_props_t **tmp = NULL;
    int i = 0;
    int j = 0;
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    for (; ((json_props_t **)json->data)[i] != NULL; i++);
    tmp = malloc(sizeof(json_props_t *) * (i + 1));
    if (tmp == NULL)
        return;
    for (int k = 0; k < i; k++) {
        if (my_strcmp(((json_props_t **)json->data)[k]->key, key) == 0) {
            json_destroy(((json_props_t **)json->data)[k]);
            continue;
        }
        tmp[j] = ((json_props_t **)json->data)[k];
        j++;
    }
    tmp[j] = NULL;
    free(json->data);
    json->data = tmp;
}
