/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "utilities.h"
#include "my_json_parser_back.h"
#include <unistd.h>
#include <stdlib.h>

void json_error_syntax(json_file_t *fd, char *wrong, char *expected)
{
    my_puterr(fd->path);
    my_puterr(": line ");
    my_puterr(my_put_nbr_to_str(fd->line, 0));
    my_puterr(": column ");
    my_puterr(my_put_nbr_to_str(fd->column, 0));
    my_puterr(": invalid syntax: got '");
    my_puterr(wrong);
    my_puterr("' instead of '");
    my_puterr(expected);
    my_puterr("'\n");
}

void json_error_unknown(json_file_t *fd, char *wrong)
{
    my_puterr(fd->path);
    my_puterr(": line ");
    my_puterr(my_put_nbr_to_str(fd->line, 0));
    my_puterr(": column ");
    my_puterr(my_put_nbr_to_str(fd->column, 0));
    my_puterr(": unknown type '");
    my_puterr(wrong);
    my_puterr("'\n");
}

void json_error_key_not_found(char *name, char *key)
{
    my_puterr("json: ");
    my_puterr(name);
    my_puterr(": key '");
    my_puterr(key);
    my_puterr("' not found\n");
}

void json_error_index_out_of_range(char *name, int index)
{
    my_puterr("json: ");
    my_puterr(name);
    my_puterr(": index ");
    my_puterr(my_put_nbr_to_str(index, 0));
    my_puterr(" out of range\n");
}
