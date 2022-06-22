#ifndef binary_tree_h_included
#define binary_tree_h_included

struct binary_tree_node
{
    int data;
    struct binary_tree_node *left, *right;
};

typedef struct binary_tree_node binary_tree_node;

binary_tree_node *create_binary_tree_node(int data);
binary_tree_node *add_to_binary_tree(binary_tree_node *root, int data);
void delete_binary_tree(binary_tree_node *root);

#endif