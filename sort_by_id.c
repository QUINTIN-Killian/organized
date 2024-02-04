/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort the linked list by if
** sort_by_id
*/

#include "include/my.h"
#include "include/organized.h"
#include "include/shell.h"

static void inv_elt_id(linked_list_t **p, linked_list_t **c,
    linked_list_t **n, linked_list_t **data_cpy)
{
    if ((*c)->id > (*n)->id && (*p) == NULL) {
        (*c)->next = (*n)->next;
        (*n)->next = (*c);
        *data_cpy = (*n);
    }
    if ((*c)->id > (*n)->id && (*p) != NULL) {
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

void sort_by_id(linked_list_t **data_cpy)
{
    linked_list_t *p;
    linked_list_t *c;
    linked_list_t *n;

    for (int i = 0; i < get_len_data(*data_cpy); i++) {
        p = NULL;
        c = *data_cpy;
        n = c->next;
        while (n != NULL)
            inv_elt_id(&p, &c, &n, data_cpy);
    }
}

static void inv_elt_id_rev(linked_list_t **p, linked_list_t **c,
    linked_list_t **n, linked_list_t **data_cpy)
{
    if ((*c)->id < (*n)->id && (*p) == NULL) {
        (*c)->next = (*n)->next;
        (*n)->next = (*c);
        *data_cpy = (*n);
    }
    if ((*c)->id < (*n)->id && (*p) != NULL) {
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

void sort_by_id_rev(linked_list_t **data_cpy)
{
    linked_list_t *p;
    linked_list_t *c;
    linked_list_t *n;

    for (int i = 0; i < get_len_data(*data_cpy); i++) {
        p = NULL;
        c = *data_cpy;
        n = c->next;
        while (n != NULL)
            inv_elt_id_rev(&p, &c, &n, data_cpy);
    }
}
