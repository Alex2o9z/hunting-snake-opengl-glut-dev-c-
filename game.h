#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define ROWS 20.0
#define COLUMNS 25.0
#define COLUMNS_INFO 9.0
#define DEFAULT_SPEED 200
#define DEFAULT_LENGTH 4
#define MAX 50
#define UP 1
#define RIGHT 2
#define DOWN -1
#define LEFT -2

void initGrid(int,int);
void draw_grid();
void draw_food();
void draw_snake();
void draw_info();
void reset_snake();

#endif // GAME_H_INCLUDED
