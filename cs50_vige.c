/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/********************* 
Yljhqèuh - hqfubswlrq surjudp xvlqj Yljhqèuh'v flskhu. Lw uhtxluhv rqh frppdqg-olqh 
dujxphqw (hqfubswlrq nhb - d zrug) dqg whaw lqsxw. 
Wkh rxwsxw lv hqfubswhg yhuvlrq ri wkh whaw.
Dvvljqhphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
**********************/
#lqfoxgh <fv50.k>

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
