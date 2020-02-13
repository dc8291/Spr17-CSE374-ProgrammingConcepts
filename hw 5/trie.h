/*Daniel Chai, CSE 374, May 11th, 2017
  Assignment 5 - Trie
*/

#ifndef TRIE_H
#define TRIE_H

struct TrieNode;
typedef struct TrieNode TrieNode;

// Make an empty TrieNode
TrieNode* makeNode();

// Inserting a word
void insert(TrieNode* root, char* word);

// Traversing the tree
void traverse(TrieNode* root, char* word);

// Post Order printing
void postOrder(TrieNode* root);

// free all memory this uses
void release(TrieNode* root);

#endif  // TRIE_H

