/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/****************************************************************************
Svhw6 - Vshoofkhfnhu - wklv iloh lpsohphqwv d glfwlrqdub'v ixqfwlrqdolwb.
Sduw ri d vshoofkhfnlqj dssolfdwlrq.
Dvvljqphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
*****************************************************************************/

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// global definitions
#define H_TABLE_SIZE ('Z' * 'Z' * 'Z' * 'Z')
#define LENGTH 45

// type definition of a node for the linked lists
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
} node;

// global variable for the head
node* head = NULL;

// global variable for the word count
int word_count = 0;

// global variable for the hashtable
node* hashtable[H_TABLE_SIZE];

/**
 * Hash function using first 3 letters of a word
 */
unsigned int hash_function(const char* key)
{      
    if (strlen(key) == 1)
    {
        int hash = toupper(key[0]);
        return hash % H_TABLE_SIZE;
    }
    else if (strlen(key) == 2)
    {
        int hash = toupper(key[0]) * toupper(key[1]);
        return hash % H_TABLE_SIZE;
    }
    else if (strlen(key) == 3)
    {
        int hash = toupper(key[0]) * toupper(key[1]) * toupper(key[2]);
        return hash % H_TABLE_SIZE;
    }
    else
    {
        int hash = toupper(key[0]) * toupper(key[1]) * toupper(key[2]) * toupper(key[0]);
        return hash % H_TABLE_SIZE;
    }
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{     
    
    // sets the tracker node to the start of a right list in the hashtable
    node* tracker = NULL;
    tracker = hashtable[hash_function(word)];
    
    // allocates memory for the word compare variables
    char* word1 = malloc(sizeof(char)*(LENGTH + 1));  
    char* word2 = malloc(sizeof(char)*(LENGTH + 1));
    
    while (tracker != NULL)
    {             
       word1 = tracker->word;
       
       // creates a lowercase copy of word char by char
       for (int i = 0; i < strlen(word) + 1; i++)
       {        
            
            // if the char is apostrophe, copy it
            if (word[i] == 39 || word[i] == 44)
            {
                word2[i] = word[i];
            }
            // else, copy lower case letter
            else
            {
                word2[i] = tolower(word[i]);
            }
               
       }
       
       // if there is no word in the node   
       if (word1 == NULL)
       {                 
            return false;
            free(word1);
            free(word2);
            break;
       }
       // if spellchecked word is found in the dictionary
       else if (strcmp(word1, word2) == 0)
       {          
            
            return true;
            free(word1);
            free(word2);
            break;
       }
       else
       {          
            // if there is no more words in the linked list
            if (tracker->next == NULL)
            {
                return false;
                free(word1);
                free(word2);
                break;
            }
            // move to the next node of the list
            else
            {
                tracker = tracker->next;
            }
       }
    }
    free(word1);
    free(word2);
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
   
    // opens dictionary file
    FILE* dict = fopen(dictionary, "r");
        
    // loops over words in the dictionary  
    for (int c = fgetc(dict); c != EOF; c = fgetc(dict))
    {                   
        // go back to the start of the file
        ungetc(c, dict);
        
        // allocate new node and check if it was created
        node* new_node = malloc(sizeof(node));
        
        // check for memory error
        if (new_node == NULL)
        {
            printf("Out of heap memory!\n");
            return false;
        }
    
        // sets buffer
        char* word_buff = malloc(sizeof(char)*(LENGTH+1));
    
        // reads the word from a file
        int word_read = fscanf(dict, "%s", word_buff);
        
        // checks if at least one character was read
        if (word_read < 1)
        {
            free(word_buff);
            free(new_node);
            continue;
        }
        else
        {
            // iterate char for char to copy word_buff into the new_node
            for (int i = 0; i < strlen(word_buff) + 1; i++)
            {
                new_node->word[i] = word_buff[i];
            }
           
            // node insertion at the start of the list
            new_node->next = hashtable[hash_function(word_buff)];
            hashtable[hash_function(word_buff)] = new_node;
        
            // increments the word count
            word_count++;
            
            //free word buff memory
            free(word_buff);
                    
        }
    }
    
    // close dictionary file
    fclose(dict);
      
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (load) { return word_count; } else { return 0; };
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // sets the nodes for traversing linked lists
    node* tracker = NULL;
    node* temp = NULL;
          
    // iterates through the hashtable
    for (int i = 0; i < H_TABLE_SIZE; i++)
    {
        
        tracker = hashtable[i];
        
        // iterates over the nodes of the linked list and frees them
        while (tracker != NULL)
        {  
            temp = tracker;            
            tracker = tracker->next;
            free(temp);

        }
        hashtable[i] = NULL;
    } 
    return true;
} 
