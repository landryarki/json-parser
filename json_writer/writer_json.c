/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "utilities.h"
#include "my_json_writer_back.h"
#include <stdio.h>

void json_spacing(FILE *file, int depth)
{
    for (int i = 0; i < depth; i++)
        fprintf(file, "  ");
}

void json_write_object(FILE *file, json_props_t *json, int depth)
{
    json_props_t **array = (json_props_t **)json->data;

    json_spacing(file, depth);
    json_write_key(file, json, depth);
    fwrite("{\n", 1, 2, file);
    for (int i = 0; array[i] != NULL; i++) {
        json_write_content(file, array[i], depth + 1);
        if (array[i + 1] != NULL)
            fwrite(",\n", 1, 2, file);
        else
            fwrite("\n", 1, 1, file);
    }
    json_spacing(file, depth);
    fwrite("}", 1, 1, file);
}

void json_write_array(FILE *file, json_props_t *json, int depth)
{
    json_props_t **array = (json_props_t **)json->data;

    json_spacing(file, depth);
    json_write_key(file, json, depth);
    fwrite("[\n", 1, 2, file);
    for (int i = 0; array[i] != NULL; i++) {
        json_write_content(file, array[i], depth + 1);
        if (array[i + 1] != NULL)
            fwrite(",\n", 1, 2, file);
        else
            fwrite("\n", 1, 1, file);
    }
    json_spacing(file, depth);
    fwrite("]", 1, 1, file);
}

void json_write_content(FILE *file, json_props_t *json, int depth)
{
    switch (json->type) {
        case JSON_ARRAY:
            json_write_array(file, json, depth);
            break;
        case JSON_OBJECT:
            json_write_object(file, json, depth);
            break;
        case JSON_INT:
            json_write_int(file, json, depth);
            break;
        case JSON_STRING:
            json_write_string(file, json, depth);
            break;
        case JSON_BOOL:
            json_write_bool(file, json, depth);
            break;
        case JSON_NULL:
            json_write_null(file, json, depth);
            break;
    }
}

void json_write_file(char *name, json_props_t *json)
{
    FILE *file = fopen(name, "w");
    int depth = 0;

    if (file == NULL)
        return;
    if (json == NULL)
        return;
    if (json->type != JSON_OBJECT && json->type != JSON_ARRAY)
        return;
    char *json_key = json->key;
    json->key = NULL;
    json_write_content(file, json, depth);
    json->key = json_key;
    fclose(file);
}

//int main(void)
//{
//    json_props_t *json = json_create_from_file("example_1.json");
//    json_write_file("new_example.json", json);
//    json_destroy(json);
//    json = json_create_from_file("new_example.json");
//    return 0;
//}
