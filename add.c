/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** add a node in the linked list
** add
*/

#include "include/my.h"
#include "include/organized.h"
#include "include/shell.h"

static int is_right_type(char *str)
{
    if (my_strcmp(str, "ACTUATOR") == 0)
        return 1;
    if (my_strcmp(str, "DEVICE") == 0)
        return 1;
    if (my_strcmp(str, "PROCESSOR") == 0)
        return 1;
    if (my_strcmp(str, "SENSOR") == 0)
        return 1;
    if (my_strcmp(str, "WIRE") == 0)
        return 1;
    return 0;
}

int error_handling_add(char **args)
{
    int total_len = my_strlen_array(args);

    if (total_len % 2 != 0 || total_len == 0)
        return 1;
    for (int i = 0; i < my_strlen_array(args); i++) {
        if (i % 2 == 0 && (!my_str_isupper(args[i]) ||
        !is_right_type(args[i]))) {
            return 1;
        }
    }
    return 0;
}

void print_added_elt(linked_list_t *node)
{
    my_putstr(node->type);
    my_putstr(" n°");
    my_put_nbr(node->id);
    my_putstr(" - \"");
    my_putstr(node->name);
    my_putstr("\" added.\n");
}

int get_highest_nbr(void *data)
{
    linked_list_t *node = (linked_list_t *)data;
    int nbr = 0;

    while (node != NULL) {
        if (nbr <= node->id)
            nbr = node->id + 1;
        node = node->next;
    }
    return nbr;
}

linked_list_t *my_put_in_list(linked_list_t **head, int id,
    char *type, char *name)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    node->id = id;
    node->type = my_strdup(type);
    node->name = my_strdup(name);
    node->next = *head;
    *head = node;
    return node;
}

int add(void *data, char **args)
{
    int elt = 0;
    linked_list_t **head = (linked_list_t **)data;

    if (error_handling_add(args))
        return 84;
    while (elt < my_strlen_array(args)) {
        print_added_elt(my_put_in_list(head, get_highest_nbr(*head),
        args[elt], args[elt + 1]));
        elt += 2;
    }
    data = head;
    return 0;
}
