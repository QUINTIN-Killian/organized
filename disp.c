/*
** EPITECH PROJECT, 2023
** organized
** File description:
** display the linked list
** del
*/

#include "include/my.h"
#include "include/organized.h"
#include "include/shell.h"

void display_elt(linked_list_t *node)
{
    my_putstr(node->type);
    my_putstr(" n°");
    my_put_nbr(node->id);
    my_putstr(" - \"");
    my_putstr(node->name);
    my_putstr("\"\n");
}

int disp(void *data, char **args)
{
    linked_list_t **node = (linked_list_t **)data;
    linked_list_t *tmp = *node;

    if (my_strlen_array(args) != 0)
        return 84;
    while (tmp != NULL) {
        display_elt(tmp);
        tmp = tmp->next;
    }
    return 0;
}
