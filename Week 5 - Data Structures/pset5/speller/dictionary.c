// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

unsigned int hash(const char *word);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 100;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hashing the word
    int hnumber = hash(word);
    
    //If the table's index is empty, means word is not in dict
    if (table[hnumber] == NULL)
    {
        return false;
    }
    
    else
    {
        node *cursor = table[hnumber];
        
        //Comparing the word cursor is currently looking at with the word needed to be found (case insensitive)
        while (cursor != NULL)
        {
            if (strcasecmp(cursor->word, word) == 0)
            {
                return true;
            }
            
            cursor = cursor->next;
        }
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]); 
    }
    
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char WORD[LENGTH + 1];
    
    //Opening the dictionary file
    FILE *file = fopen(dictionary, "r");
    
    if (file == NULL)
    {
        return false;
    }
    
    //Reading words from the dict file and storing them in a temporary node
    while (fscanf(file, "%s", WORD) != EOF)
    {
        node *temp_node = malloc(sizeof(node));
        
        if (temp_node == NULL)
        {
            return false;
        }
        
        strcpy(temp_node->word, WORD);
        temp_node->next = NULL;
    
    
        //Hashing the word 
        int hnumber = hash(temp_node->word);
    
        //If the node is empty, store the word
        if (table[hnumber] == NULL)
        {
            table[hnumber] = temp_node;
        }
    
        else
        {   
            //Find the closest empty node to store the word
            temp_node->next = table[hnumber];
            table[hnumber] = temp_node;
        }
    
    }
    fclose(file);
    return true;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int wordctr = 0;
    
    //traverses the hash table, counting each word
    for (int i = 0; i < N; i++)
    {
        node *x = table[i];
        if (x != NULL)
        {
            x = x->next;
            wordctr++;
        }
    }
    
    if (wordctr > 0)
    {
        return wordctr;
    }
    
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *item = table[i];
        node *cursor = item;
        node *temp = cursor;
        
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
