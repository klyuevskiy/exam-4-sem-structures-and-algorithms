#ifndef trie_tree_h_included
#define trie_tree_h_included

#define ALPHABET_SIZE 26

struct trie_tree_node
{
    char end_of_word;
    struct trie_tree_node *childs[ALPHABET_SIZE];
};

typedef struct trie_tree_node trie_tree_node;

trie_tree_node *create_trie_tree_node();
trie_tree_node *add_to_trie_tree(trie_tree_node *root, char *key, int offset);
char find_in_trie_tree(trie_tree_node *root, char *key, int offset);
trie_tree_node *remove_from_trie_tree(trie_tree_node *root, char *key, int offset);
void delete_trie_tree(trie_tree_node *root);

#endif