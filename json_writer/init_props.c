/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_writer_back.h"
#include "utilities.h"

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
