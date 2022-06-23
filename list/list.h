#ifndef list_h_included
#define list_h_included

struct list_node
{
    int data;
    struct list_node *next;
};

typedef struct list_node list_node;

list_node *create_list_node(int data);
list_node *add_order_to_list(list_node *head, int data);
list_node *add_to_head(list_node *head, int data);
list_node *remove_from_list(list_node *head, int data);
char find_in_list(list_node *head, int data);
void delete_list(list_node *head);

#endif