/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-marius.pain
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser.h"
#include "utilities.h"
#include <stdlib.h>

void json_close_guide(json_guide_t *guide)
{
    if (guide == NULL)
        return;
    free(guide);
}

json_props_t *json_read_guide(json_guide_t *guide)
{
    json_props_t **child = NULL;

    if (guide == NULL)
        return NULL;
    if (guide->json->type == JSON_OBJECT || guide->json->type == JSON_ARRAY)
        child = (json_props_t**)(guide->json->data);
    else
        return NULL;
    if (guide->index >= guide->size)
        return NULL;
    if (child[guide->index] == NULL)
        return NULL;
    guide->index++;
    return child[guide->index - 1];
}

json_guide_t *json_open_guide(json_props_t *json)
{
    json_guide_t *guide = malloc(sizeof(json_guide_t));
    json_props_t **child = NULL;

    if (guide == NULL)
        return NULL;
    if (json == NULL)
        return NULL;
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return NULL;
    child = (json_props_t**)(json->data);
    if (child == NULL)
        return NULL;
    guide->size = 0;
    for (; child[guide->size] != NULL; guide->size++);
    guide->json = json;
    guide->index = 0;
    return guide;
}
