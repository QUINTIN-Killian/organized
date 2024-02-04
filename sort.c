/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort the linked list
** del
*/

#include "include/my.h"
#include "include/organized.h"
#include "include/shell.h"

static int error_handling_sort(char **args)
{
    int len_array = my_strlen_array(args);

    if (len_array == 0)
        return 1;
    for (int i = 0; i < len_array; i++) {
        if (my_strcmp(args[i], "-r") != 0 && my_strcmp(args[i], "TYPE") != 0 &&
        my_strcmp(args[i], "NAME") != 0 && my_strcmp(args[i], "ID") != 0)
            return 1;
    }
    return 0;
}

void rev_data(linked_list_t **data_cpy)
{
    linked_list_t *p = NULL;
    linked_list_t *c = (linked_list_t *)(*data_cpy);
    linked_list_t *n = c->next;

    while (n != NULL) {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    }
    c->next = p;
    *data_cpy = c;
}

static void sort_type(linked_list_t **data_cpy, int *rev)
{
    if (*rev == 0) {
        sort_by_type(data_cpy);
    } else {
        sort_by_type_rev(data_cpy);
        *rev = 0;
    }
}

static void sort_name(linked_list_t **data_cpy, int *rev)
{
    if (*rev == 0) {
        sort_by_name(data_cpy);
    } else {
        sort_by_name_rev(data_cpy);
        *rev = 0;
    }
}

static void sort_id(linked_list_t **data_cpy, int *rev)
{
    if (*rev == 0) {
        sort_by_id(data_cpy);
    } else {
        sort_by_id_rev(data_cpy);
        *rev = 0;
    }
}

void call_sort(char *str, linked_list_t **data_cpy, int *rev)
{
    if (my_strcmp(str, "TYPE") == 0) {
        sort_type(data_cpy, rev);
        return;
    }
    if (my_strcmp(str, "NAME") == 0) {
        sort_name(data_cpy, rev);
        return;
    }
    if (my_strcmp(str, "ID") == 0) {
        sort_id(data_cpy, rev);
        return;
    }
}

static void explore_args_loop(linked_list_t **data_cpy, char *arg, int *rev)
{
    if (my_strcmp(arg, "-r") == 0 && *rev == 0)
        *rev = 1;
    else if (my_strcmp(arg, "-r") == 0 && *rev == 1)
        *rev = 0;
    else
        call_sort(arg, data_cpy, rev);
}

int sort(void *data, char **args)
{
    linked_list_t **data_cpy = (linked_list_t **)data;
    int rev = 0;

    if (error_handling_sort(args))
        return 84;
    for (int i = my_strlen_array(args) - 1; i >= 0; i--)
        explore_args_loop(data_cpy, args[i], &rev);
    if (rev)
        rev_data(data_cpy);
    data = data_cpy;
    return 0;
}
