/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-marius.pain
** File description:
** No file there , just an epitech header example .
*/

#ifndef B_MUL_200_NAN_2_1_MYRPG_MARIUS_PAIN_PARSER_JSON_H
    #define B_MUL_200_NAN_2_1_MYRPG_MARIUS_PAIN_PARSER_JSON_H

typedef struct json_file_s {
    char *path;
    char *str;
    int size;
    int index;
    int line;
    int column;
    int depth;
} json_file_t;

typedef enum json_type {
    JSON_ERROR = -1,
    JSON_NULL,
    JSON_STRING,
    JSON_INT,
    JSON_BOOL,
    JSON_ARRAY,
    JSON_OBJECT,
} json_type_t;

typedef struct json_props_s {
    char *key;
    void *data;
    int type;
} json_props_t;

typedef struct json_guide_s {
    json_props_t *json;
    int index;
    int size;
} json_guide_t;

typedef json_props_t json_object_t;
typedef json_props_t json_array_t;

json_props_t *json_create_props(char *key, int type, void *data);
json_props_t *json_create_from_file(char *path);

json_file_t *json_open_file(char *path);
void json_close_file(json_file_t *fd);

void json_fd_advance_index(json_file_t *fd, int nb);
int json_fd_reach_next_char(json_file_t *fd, char *delim, char *ignore);

void json_error_syntax(json_file_t *fd, char *wrong, char *expected);
void json_error_unknown(json_file_t *fd, char *wrong);
void json_error_key_not_found(char *name, char *key);
void json_error_index_out_of_range(char *name, int index);

json_props_t *json_set_props(json_file_t *fd);
int json_set_type(json_file_t *fd);
char *json_set_key(json_file_t *fd);
void *json_set_data(json_file_t *fd, int type);

char *json_set_string(json_file_t *fd);
int json_set_int(json_file_t *fd);
int json_set_bool(json_file_t *fd);
int json_set_null(json_file_t *fd);
json_props_t **json_fill_object(json_file_t *fd);
json_props_t **json_fill_array(json_file_t *fd);
char *json_set_error(json_file_t *fd);

char *json_get_key(json_props_t *json);
int json_get_type(json_props_t *json, char *key);
int json_get_bool(json_props_t *json, char *key);
char *json_get_string(json_props_t *json, char *key);
int json_get_int(json_props_t *json, char *key);
json_props_t *json_get_props(json_props_t *json, char *key);
json_props_t *json_get_object(json_props_t *json, char *key);
json_props_t *json_find_object(json_props_t *json, char **keys);

json_props_t *json_get_props_from_array(json_props_t *array, int index);
json_props_t *json_get_props_from_object(json_props_t *object, char *key);
int json_get_type_from_array(json_props_t *json, int index);
int json_get_bool_from_array(json_props_t *json, int index);
char *json_get_string_from_array(json_props_t *json, int index);
int json_get_int_from_array(json_props_t *json, int index);
int json_get_array_size(json_props_t *json);

json_props_t *json_read_guide(json_guide_t *guide);
json_guide_t *json_open_guide(json_props_t *json);
void json_close_guide(json_guide_t *guide);

void json_destroy(json_props_t *json);

#endif //B_MUL_200_NAN_2_1_MYRPG_MARIUS_PAIN_PARSER_JSON_H
