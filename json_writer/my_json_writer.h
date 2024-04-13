/*
** EPITECH PROJECT, 2023
** my_json
** File description:
** No file there , just an epitech header example .
*/

#pragma once

/* Un props json a un type qui définit la valeur
 * qu'il va contenir, il a aussi une clé dans la plus part des cas qui va
 * servir a l'identifier.
 * un props json s'écrit "json_props_t" et sera tout le temps un pointeur
 * */

typedef struct json_props_s {
    char *key;
    void *data;
    int type;
} json_props_t;

/* Il y a 6 types de valeur dans ce parser pris en compte (voir example_1.json)
 * et sont les suivants:
 *      INT une valeur numérique
 *      STRING une chaine de caractère
 *      BOOL un booléen
 *      NULL rien... (note: il faut ecrire "null" et non pas laisser un vide)
 *      ARRAY un tableau de valeur (note que ce sont des valeurs et non pas
 *          des props, elles n'ont pas de clé, aussi une valeur peut tres bien
 *          etre un autre tableau, ou un objet)
 *      OBJECT un objet qui contient d'autres props json (note qu'il faut
 *          différencier un props qui a un type, et le type
 *          object qui a pour valeur d'autres props json)
 *
 *   ERROR un type d'erreur, il est utilisé pour les fonctions qui retournent
 *       un props json, si il y a une erreur.
 * */

typedef enum json_type {
    JSON_ERROR = -1,
    JSON_NULL,
    JSON_STRING,
    JSON_INT,
    JSON_BOOL,
    JSON_ARRAY,
    JSON_OBJECT,
} json_type_t;

/*-----------------------------*/

/* Si vous voulez vous pouvez utiliser les types suivants
 * qui sont des alias pour les types de base
 * */

typedef json_props_t json_object_t;
typedef json_props_t json_array_t;

/*-----------------------------*/

/* Cette fonction permet de transformer un objet ou tableau json en un fichier
 * json, elle prend en paramètre le nom du fichier et le props json
 * */

////////////////////////////////////////
///  \brief Write a json file
///
///  \param name The name of the file
///  \param json The json object or array to transform
///
////////////////////////////////////////

void json_write_file(char *name, json_props_t *json);

/*-----------------------------*/

/* Pour pouvoir créer un objet ou un tableau json, il faut utiliser les
 * fonctions suivantes
 * */

////////////////////////////////////////
///  \brief Create a json object
///
///  \param key The key of the object
///
///  \return The json object
///
////////////////////////////////////////

json_props_t *json_init_object(char *key);

////////////////////////////////////////
///  \brief Create a json array
///
///  \param key The key of the array
///
///  \return The json array
///
////////////////////////////////////////

json_props_t *json_init_array(char *key);

/*-----------------------------*/

/* Pour pouvoir ajouter des valeurs a un objet ou un tableau json, il faut
 * utiliser les fonctions suivantes
 * (note: mettre une clé deja existante dans un objet remplacera
 * la valeur de celui ci)
 * */

////////////////////////////////////////
///  \brief Add a string to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the string
///  \param value The value of the string
///
////////////////////////////////////////

void json_add_string(json_props_t *json, char *key, char *value);

////////////////////////////////////////
///  \brief Add a int to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the int
///  \param value The value of the int
///
////////////////////////////////////////

void json_add_int(json_props_t *json, char *key, int value);

////////////////////////////////////////
///  \brief Add a bool to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the bool
///  \param value The value of the bool
///
////////////////////////////////////////

void json_add_bool(json_props_t *json, char *key, int value);

////////////////////////////////////////
///  \brief Add a null to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the null
///
////////////////////////////////////////

void json_add_null(json_props_t *json, char *key);

////////////////////////////////////////
///  \brief Add a json object to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the object
///  \param value The value of the object
///
////////////////////////////////////////

void json_add_object(json_props_t *json, char *key, json_props_t *value);

////////////////////////////////////////
///  \brief Add a json array to a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the array
///  \param value The value of the array
///
////////////////////////////////////////

void json_add_array(json_props_t *json, char *key, json_props_t *value);

/* (note: pour ajouter un tableau ou un objet a un tableau ou un objet,
 * il faut les initialiser avec la fonction correspondante, puis les ajouter)
 * */

/*-----------------------------*/

/* Pour pouvoir retirer des props d'un objet ou un tableau json, il faut
 * utiliser la fonction suivante
 * */

////////////////////////////////////////
///  \brief Remove a json props from a json object or array
///
///  \param json The json object or array parent
///  \param key The key of the props
///
////////////////////////////////////////

void json_remove_props(json_props_t *json, char *key);

/*-----------------------------*/

/* Une fois le fichier json écrit, il faut libérer la mémoire allouée
 * par la structure json, il faut utiliser la fonction suivante
 * */

////////////////////////////////////////////////////////////
/// \brief destroy a json object and all the objects it contains
///
/// \param json object to destroy
////////////////////////////////////////////////////////////

void json_destroy(json_props_t *json);
