/*********************** 
The below information was coded with Caesar Cipher to avoid it being searchable in Google.
It can be deciphered using http://www.braingle.com/brainteasers/codes/caesar.php 
with a letter shift 3.
***********************/

/****************************************************************************
Svhw4 - Euhdnrxw jdph
Dvvljqphqw iru wkh FV50a frxuvh riihuhg rq hgA eb Kduydug Xqlyhuvlwb.
kwwsv://zzz.hga.ruj/frxuvh/kduyduga/kduyduga-fv50a-lqwurgxfwlrq-frpsxwhu-1022
*****************************************************************************/


// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

// x coordinate of the ball
#define BALL_X ((WIDTH / 2) - RADIUS)

// y coordinate of the ball
#define BALL_Y ((HEIGHT / 2) - RADIUS)

// paddle width
#define PADDLE_W 75

// paddle height
#define PADDLE_H 10

// x coordinate of the paddle
#define PADDLE_X ((WIDTH / 2) - (PADDLE_W / 2)) 

// y coordinate of the paddle
#define PADDLE_Y ((HEIGHT / 10) * 9)

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GRect initWalls(GWindow window);
GLabel initScoreboard(GWindow window);
GLabel initInfo(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);
    
    // instantiate info
    GLabel info = initInfo(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
       
    // sets ball speed
    double velocity_x = 1.75 * drand48();
    double velocity_y = 1.45;
    
    // waits for click before start
    waitForClick();
    
    // removes the intro label
    removeGWindow(window, info);
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        
        // allows moving the paddle with mouse 
        GEvent event = getNextEvent(MOUSE_EVENT);
        if (event != NULL)
        {
            if (getEventType(event) == MOUSE_MOVED)
            {
                double x = getX(event);
                setLocation(paddle, x, (HEIGHT / 10) * 9);
            }
        }
        
        
        // moves the ball and bounces back from walls
        move(ball, velocity_x, velocity_y);
        
            if (getX(ball) + getWidth(ball) >= getWidth(window))
            {
               // bounce back from the right of the window
               velocity_x = -velocity_x;
            }
            else if (getX(ball) <= 0)
            {
                // bounce back from the left of the window
                velocity_x = -velocity_x;
            }
            else if (getY(ball) < 1)
            {
                //bounce back from the top of the window
                velocity_y = -velocity_y;
            }
            else if (getY(ball) + getHeight(ball) > getHeight(window))
            {
                //loosing one try when ball hits the bottom of the window
                lives -= 1;
                setLocation(ball, BALL_X, BALL_Y);
                setLocation(paddle, PADDLE_X, PADDLE_Y);
                
                if (lives > 0)
                {
                    // displays modified info label
                    char* lost_life = "Ups... Maybe you will do better next time!";
                    setLabel(info, lost_life);
                    setLocation(info, 50, 450);
                    add(window, info);
                    waitForClick();
                    removeGWindow(window, info);
                    velocity_x = 1.50 * drand48();
                    move(ball, velocity_x, velocity_y);
                }
                else
                {
                    // displays 'Game Over' label when no more lives
                    removeGWindow(window, ball);
                    removeGWindow(window, paddle);
                    char* game_over = "GAME OVER";
                    setLocation(label, 85, HEIGHT / 2);
                    setLabel(label, game_over);
                }
            }
                
            pause(2);   
        
        // Collision detection
        GObject object = detectCollision(window, ball);
        
        // if no collision, continues
        if (object == NULL)
        {
            continue;
        }
        // if object is a paddle bounces ball back
        else if (object == paddle)
        {
            if (getY(ball) + getHeight(ball) - 3 > getY(paddle))
            {
                velocity_x = -velocity_x;
            }
            else
            {
                velocity_y = -velocity_y;
            }
        }
        // if object is a label, ignores it and continues
        else if (strcmp(getType(object), "GLabel") == 0)
        {
            continue;
        }
        // if object is a brick, bounce back and removes the brick
        else if (strcmp(getType(object), "GRect") == 0)
        {
            points += 1;
            bricks -= 1;
            updateScoreboard(window, label, points);
            velocity_y = -velocity_y;
            removeGWindow(window, object);
            
            // checks for the win and displays win label
            if (lives > 0 && bricks < 1)
            {     
                char* winning = "You have won, congratulations!";
                setLabel(info, winning);
                setLocation(info, 75, 450);
                add(window, info);
                waitForClick();
                closeGWindow(window);
                return 0;
            }  
        }
    } 

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // Initialize array of the bricks (rows x columns)
    GRect bricks_arr[5][10];
    
    // Sets the width, height and spacing of the bricks
    int rect_width = (0.9 * WIDTH) / 10; 
    int rect_height = 20;
    int side_spacing = (WIDTH - (rect_width * 10)) / 10;
    int top_spacing = HEIGHT / 125;
    
    // Loop generating the bricks
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {    
        GRect rect = newGRect((side_spacing * (j + 1)) + (rect_width * j), (top_spacing * (i + 1)) + (rect_height * i), rect_width, rect_height);
        setFilled(rect, true);
            
        // Sets the colour based on the row number
        if (i == 0) 
        {
           setColor(rect, "RED");
        }
        else if (i == 1)
        {
           setColor(rect, "ORANGE");
        }
        else if (i == 2)
        {
           setColor(rect, "YELLOW");
        }
        else if (i == 3)
        {
           setColor(rect, "GREEN");
        }
        else
        {
           setColor(rect, "LIGHT_GRAY");
        }
            
        // Adds the brick to the the window
        bricks_arr[i][j] = rect;
        add(window, bricks_arr[i][j]);
        }          
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    GOval ball = newGOval(BALL_X, BALL_Y, (2 * RADIUS), (2 * RADIUS));
    setFilled(ball, true);
    setColor(ball, "BLACK");
    add(window, ball);
    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // specifies the paddle parameters
    GRect paddle = newGRect(PADDLE_X, PADDLE_Y, PADDLE_W, PADDLE_H);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    
    add(window, paddle);
    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{  
    // specifies the label
    GLabel label = newGLabel("Score");
    setFont(label, "Arial-36");
    setColor(label, "GRAY");
    
    // sets location of the label
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    
    add(window, label);
    return label;
}

/**
 * Instantiates, configures, and returns info label.
 */
GLabel initInfo(GWindow window)
{
    // specifies the label
    GLabel info = newGLabel("You have 3 tries, good luck! \n (please click to start)");
    setFont(info, "Arial-16");
    setColor(info, "GRAY");
    
    // sets location and adds the label to the window
    setLocation(info, 5, 450); 
    add(window, info);
    
    return info;
}


/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
