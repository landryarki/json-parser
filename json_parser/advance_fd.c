/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#include "my_json_parser_back.h"
#include "utilities.h"
#include <stdbool.h>
#include <stdlib.h>

static bool char_in_str(char c, char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == c)
            return true;
    return false;
}

static void json_fd_back_index(json_file_t *fd, int n)
{
    for (int i = 0; i < n; i++) {
        if (fd->index > 0)
            fd->index--;
        if (fd->str[fd->index] == '\n') {
            fd->line -= 1;
            fd->column = -69;
        } else
            fd->column -= 1;
        if (fd->str[fd->index + 1] == '{' || fd->str[fd->index + 1] == '[')
            fd->depth -= 1;
        if (fd->str[fd->index + 1] == '}' || fd->str[fd->index + 1] == ']')
            fd->depth += 1;
    }
}

void json_fd_advance_index(json_file_t *fd, int n)
{
    if (n == 0)
        return;
    if (n < 0)
        return json_fd_back_index(fd, n * -1);
    for (int i = 0; i < n; i++) {
        if (fd->size > fd->index)
            fd->index++;
        if (fd->index == fd->size)
            break;
        if (fd->index > 0 && fd->str[fd->index - 1] == '\n') {
            fd->line += 1;
            fd->column = 1;
        } else
            fd->column += 1;
        if (fd->str[fd->index] == '{' || fd->str[fd->index] == '[')
            fd->depth += 1;
        if (fd->str[fd->index] == '}' || fd->str[fd->index] == ']')
            fd->depth -= 1;
    }
}

int json_fd_reach_next_char(json_file_t *fd, char *delim, char *ignore)
{
    if (delim == NULL && ignore == NULL)
        return 0;
    for (int i = 0; fd->str[fd->index] != 0; i++) {
        if (delim != NULL && char_in_str(fd->str[fd->index], delim))
            return i;
        if (delim == NULL && ignore != NULL &&
            !(char_in_str(fd->str[fd->index], ignore)))
            return i;
        if (ignore != NULL && !(char_in_str(fd->str[fd->index], ignore)))
            break;
        json_fd_advance_index(fd, 1);
    }
    json_error_syntax(fd, char_to_str(fd->str[fd->index]), delim);
    return -1;
}
