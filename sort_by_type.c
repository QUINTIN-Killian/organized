/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort the linked list by type
** sort_by_type
*/

#include "include/my.h"
#include "include/organized.h"
#include "include/shell.h"

static void inv_elt_type(linked_list_t **p, linked_list_t **c,
    linked_list_t **n, linked_list_t **data_cpy)
{
    if (my_strcmp((*c)->type, (*n)->type) > 0 && (*p) == NULL) {
        (*c)->next = (*n)->next;
        (*n)->next = (*c);
        *data_cpy = (*n);
    }
    if (my_strcmp((*c)->type, (*n)->type) > 0 && (*p) != NULL) {
        (*c)->next = (*n)->next;
        (*n)->next = (*c);
        (*p)->next = (*n);
    }
    if ((*p) != NULL)
        (*p) = (*p)->next;
    else
        (*p) = *data_cpy;
    (*c) = (*p)->next;
    (*n) = (*c)->next;
}

void sort_by_type(linked_list_t **data_cpy)
{
    linked_list_t *p;
    linked_list_t *c;
    linked_list_t *n;

    for (int i = 0; i < get_len_data(*data_cpy); i++) {
        p = NULL;
        c = *data_cpy;
        n = c->next;
        while (n != NULL)
            inv_elt_type(&p, &c, &n, data_cpy);
    }
}

static void inv_elt_type_rev(linked_list_t **p, linked_list_t **c,
    linked_list_t **n, linked_list_t **data_cpy)
{
    if (my_strcmp((*c)->type, (*n)->type) < 0 && (*p) == NULL) {
        (*c)->next = (*n)->next;
        (*n)->next = (*c);
        *data_cpy = (*n);
    }
    if (my_strcmp((*c)->type, (*n)->type) < 0 && (*p) != NULL) {
        (*c)->next = (*n)->next;
        (*n)->next = (*c);
        (*p)->next = (*n);
    }
    if ((*p) != NULL)
        (*p) = (*p)->next;
    else
        (*p) = *data_cpy;
    (*c) = (*p)->next;
    (*n) = (*c)->next;
}

void sort_by_type_rev(linked_list_t **data_cpy)
{
    linked_list_t *p;
    linked_list_t *c;
    linked_list_t *n;

    for (int i = 0; i < get_len_data(*data_cpy); i++) {
        p = NULL;
        c = *data_cpy;
        n = c->next;
        while (n != NULL)
            inv_elt_type_rev(&p, &c, &n, data_cpy);
    }
}
