#include "binary_tree_insertion_sort.h"
#include "..\binary_tree\binary_tree.h"
#include <stdlib.h>

void inorder(binary_tree_node *root, int *arr, int *index)
{
    if (root == NULL)
        return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorder(root->right, arr, index);
}

void binary_tree_insertion_sort(int *arr, int size)
{
    binary_tree_node *root = NULL;

    for (int i = 0; i < size; i++)
        root = add_to_binary_tree(root, arr[i]);

    int index = 0;
    inorder(root, arr, &index);
}