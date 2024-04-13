/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

json_props_t *json_create_props(char *key, int type, void *data)
{
    json_props_t *json = malloc(sizeof(json_props_t));

    if (json == NULL)
        return NULL;
    json->key = key;
    json->data = data;
    json->type = type;
    return json;
}

char *json_set_key(json_file_t *fd)
{
    char *key = NULL;
    int i = 0;
    int j = 0;

    if (json_fd_reach_next_char(fd, "\"", " \n\t") < 0)
        return NULL;
    json_fd_advance_index(fd, 1);
    i = fd->index;
    j = json_fd_reach_next_char(fd, "\"\n", NULL);
    if (fd->str[i + j] == '\n') {
        json_error_syntax(fd, "\\n", "char");
        return NULL;
    }
    if (j < 0)
        return NULL;
    key = my_strdup_ij(fd->str, i, i + j);
    if (key == NULL)
        return NULL;
    json_fd_advance_index(fd, 1);
    return key;
}

int json_set_type(json_file_t *fd)
{
    json_fd_advance_index(fd, 1);
    json_fd_reach_next_char(fd, NULL, " \n\t");

    switch (fd->str[fd->index]) {
        case '{':
            return JSON_OBJECT;
        case '[':
            return JSON_ARRAY;
        case '"':
            return JSON_STRING;
        case 't': case 'f':
            return JSON_BOOL;
        case 'n':
            return JSON_NULL;
        default:
            if ((fd->str[fd->index] >= '0' && fd->str[fd->index] <= '9') ||
            fd->str[fd->index] == '-')
                return JSON_INT;
            else
                return JSON_ERROR;
    }
}

json_props_t *json_set_props(json_file_t *fd)
{
    json_props_t *json = json_create_props(NULL, -1, NULL);

    json->key = json_set_key(fd);
    if (json->key == NULL)
        return NULL;
    if (json_fd_reach_next_char(fd, ":", " \n\t") < 0)
        return NULL;
    json->type = json_set_type(fd);
    json->data = json_set_data(fd, json->type);
    if (json->data == NULL)
        return NULL;
    return json;
}

json_props_t *json_create_from_file(char *path)
{
    json_props_t *json = json_create_props
            (my_strdup(path), JSON_ERROR, NULL);
    json_file_t *fd = json_open_file(my_strdup(path));

    if (fd == NULL || fd->size == 0)
        return NULL;
    if (json_fd_reach_next_char(fd, "{[", " \n\t") < 0)
        return NULL;
    switch (fd->str[fd->index]) {
        case '{': json->type = JSON_OBJECT;
            json->data = json_fill_object(fd); break;
        case '[': json->type = JSON_ARRAY;
            json->data = json_fill_array(fd); break;
        default:
            return NULL;
    }
    if (json->data == NULL)
        return NULL;
    json_close_file(fd);
    return json;
}
