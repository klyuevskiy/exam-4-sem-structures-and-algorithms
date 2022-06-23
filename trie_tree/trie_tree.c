#include "trie_tree.h"
#include <stdlib.h>
#include <ctype.h>

trie_tree_node *create_trie_tree_node()
{
    trie_tree_node *node = (trie_tree_node *)malloc(sizeof(trie_tree_node));

    node->end_of_word = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->childs[i] = NULL;
}

trie_tree_node *add_to_trie_tree(trie_tree_node *root, char *key, int offset)
{
    if (root == NULL)
        root = create_trie_tree_node();

    if (key[offset] == '\0')
        root->end_of_word = 1;
    else
    {
        int child = tolower(key[offset]) - 'a';
        root->childs[child] = add_to_trie_tree(root->childs[child], key, offset + 1);
    }

    return root;
}

char find_in_trie_tree(trie_tree_node *root, char *key, int offset)
{
    if (root == NULL)
        return 0;

    if (key[offset] == '\0')
        return root->end_of_word;

    return find_in_trie_tree(root->childs[tolower(key[offset]) - 'a'], key, offset + 1);
}

char all_empty_childs(trie_tree_node *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->childs[i] != NULL)
            return 0;

    return 1;
}

trie_tree_node *remove_from_trie_tree(trie_tree_node *root, char *key, int offset)
{
    if (root == NULL)
        return NULL;

    if (key[offset] == '\0')
        root->end_of_word = 0;
    else
    {
        int child = tolower(key[offset]) - 'a';
        root->childs[child] = remove_from_trie_tree(root->childs[child], key, offset + 1);
    }

    if (!root->end_of_word && all_empty_childs(root))
    {
        free(root);
        root = NULL;
    }

    return root;
}

void delete_trie_tree(trie_tree_node *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        delete_trie_tree(root->childs[i]);

    free(root);
}