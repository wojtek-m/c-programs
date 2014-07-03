/********************* 
Greedy - program that calculates the minimum number of 1-25c coins needed to return
a given amount of change.
Assignement for the CS50x course offered on edX by Harvard University.
https://www.edx.org/course/harvardx/harvardx-cs50x-introduction-computer-1022
**********************/

#include <stdio.h>
#include <cs50.h>
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

