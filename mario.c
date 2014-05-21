/********************* 
Mario - program that prints a pyramid of a given size up to 23 rows.
Assignement for the CS50x course offered on edX by Harvard University.
https://www.edx.org/course/harvardx/harvardx-cs50x-introduction-computer-1022
**********************/


#include <stdio.h>
#include <cs50.h>

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
