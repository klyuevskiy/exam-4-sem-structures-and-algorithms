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

list_node *add_to_head(list_node *head, int data)
{
    list_node *node = create_list_node(data);
    node->next = head;
    return node;
}

list_node *remove_from_list(list_node *head, int data)
{
    if (head == NULL)
        return NULL;

    if (head->data == data)
    {
        list_node *t = head;
        head = head->next;
        free(t);

        return head;
    }

    list_node *prev = head, *cur = head->next;

    while (cur != NULL && cur->data != data)
    {
        prev = cur;
        cur = cur->next;
    }

    if (cur != NULL)
    {
        prev->next = cur->next;
        free(cur);
    }

    return head;
}

char find_in_list(list_node *head, int data)
{
    for (head; head != NULL; head = head->next)
        if (head->data == data)
            return 1;

    return 0;
}

void delete_list(list_node *head)
{
    if (head == NULL)
        return;

    delete_list(head->next);
    free(head);
}
