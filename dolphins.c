/********************* 
Dolphin training.
Exercise from the CS50x course offered on edX by Harvard University.
https://www.edx.org/course/harvardx/harvardx-cs50x-introduction-computer-1022
**********************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int* getAge(void);

int main(int argc, char* argv[]) {

    // checks if the user enters an argument 
    if (argc <= 1)
    {
        printf("An argument (number of dolphins) is required to run this program\n");
        return 1;
    }
    // checks if the user enters only one argument
    else if (argc > 2)
    {
        printf("Only one argument is accepted\n");
        return 1;
    }

    // converts cmd line input to an integer
    int dolphins = atoi(argv[1]);

    // ensures number of dolphins is greater than 0
    if (dolphins < 1) 
    {
        printf("Please enter a number of dolphins to train (at least one).\n");
        return 2;
    }

    // initialize a new array for dolphins ages
    int* dolphin_ages[dolphins];

    // getting dolphin ages
    for (int i = 0; i < dolphins; i++) 
    {
        dolphin_ages[i] = getAge();
    }

    // prints out oldest dolphins's age
    int oldest = 0;
    for (int i = 0; i < dolphins; i++) 
    {
        if (*dolphin_ages[i] > oldest) 
        {
            oldest = *dolphin_ages[i];
        }
    }
    printf("The oldest dophin you are training today is %i year old!\n", oldest);

}

/**
Function getting the age of a dolphin
**/
int* getAge(void) 
{
    // get an age
    int* age = malloc(sizeof(int));
    do
    {
        printf("How old is the dolphin (> 0)? ");
        *age = GetInt();
    }
    while (*age < 1);

    // return the age
    return age;
}