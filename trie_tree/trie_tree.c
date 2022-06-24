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

trie_tree_node *iterative_add_to_trie_tree(trie_tree_node *root, char *key, int offset)
{
    if (root == NULL)
        root = create_trie_tree_node();

    trie_tree_node *node = root;

    while (key[offset] != '\0')
    {
        int index = tolower(key[offset++]) - 'a';

        if (!node->childs[index])
            node->childs[index] = create_trie_tree_node();

        node = node->childs[index];
    }

    node->end_of_word = 1;

    return root;
}

char iterative_find_in_trie_tree(trie_tree_node *root, char *key, int offset)
{
    while (key[offset] != '\0' && root != NULL)
        root = root->childs[tolower(key[offset++]) - 'a'];

    if (root == NULL)
        return 0;

    return root->end_of_word;
}

struct stack_node
{
    trie_tree_node *node, *parent;
    int node_index_in_parent;
    struct stack_node *next;
};

typedef struct stack_node stack_node;

stack_node *add_stack(stack_node *head, trie_tree_node *node, trie_tree_node *parent, int node_index_in_parent)
{
    stack_node *snode = (stack_node *)malloc(sizeof(stack_node));

    snode->node = node;
    snode->next = head;
    snode->parent = parent;
    snode->node_index_in_parent = node_index_in_parent;

    return snode;
}

stack_node *pop_stack(stack_node *head)
{
    stack_node *t = head;
    head = head->next;
    free(t);

    return head;
}

trie_tree_node *iterative_remove_from_trie_tree(trie_tree_node *root, char *key, int offset)
{
    if (root == NULL)
        return NULL;

    stack_node *s = add_stack(NULL, root, NULL, 0);
    trie_tree_node *node = root;

    while (key[offset] != '\0' && node != NULL)
    {
        int index = tolower(key[offset++]) - 'a';
        s = add_stack(s, node->childs[index], node, index);
        node = node->childs[index];
    }

    if (node == NULL)
    {
        while (s)
            s = pop_stack(s);
    }
    else
    {
        node->end_of_word = 0;
        while (s)
        {
            if (!s->node->end_of_word && s->parent && all_empty_childs(s->node))
            {
                s->parent->childs[s->node_index_in_parent] = NULL;
                free(s->node);
            }

            s = pop_stack(s);
        }

        if (all_empty_childs(root))
        {
            free(root);
            root = NULL;
        }
    }

    return root;
}