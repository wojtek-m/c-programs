/********************* 
Vigenère - encryption program using Vigenère’s cipher. It requires one command-line 
argument (encryption key - a word) and text input. 
The output is encrypted version of the text.
Assignement for the CS50x course offered on edX by Harvard University.
https://www.edx.org/course/harvardx/harvardx-cs50x-introduction-computer-1022
**********************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//defines constants that allow to switch between ASCII and alphabetical index of characters
#define asci_conv_lower 97
#define asci_conv_upper 65

int main(int argc, string argv[])
{
    
    // checks if the user enters an argument 
    if (argc <= 1)
    {
        printf("An argument (encryption key) is required to run this program\n");
        return 1;
    }
    // checks if the user enters only one argument
    else if (argc > 2)
    {
        printf("Only one argument is accepted\n");
        return 1;
    }
    // checks if the user entered a word and did not use any non-letter characters
    else
    {
        string encrypt_key = argv[1];
        for (int i=0, key_length = strlen(encrypt_key); i < key_length; i++)
        {
            
            if (isalpha(encrypt_key[i]))
            {
                continue;
            }
            else
            {
                printf("Your keyword has to be a word. Non English letters are not permitted\n");
                return 1;
                break;
            }
        }

    }
   
    //asks for the text to encode
    //printf("Please enter the text you want to encrypt: \n");
    string text_raw = GetString();
        
    for (int i=0, string_length = strlen(text_raw), non_letter_chars = 0; i < string_length; i++)
    {
        string encrypt_key = argv[1];
        int key_idx = i - non_letter_chars; // key_idx allows skipping non letter characters from the key letter index when encrypting
        int key_len = strlen(encrypt_key);
              
        // *** encrypts UPPERCASE characters in the text ***
        if (isupper(text_raw[i]))
        {
            // encrypts using uppercase key characters 
            if (isupper(encrypt_key[key_idx % key_len]))
            {
                int crypto_upper = (((((int) text_raw[i] - asci_conv_upper) + (encrypt_key[key_idx % key_len] - asci_conv_upper)) % 26) + asci_conv_upper);
                printf("%c", (char) crypto_upper);
            }
            // encrypts using lowercase key characters  
            else
            {
                int crypto_upper = (((((int) text_raw[i] - asci_conv_upper) + (encrypt_key[key_idx % key_len] - asci_conv_lower)) % 26) + asci_conv_upper);
                printf("%c", (char) crypto_upper);
            }
        }
        // *** encrypts LOWERCASE characters in the text ***
        else if (islower(text_raw[i]))
        {
            
            // encrypts using uppercase key characters 
            if (isupper(encrypt_key[key_idx % key_len]))
            {
                int crypto_lower = (((((int) text_raw[i] - asci_conv_lower) + (encrypt_key[key_idx % key_len] - asci_conv_upper)) % 26) + asci_conv_lower);
                printf("%c", (char) crypto_lower);
            }
            // encrypts using lowercase key characters 
            else
            {
                int crypto_lower = (((((int) text_raw[i] - asci_conv_lower) + (encrypt_key[key_idx % key_len] - asci_conv_lower)) % 26) + asci_conv_lower);
                printf("%c", (char) crypto_lower);
            }  

        }
        // *** prints all other characters unchanged and increments their counter ***
        else
        {
            printf("%c", text_raw[i]);
            non_letter_chars ++;
        }
            
    }
    printf("\n");

    return 0;
}
