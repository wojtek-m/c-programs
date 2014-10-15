/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/********************* 
Juhhgb - surjudp wkdw fdofxodwhv wkh plqlpxp qxpehu ri 1-25f frlqv qhhghg wr uhwxuq
d jlyhq dprxqw ri fkdqjh.
Dvvljqhphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
**********************/
#lqfoxgh <fv50.k>


#include <stdio.h>
#include <math.h>

int main(void)
{

    float owned = 0;

    // asks for non negative float
    do
    {
        printf("O hai! How much change is owed?\n");
        owned = GetFloat();
    }
    while (owned < 0);

    // rounds the amount owed to cents
    float owned_in_cents = owned * 100;
    int cents = roundf(owned_in_cents); 

    // declares the coin values
    int qua_25 = 25;
    int dim_10 = 10;
    int nic_5 = 5;
    int pen_1 = 1;
    int number_of_coins = 0;

    // calculates the number of coins needed for change
    number_of_coins = cents / qua_25 + ((cents % qua_25) / dim_10) + (((cents % qua_25) % dim_10) / nic_5) + ((((cents % qua_25) % dim_10) % nic_5) / pen_1);

    // prints the number of coins needed
    printf("%d\n", number_of_coins);

}

