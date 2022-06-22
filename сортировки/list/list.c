#include "list.h"
#include <stdlib.h>

list_node *create_list_node(int data)
{
    list_node *node = (list_node *)malloc(sizeof(list_node));
    node->data = data;
    node->next = NULL;

    return node;
}

list_node *add_order_to_list(list_node *head, int data)
{
    list_node *node = create_list_node(data);

    if (head == NULL)
        return node;

    if (data <= head->data)
    {
        node->next = head;
        return node;
    }

    list_node *cur = head->next, *prev = head;

    while (cur && data > cur->data)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = node;
    node->next = cur;

    return head;
}

void delete_list(list_node *head)
{
    if (head == NULL)
        return;

    delete_list(head->next);
    free(head);
}
