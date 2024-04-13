/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdlib.h>



static json_props_t *json_set_props_to_array(json_file_t *fd)
{
    json_props_t *json = json_create_props(NULL, -1, NULL);

    json->key = NULL;
    json->type = json_set_type(fd);
    json->data = json_set_data(fd, json->type);
    if (json->data == NULL)
        return NULL;
    return json;
}

static json_props_t **json_fill_array_loop(json_file_t *fd,
    json_props_t **jsons, int actual)
{
    json_props_t *tmp = NULL;

    while (fd->depth >= actual) {
        tmp = json_set_props_to_array(fd);
        if (tmp == NULL)
            return NULL;
        append_json_object(&jsons, tmp);
        if (json_fd_reach_next_char(fd, ",]", " \n\t") < 0)
            return NULL;
        json_fd_advance_index(fd, 1);
    }
    return jsons;
}

json_props_t **json_fill_array(json_file_t *fd)
{
    json_props_t **jsons = malloc(sizeof(json_props_t *));
    int actual = fd->depth;

    if (jsons == NULL)
        return NULL;
    jsons[0] = NULL;
    json_fd_advance_index(fd, 1);
    if (json_fd_reach_next_char(fd, NULL, " \n\t") < 0)
        return NULL;
    if (fd->str[fd->index] == ']') {
        json_fd_advance_index(fd, 1);
        return jsons;
    }
    json_fd_advance_index(fd, -1);
    return json_fill_array_loop(fd, jsons, actual);
}
