/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-marius.pain
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdlib.h>
#include <stdio.h>

static json_file_t *json_create_file(char *str, char *path)
{
    json_file_t *file = malloc(sizeof(json_file_t));
    if (file == NULL)
        return NULL;

    file->line = 1;
    file->column = 1;
    file->depth = 0;
    file->path = path;
    file->str = str;
    file->size = my_strlen(file->str);
    file->index = 0;
    return file;
}

json_file_t *json_open_file(char *path)
{
    char *line = NULL;
    char *file = NULL;
    char *tmp = NULL;
    size_t len = 0;
    FILE *fd_tmp = fopen(path, "r");

    if (fd_tmp == NULL) {
        my_puterr("json: can't open file: ");
        my_puterr(path);
        my_puterr("\n");
        return NULL;
    }
    while (getline(&line, &len, fd_tmp) > 0) {
        tmp = my_strcat(file, line);
        free(file);
        file = tmp;
    }
    free(line);
    fclose(fd_tmp);
    return json_create_file(file, path);
}

void json_close_file(json_file_t *fd)
{
    free(fd->str);
    free(fd->path);
    free(fd);
}
