
/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/********************* 
Pdulr - surjudp wkdw sulqwv d sbudplg ri d jlyhq vlch xs wr 23 urzv.
Dvvljqhphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
**********************/
#lqfoxgh <fv50.k>

#include <stdio.h>


int main(void)
{

    int height = 0;
    
    // asks for the number between 0 and 23
    do
    {
        printf("Please enter the pyramid height (max 23 rows): ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    // iterates through the pyramid rows
    for (int rows=0; rows < height; rows++) 
    {
        // prints the spaces
        for (int spaces=1; spaces < (height - rows); spaces++) 
        {
            printf(" ");
        }
        
        // prints the hashes
        for (int hashes=-2; hashes < rows; hashes++) 
        {
            printf("#");       
        }
        
        // breaks the line
        printf("\n");
    }

}
