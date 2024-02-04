/*
** EPITECH PROJECT, 2023
** organized
** File description:
** main file
** main
*/
/*
add WIRE usb0, WIRE usb1, WIRE usb2
add WIRE usb, ACTUATOR button, DEVICE recorder
add WIRE usb, ACTUATOR z, WIRE w, WIRE usb
add WIRE usb, WIRE type-c, WIRE usb, ACTUATOR button
NOTES ET OBJECTIFS :
    - combiner les tris
*/

#include "include/my.h"
#include "include/organized.h"
#include "include/shell.h"

int get_len_data(linked_list_t *data)
{
    int ans = 0;

    while (data != NULL) {
        ans++;
        data = data->next;
    }
    return ans;
}

void destroy_data(linked_list_t **data)
{
    linked_list_t *current = *data;
    linked_list_t *tmp = NULL;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->type);
        free(tmp->name);
        free(tmp);
    }
}

int main(void)
{
    linked_list_t *linked_list = NULL;
    int ans_ret = workshop_shell(&linked_list);

    destroy_data(&linked_list);
    return ans_ret;
}
