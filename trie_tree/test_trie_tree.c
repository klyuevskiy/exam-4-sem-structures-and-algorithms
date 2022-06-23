#include <stdio.h>
#include "trie_tree.h"

int main()
{
    trie_tree_node *root = NULL;

    root = add_to_trie_tree(root, "aaa", 0);
    root = add_to_trie_tree(root, "ab", 0);
    root = add_to_trie_tree(root, "abc", 0);

    root = remove_from_trie_tree(root, "abc", 0);
    root = remove_from_trie_tree(root, "ab", 0);
    root = remove_from_trie_tree(root, "aaa", 0);

    root = add_to_trie_tree(root, "av", 1);

    printf("%d %d %d", find_in_trie_tree(root, "av", 0),
           find_in_trie_tree(root, "v", 0), find_in_trie_tree(root, "abd", 0));

    delete_trie_tree(root);

    return 0;
}