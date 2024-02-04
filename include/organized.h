/*
** EPITECH PROJECT, 2023
** organized
** File description:
** header file
** organized
*/

#ifndef ORGANIZED_H_
    #define ORGANIZED_H_

typedef struct linked_list {
    int id;
    char *type;
    char *name;
    struct linked_list *next;
} linked_list_t;

//main.c :
int get_len_data(linked_list_t *data);

//sort_by_type.c :
void sort_by_type(linked_list_t **data_cpy);
void sort_by_type_rev(linked_list_t **data_cpy);

//sort_by_name.c :
void sort_by_name(linked_list_t **data_cpy);
void sort_by_name_rev(linked_list_t **data_cpy);

//sort_by_id.c :
void sort_by_id(linked_list_t **data_cpy);
void sort_by_id_rev(linked_list_t **data_cpy);

#endif
