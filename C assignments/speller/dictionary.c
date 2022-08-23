// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"
int dict_size=0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash word to obtain hash value
    int hash_value = hash(word);
    // Access linked list at that index in hash table
    node *n = table[hash_value];
    // Traverse linked list, looking for word (strcasecomp)
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Function should take a string and return an index
    // This hash function adds the ASCII values of all characters in     the word together
    long sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}
/*// Hashes word to a number
unsigned int hash(const char *word)
{
    char first_letter;
    // TODO: Improve this hash function
    if (word == NULL) {
        return 1;
    } else {
        first_letter = tolower(word[0]);
    }
    if (96 < (int)first_letter && (int)first_letter < 123) {
        return (int)first_letter - 97;
    } else {
        return 1;
    }
}*/

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *f = fopen(dictionary, "r");
    if (dictionary == NULL) {
        return false;
    }
    char next_word[LENGTH+1];

    while(fscanf(f, "%s", next_word) != EOF) {
        if (f == NULL) {
            return false;
        }

        node *new_word = malloc(sizeof(node));
        strcpy(new_word->word, next_word);

        int hash_value = hash(next_word);
        new_word->next = table[hash_value];
        table[hash_value] = new_word;

        dict_size++;

        }
        fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {

        node *cursor = table[i];

        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
