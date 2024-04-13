/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_writer_back.h"
#include "utilities.h"

void json_write_key(FILE *file, json_props_t *json, int depth)
{
    if (json->key != NULL) {
        fwrite("\"", 1, 1, file);
        fwrite(json->key, 1, my_strlen(json->key), file);
        fwrite("\"", 1, 1, file);
        fwrite(":", 1, 1, file);
        fwrite(" ", 1, 1, file);
    }
}

void json_write_string(FILE *file, json_props_t *json, int depth)
{
    json_spacing(file, depth);
    json_write_key(file, json, depth);
    fwrite("\"", 1, 1, file);
    fwrite((char *)json->data, 1, my_strlen((char *)json->data), file);
    fwrite("\"", 1, 1, file);
}

void json_write_int(FILE *file, json_props_t *json, int depth)
{
    char *str = NULL;

    json_spacing(file, depth);
    json_write_key(file, json, depth);
    str = my_put_nbr_to_str(*((int *)json->data), 0);
    fwrite(str, 1, my_strlen(str), file);
    free(str);
}

void json_write_bool(FILE *file, json_props_t *json, int depth)
{
    json_spacing(file, depth);
    json_write_key(file, json, depth);
    if (*((int *)json->data) == 1)
        fwrite("true", 1, 4, file);
    else
        fwrite("false", 1, 5, file);
}

void json_write_null(FILE *file, json_props_t *json, int depth)
{
    json_spacing(file, depth);
    json_write_key(file, json, depth);
    fwrite("null", 1, 4, file);
}
