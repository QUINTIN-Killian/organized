/*
** EPITECH PROJECT, 2023
** organized
** File description:
** delete a node in the linked list
** del
*/
//add WIRE 0, WIRE 1, WIRE 2

#include "include/my.h"
#include "include/organized.h"
#include "include/shell.h"

static int is_id_in_data(int id_search, linked_list_t **data_cpy)
{
    linked_list_t *current = (linked_list_t *)(*data_cpy);

    while (current != NULL) {
        if (current->id == id_search)
            return 1;
        current = current->next;
    }
    return 0;
}

int error_handling_del(char **args)
{
    int total_len = my_strlen_array(args);

    if (total_len == 0)
        return 1;
    for (int i = 0; i < total_len; i++) {
        if (!my_str_isnum(args[i]))
            return 1;
    }
    return 0;
}

void print_deleted_elt(linked_list_t *node)
{
    my_putstr(node->type);
    my_putstr(" n°");
    my_put_nbr(node->id);
    my_putstr(" - \"");
    my_putstr(node->name);
    my_putstr("\" deleted.\n");
}

static void free_node(linked_list_t *node)
{
    free(node->type);
    free(node->name);
    free(node);
}

linked_list_t *del_first_node(linked_list_t *current,
    linked_list_t *tmp)
{
    tmp = current;
    current = current->next;
    print_deleted_elt(tmp);
    free_node(tmp);
    return current;
}

linked_list_t *del_node(linked_list_t **data_cpy, int id_del)
{
    linked_list_t *current = (linked_list_t *)(*data_cpy);
    linked_list_t *tmp = NULL;

    if (current == NULL)
        return current;
    if (current->id == id_del)
        return del_first_node(current, tmp);
    while (current->next != NULL) {
        if (current->next->id == id_del) {
            tmp = current->next;
            print_deleted_elt(tmp);
            current->next = current->next->next;
            free_node(tmp);
            return *data_cpy;
        }
        current = current->next;
    }
    return *data_cpy;
}

int del(void *data, char **args)
{
    linked_list_t **data_cpy = (linked_list_t **)data;

    if (error_handling_del(args))
        return 84;
    for (int i = 0; i < my_strlen_array(args); i++) {
        if (!is_id_in_data(convert_str_in_int(args[i]), data_cpy))
            return 84;
        *data_cpy = del_node(data_cpy, convert_str_in_int(args[i]));
    }
    data = data_cpy;
    return 0;
}
