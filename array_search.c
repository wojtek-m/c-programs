/********************* 
Program that sorts a randomly generated array of numbers and search if it includes
a given number.
Part of an assignement for the CS50x course offered on edX by Harvard University.
https://www.edx.org/course/harvardx/harvardx-cs50x-introduction-computer-1022
**********************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    // Array generator
    printf("Please provide required length of the array: \n");
    int n = GetInt();
    int values[n];
    for (int i = 0; i < n; i++)
    {
        int element = rand() % 5000;
        values[i] = element;
        printf("Values[%i] = %i\n", i, element);
    }

    // Bubble sort algorithm
    int temp = 0;
    int swap = 0;
    do 
    {
        swap = 0;
        for (int num=0; num <= (n - 1); num++)    
        {
            if (values[num] > values[num + 1])
                {
                    temp = values[num];
                    values[num] = values[num + 1];
                    values[num + 1] = temp;
                    swap = 1;
                } 
        }
    }
    while (swap == 1);
    
    for (int i=1; i < n + 1; i++)
    {
        printf("Sorted Values[%i] = %i\n", i, values[i]);
    }
        
    // Binary search algorithm   
    int min = 0;
    int result = 0;
    int mid = (min + n) / 2;
    
    printf("Number to find: \n");
    int value = GetInt();
    
    do
    {
        if (values[mid] == value)
        {
            result = 1;
            printf("Found %i in position %i\n", value, mid);
            break;
        }
        else if (values[mid] < value)
        {
            min = mid + 1;
        }
        else 
        {
            n = mid - 1;
        }
        mid = (min + n) / 2;

    }
    while (min <= n);
    
    if (result == 1)
    {
        return true;
    }
    else
    {
        printf("Didn't find %i in the array\n", value);
        return false;    
    }      
    return 0;
}