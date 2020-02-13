/*Daniel Chai, CSE 374, May 11th, 2017
  Assignment 5 - Trie 
 */
#include <stdio.h>
#include <stdlib.h>  // malloc
#include <string.h>

#include "trie.h"

#define NUMBER_OF_CHARACTERS 128

struct TrieNode {
  TrieNode* childNode[NUMBER_OF_CHARACTERS];
  int isWord;  // If it is a word it will be 1, 0 if it is not
  char* nodeWord;
};

// Does not accept anything as a parameter
// Creates TrieNode* that has empty childNodes
// Returns a TrieNode pointer
TrieNode* makeNode() {
    TrieNode* temp;
    temp = (TrieNode*)malloc(sizeof(TrieNode));
    if (temp) {
      for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
        temp->childNode[i]= NULL;
      }
      temp->isWord = 0;
      temp->nodeWord = NULL;
    } else {
      fprintf(stderr, "Malloc failed, abort\n");
      exit(1);
    }
    return temp;
}

// Accepts TrieNode* and a char* as parameters
// Inserts the word into the Trie
// Returns nothing
void insert(TrieNode* root, char* word) {
  int length = strlen(word);
  TrieNode* pointer = root;  // pointer that will look for the end
  for (int i = 0; i < length - 1; i++) {  // -1 for newline
    int ascii = (int)word[i];  // ascii code for the letter
    if (pointer->childNode[ascii] == NULL) {
      TrieNode* temp = makeNode();
      pointer->childNode[ascii] = temp;
    }
    pointer = pointer->childNode[ascii];
  }
  if (pointer) {
    pointer->isWord = 1;  // This is a word
    pointer->nodeWord = word;  // Set the word
  }
}

// Takes a TrieNode* as a parameter
// Traverses through the Trie with post-order traversal
// Returns nothing
void postOrder(TrieNode* root) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
    postOrder(root->childNode[i]);
  }
  if (root->isWord == 1) {  // If this is a word
    printf("%s", root->nodeWord);  // print that word
  }
}

// Accepts TrieNode* and char* as parameters
// Traverses the Trie until it finds the TrieNode* with the word
// Returns nothing
void traverse(TrieNode* root, char* word) {
  int length = strlen(word);
  TrieNode* pointer = root;
  for (int i = 0; i < length - 1; i++) {
    int ascii = (int)word[i];
    if (pointer->childNode) {  // if child exists
      pointer = pointer->childNode[ascii];  // Go to the node of the word
    }
  }
  postOrder(pointer);
}

// Takes in a TrieNode* as a parameter
// Frees all the dynamically allotted memory
// Returns nothing
void release(TrieNode* root) {
  if (root == NULL) {
    return;
  }
  for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {  // for each child
    release(root->childNode[i]);
  }
  if (root->nodeWord != NULL) {
    free(root->nodeWord);  // Free the malloced word
  }
  free(root);
}
