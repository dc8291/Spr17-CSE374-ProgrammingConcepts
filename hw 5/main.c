/* Daniel Chai, CSE 374, May 11th, 2017
   Assignment 5 - Trie
*/

#include <stdio.h>
#include <stdlib.h>  // Used for files
#include <string.h>  // Used for string operations
#include "trie.h"

#define LONGEST_WORD 501  // Assumption that no word is longer than 500

// Takes in TrieNode* and FILE* as parameters
// Creates the root node
// Returns the node
TrieNode* makeRoot(TrieNode* root, FILE* file) {
  char line[LONGEST_WORD];
  while (fgets(line, LONGEST_WORD, file) != NULL) {  // Gets one line
    char* tempWord = (char*)malloc(strlen(line)+1);  // One Word
    strncpy(tempWord, line, strlen(line)+1);
    insert(root, tempWord);  // Insert it to the trie
  }
  return root;
}


// Initializes the TrieNode
// Takes in the user input
int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Not Enough Arguments");
  }
  char* file_name = argv[1];  // First argument
  FILE* file = fopen(file_name, "r");  // Opening the file
  TrieNode* root = makeNode();
  if (file == NULL) {
    fprintf(stderr, "The file could not be opened.");
    exit(1);
  } else {
    root = makeRoot(root, file);
  }
  char input[LONGEST_WORD];
  if (fgets(input, LONGEST_WORD, stdin) != NULL) {  // Get user input from
    traverse(root, input);  // Search and print the autocomplete
  }

  // free the list
  release(root);
  return 0;
}
