
/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/********************* 
Fdhvdu - hqfubswlrq surjudp xvlqj Fdhvdu'v flskhu. Lw uhtxluhv rqh frppdqg-olqh 
dujxphqw (hqfubswlrq nhb - d srvlwlyh qxpehu) dqg whaw lqsxw. 
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
    // checks if the user enters numerical argument
    else if (atoi(argv[1]) == 0)
    {
        printf("Please enter a positive number as your argument\n");
        return 1;
    }
    else
    {
        //converts user argument into an integer
        int key = atoi(argv[1]);
        
        //asks for the text to encode
        //printf("Please enter the text you want to encrypt: \n");
        string text_raw = GetString(); 
        
        for (int i=0, string_length = strlen(text_raw); i < string_length; i++)
        {

            if (isupper(text_raw[i]))
            {
                //encodes and prints uppercase characters
                int crypto_upper = ((((int) text_raw[i] - asci_conv_upper) + key) % 26) + asci_conv_upper;
                printf("%c", (char) crypto_upper);
            }
            else if (islower(text_raw[i]))
            {
                //encodes and prints lowercase characters
                int crypto_lower = ((((int) text_raw[i] - asci_conv_lower) + key) % 26) + asci_conv_lower;
                printf("%c", (char) crypto_lower);
            }
            else
            {
                //prints all other characters unchanged
                printf("%c", text_raw[i]);
            }
            
        }
        printf("\n");
    }
    return 0;
}
