#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include "include/game.h"
#include "include/physics.h"
#include "include/draw.h"
#include "include/input.h"
#include "include/movement.h"

int main(int argc, char **argv) 
{
    srand(time(NULL));
    char field[FIELD_HEIGHT][FIELD_WIDTH] = {
        "######################",
	"#                    #",
	"#                    #",
	"#                    #",
	"#                    #",
	"#                    #",
	"#                    #",
	"#                    #",
	"#                    #",
	"#                    #",
        "#                    #",
	"#                    #",
	"#         *          #",
	"#       =====        #",
	"#                    #",
	"######################"
    };
    int coordsBall[2] = {12, 10};
    generateRows(FIELD_HEIGHT, FIELD_WIDTH, field);
    drawMap(FIELD_HEIGHT, FIELD_WIDTH, field, FIELD_HEIGHT);
    //clearField();
}


// realization include/draw.h
void drawMap(int h, int w, char map[h][w], int rows) 
{
    for (int i = 0; i < rows; i++)
        puts(map[i]);
}

void generateRows(int h, int w, char map[h][w]) 
{
    int random;
    // make rows with '$' symbols
    for (int i = 1; i < LIMIT; i++)
    {
        for (int j = 1; j < FIELD_WIDTH-2; j++)
            map[i][j] = '$';
    }
    // make vertical spaces between
    for (int i = 1; i < LIMIT; i += SPACE_HORIZONTAL+1)
    {
        for (int j = 1; j < FIELD_WIDTH-2; j++)
            map[i][j] = ' ';
    }
    // make ' ' symbols
    for (int i = 1; i < LIMIT; i++)
    {

        for (int j = 1; j < 6; j++) 
	{
            random = rand() % (FIELD_WIDTH-3) + 1;
            map[i][random] = ' ';
        }
    }

}

void clearField(void) 
{
    system("clear");
}
