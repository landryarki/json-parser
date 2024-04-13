/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdlib.h>

void append_json_object(json_props_t ***jsons, json_props_t *json)
{
    int i = 0;
    json_props_t **tmp = NULL;

    for (; (*jsons)[i] != NULL; i++);
    tmp = malloc(sizeof(json_props_t *) * (i + 2));
    if (tmp == NULL)
        return;
    for (int j = 0; j < i; j++)
        tmp[j] = (*jsons)[j];
    tmp[i] = json;
    tmp[i + 1] = NULL;
    free(*jsons);
    *jsons = tmp;
}

void *json_set_data_switch(json_file_t *fd, int type, int *k, int *good)
{
    switch (type) {
        case JSON_OBJECT:
            return json_fill_object(fd);
        case JSON_ARRAY:
            return json_fill_array(fd);
        case JSON_STRING:
            return json_set_string(fd);
        case JSON_BOOL:
            k[0] = json_set_bool(fd, good); break;
        case JSON_NULL:
            k[0] = json_set_null(fd, good); break;
        case JSON_INT:
            k[0] = json_set_int(fd, good); break;
        case JSON_ERROR:
            json_error_unknown(fd, json_set_error(fd));
            return NULL;
        default:
            break;
    }
    return NULL;
}

void *json_set_data(json_file_t *fd, int type)
{
    int *k = malloc(sizeof(int));
    int *good = malloc(sizeof(int));
    void *data = NULL;
    if (k == NULL || good == NULL)
        return NULL;
    good[0] = -1;
    data = json_set_data_switch(fd, type, k, good);
    if (data == NULL) {
        if (good[0] == -1) {
            free(good);
            free(k);
            return NULL;
        } else
            free(good);
            return k;
    } else {
        free(k);
        free(good);
        return data;
    }
}

static json_props_t **json_fill_object_loop(json_file_t *fd,
json_props_t **jsons, int actual)
{
    json_props_t *tmp = NULL;

    while (fd->depth >= actual) {
        tmp = json_set_props(fd);
        if (tmp == NULL)
            return NULL;
        append_json_object(&jsons,tmp);
        if (json_fd_reach_next_char(fd, ",}", " \n\t") < 0)
            return NULL;
        json_fd_advance_index(fd, 1);
    }
    return jsons;
}

json_props_t **json_fill_object(json_file_t *fd)
{
    json_props_t **jsons = malloc(sizeof(json_props_t *));
    int actual = fd->depth;

    if (jsons == NULL)
        return NULL;
    jsons[0] = NULL;
    json_fd_advance_index(fd, 1);
    if (json_fd_reach_next_char(fd, "}\"", " \n\t") < 0)
        return NULL;
    if (fd->str[fd->index] == '}') {
        json_fd_advance_index(fd, 1);
        return jsons;
    }
    return json_fill_object_loop(fd, jsons, actual);
}
