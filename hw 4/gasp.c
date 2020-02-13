/* Daniel Chai, CSE 374, April 27th, 2017
 * Assignment 4 
 */

#include<stdio.h>
#include<stdlib.h>  // used for files
#include<string.h>  // used for strings
#include<ctype.h>  // tolower

#define MAX_CHAR_IN_LINE 500  // Maximum number of characters in a line
#define LENGTH_OF_PATTERN 100  // Maximum length of the pattern to match

/* Parameter: takes in two char*
 * Turns the second char* into lower case
 */
void toLowerCase(char* string, char* lower_case) {
  int i = 0;
  for ( ; i < strlen(string); i++) {
    lower_case[i] = tolower(string[i]);
  }
  lower_case[i] = '\0';
}

/* Parameter: takes in two char*, and two ints
 * Goes through one file and checks each line for the matching pattern
 * If file does not exist, it exits.
 */
void process(char* string, char* file_name, int i, int n) {
  FILE *file = fopen(file_name, "r");  // initializing the file
  if (file == NULL) {
    fprintf(stderr, "Error: the file \"%s\" does not exist.\n", file_name);
    exit(1);
  } else {
    char line[MAX_CHAR_IN_LINE];  // initializing space for next line
    int line_number = 1;  // counter for line number
    char string_lower[LENGTH_OF_PATTERN];
    toLowerCase(string, string_lower);
    while (fgets(line, MAX_CHAR_IN_LINE, file) != NULL) {  // Get one line
      int print = 0;  // determines whether to print this line or not
      if (i == 1) {  // if case insensitive
        char line_lower[MAX_CHAR_IN_LINE];
        toLowerCase(line, line_lower);
        if (strstr(line_lower, string_lower) != NULL) {
          print = 1;
        }
      } else {  // if case sensitive
        if (strstr(line, string) != NULL) {
          print = 1;
        }
      }
      if (print == 1) {
        if (n == 1) {  // if line number flag has been given
          printf("Line %d ", line_number);
        }
        printf("File:%s   ", file_name);
        printf("%s", line);
      }
      line_number += 1;
    }
  }
}

/* Sends the information received from the terminal to another method
 * Exits when length of pattern is too long.
 * Exits when there are too few arguments.
 */
int main(int argc, char* argv[]) {
  int i_option = 0;  // determines whether -i flag has been entered
  int n_option = 0;  // determines whether -n flag has been entered

  if (argc > 2) {
    for (int i = 1; i < 3; i++) {
      char* temp = argv[i];
      if (strcmp(temp, "-i") == 0) {
        i_option = 1;
      }
      if (strcmp(temp, "-n") == 0) {
        n_option = 1;
      }
    }
    int arg = 1 + i_option + n_option;
    if (argc < arg + 2) {  // when arguments don't include string and file name
      fprintf(stderr, "Error: Not enough arguments.\n");
      exit(1);
    }
    char* string = argv[arg];  // Pattern to match
    if (strlen(string) > LENGTH_OF_PATTERN) {
      fprintf(stderr, "Error: Pattern too long.\n");
      exit(1);
    }
    arg += 1;
    for (; arg < argc; arg++) {
      char* file_name = argv[arg];  // file name given by the stdin
      process(string, file_name, i_option, n_option);
    }
  } else {
    fprintf(stderr, "Error: not enough arguments.\n");
    exit(1);
  }
}
