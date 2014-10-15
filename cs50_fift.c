
/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/********************* 
Ixqfwlrqv dgghg wr d 'Iliwhhq' jdph lpsohphqwdwlrq.
Dvvljqhphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
**********************/
#lqfoxgh <fv50.k>


#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
//void clear(void);
//void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
//void save(void);
int legal_move(int empty_i, int empty_j, int move_i, int move_j, int moved);

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    int max_num = d*d - 1;
        
    // Generates the list of numbers for the game
    int board_nums[(d*d)-1];
    for (int i = 0; i < max_num; i++)
    {
        board_nums[i] = max_num - i;
    }
    
    // Fills the board with the numbers from the list
    int num = 0;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = board_nums[num];
            num++;
        }
    }
    
    // Sets the empty field to 777
    board[d-1][d-1] = 777;

    // Swaps the 1 and 2 fields if the board size is even
    if (d % 2 == 0)
    {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
}

/**
 * Prints the board in its current state.
 */

void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {  
            // If the number is empty block (777) X is printed.  
            if (board[i][j] == 777)
            {
                if (d > 3)
                {
                    printf("  X"); 
                }
                else
                {
                    printf(" X"); 
                }             
            }
            // If the number is lower than 10 it is printed with a space in front of it.
            else if (board[i][j] < 10)
            {
                printf(" %2d ", board[i][j]); 
            }
                   
            else
            {
                printf(" %d ", board[i][j]); 
            }
            
        }
        printf("\n");
    }
    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // Declaring variables tracking the positions for the move and empty blocks
    int empty_i = 1000, empty_j = 1000;
    int move_i = 0, move_j = 0;
    int on_board = 0;

    // Looks for the position of the block player wants to move
    for (int i = 0; i < d; i++)
    {
        if (on_board == 1)
            {
                break;
            }
        for (int j = 0; j < d; j++)
        {
            
            if (tile == board[i][j])
            {
                // If the number player wants to move is on the boards, the tracking variables are set to it's position
                move_i = i;
                move_j = j;
                on_board = 1;
                break;
            }      
        }      
    }
    
    // Checks if the position of empty block has been initialized and if not looks for it
    if (empty_i == 1000 || empty_j == 1000)
    {
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if (board[i][j] == 777)
                {
                    empty_i = i;
                    empty_j = j;
                }
            }
        }
    }
    
    int moved = 0;
    
    // Checks if the move is legal and if so, makes the move
    if ((move_i + 1 == empty_i) && (move_j == empty_j))
    {
        legal_move(empty_i, empty_j, move_i, move_j, moved);
        moved = 1;
    }
    else if ((move_i - 1 == empty_i) && (move_j == empty_j))
    {
        legal_move(empty_i, empty_j, move_i, move_j, moved);
        moved = 1;
    }
    else if ((move_i == empty_i) && (move_j + 1 == empty_j))
    {
        legal_move(empty_i, empty_j, move_i, move_j, moved);
        moved = 1;
    }
    else if ((move_i == empty_i) && (move_j - 1 == empty_j))
    {
        legal_move(empty_i, empty_j, move_i, move_j, moved);
        moved = 1;
    }
    
    if (moved != 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool won(void)
{
    // Loops through the board and check if the configuration is winning. If not, sets var 'winning' to 1.
    int winning = 0;
    for (int i = 0; i < d; i++)
    { 
        for (int j = 0; j < d; j++)
        {   
            // Skips the check on the last element of the board
            if (i == d-1 && j == d-1)
            {
                break;
            } 
            // If the element is last in row it is compared to the first in the next row
            else if (j == d-1)
            {
                if (board[i][j] > board[i+1][0])
                {
                    winning = 1;
                    break;
                }
            }
            // Else it compares element to the next one in row
            else if (board[i][j] > board[i][j+1])
            {
                winning = 1;
                break;
            }
        }
    }
    
    // Checks the value of var 'winning' and return result
    if (winning == 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

/** 
Function that implements a players move
*/
int legal_move(int empty_i, int empty_j, int move_i, int move_j, int moved)
{
    board[empty_i][empty_j] = board[move_i][move_j];
    board[move_i][move_j] = 777;
    empty_i = move_i;
    empty_j = move_j;
    return 1;
}
