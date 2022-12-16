#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include "game.h"

std::ofstream ofile;
std::ifstream ifile;
bool game_over=false;
extern int sDirection;
int score=0;
extern int SPEED;
extern int length;
char WINDOW_TITLE[50]= "HUNTING SNAKE - current score: ";

void init();
void display_callback();
void input_callback(int,int,int);
void reshape_callback(int,int);
void timer_callback(int);

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2 - 75, 20); //(glutGet(GLUT_SCREEN_HEIGHT)-480)/2
    glutInitWindowSize(950,600);
    
    // update score title
    char str_score[10];
    sprintf(str_score, "%d", score);
    strcat(WINDOW_TITLE,str_score);
    glutCreateWindow(WINDOW_TITLE);
    
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutSpecialFunc(input_callback);
    glutTimerFunc(100,timer_callback,0);
    init();
    glutMainLoop();
    
    return 0;
}

void init()
{
//    glClearColor(0.0,0.0,0.0,0.0);
	glClearColor(0.7,0.8,0.3,0.5);
    initGrid(COLUMNS,ROWS);
}

//Callbacks
void display_callback()
{
    if(game_over)
    {
        ofile.open("score.dat",std::ios::trunc);
        ofile<<score<<std::endl;
        ofile.close();
        ifile.open("score.dat",std::ios::in);
        char a[4];
        ifile>>a;
        std::cout<<a;
        char text[50]= "Oh no your snake has hit its head! \n Your score: ";
        strcat(text,a);
//        MessageBox(NULL,text,"GAME OVER !!!",0);
		//MB_ICONINFORMATION,MB_RETRYCANCEL
        switch (MessageBox(NULL,text,"GAME OVER !!!",0x00000045L)) {
        	case IDCANCEL: case IDNO: {
        		//exit game 
				exit(0);
				break;
			}
			case IDRETRY: {
        		//play again 
				score = 0;
				reset_snake();
				game_over=false;
				break;
			}
		}
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    draw_grid();
    draw_food();
    draw_snake();
    draw_info();
    glutSwapBuffers();
}
void reshape_callback(int w, int h)
{
    glViewport(0,0,(GLfloat)w,GLfloat(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS+COLUMNS_INFO,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(SPEED,timer_callback,0);
}
void input_callback(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(sDirection!=DOWN)
            sDirection=UP;
        break;
    case GLUT_KEY_DOWN:
        if(sDirection!=UP)
            sDirection=DOWN;
        break;
    case GLUT_KEY_RIGHT:
        if(sDirection!=LEFT)
            sDirection=RIGHT;
        break;
    case GLUT_KEY_LEFT:
        if(sDirection!=RIGHT)
            sDirection=LEFT;
        break;
    }
}
