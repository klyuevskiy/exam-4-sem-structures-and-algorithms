#include "binary_tree.h"
#include <stdlib.h>

binary_tree_node *create_binary_tree_node(int data)
{
    binary_tree_node *node =
        (binary_tree_node *)malloc(sizeof(binary_tree_node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

binary_tree_node *add_to_binary_tree(binary_tree_node *root, int data)
{
    if (root == NULL)
        return create_binary_tree_node(data);

    if (data < root->data)
        root->left = add_to_binary_tree(root->left, data);
    else
        root->right = add_to_binary_tree(root->right, data);

    return root;
}

void delete_binary_tree(binary_tree_node *root)
{
    if (root == NULL)
        return;

    delete_binary_tree(root->left);
    delete_binary_tree(root->right);

    free(root);
}