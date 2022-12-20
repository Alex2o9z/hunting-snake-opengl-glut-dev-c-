#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include "game.h"
#include "displayinfo.h"

void unit(int,int);
void unit_info(int,int);
int random(int,int);

bool length_inc=false;
bool seedflag = false;
extern int score;
extern char str_score[4];
extern bool game_over;
int sDirection = RIGHT;
bool food=false;
int rows=0,columns=0;
int foodx,foody;
int posx[MAX+1]={5,4,3,2};
int posy[MAX+1]={10,10,10,10};
int length=DEFAULT_LENGTH;
int SPEED=DEFAULT_SPEED;
extern char WINDOW_TITLE[50];
int infox,infoy;

void initGrid(int x,int y)
{
    columns=x;
    rows=y;
}

void draw_grid()
{
    for(int i=0;i<columns;i++)
    {
        for(int j=0;j<rows;j++)
            {unit(i,j);}
    }
    for(int i=columns;i<columns+COLUMNS_INFO;i++)
    {
        for(int j=0;j<rows;j++)
            {unit_info(i,j);}
    }
}

void draw_snake()
{
    for(int i=length-1;i>0;i--)
    {
        posx[i]=posx[i-1];
        posy[i]=posy[i-1];
    }
    for(int i=0;i<length;i++)
    {
    	if (i == 0) {
    		switch(sDirection) {
            	case UP: {
            		posy[i]++;
					break;
				}
            	case DOWN: {
            		posy[i]--;
					break;
				}
            	case RIGHT: {
            		posx[i]++;
					break;
				}
            	case LEFT: {
            		posx[i]--;
                	break;
				}
            }
		}
		
		// Draw base snake
    	glColor3f(0.4,0.5,1.0);
        glBegin(GL_QUADS);
        	glVertex2d(posx[i],posy[i]);
			glVertex2d(posx[i]+1,posy[i]);
			glVertex2d(posx[i]+1,posy[i]+1);
			glVertex2d(posx[i],posy[i]+1);
        glEnd();
        // Draw border 
        glColor3f(0.0,0.0,0.0);
		if (posy[i] != posy[i+1] || posy[i] != posy[i-1]) {
			// line right
			if (posx[i]+1 != posx[i+1] && posx[i]+1 != posx[i-1]) {
				glBegin(GL_LINES);
					glVertex2d(posx[i]+1,posy[i]);
					glVertex2d(posx[i]+1,posy[i]+1);
        		glEnd();
			}
			// line right
			if (posx[i]-1 != posx[i+1] && posx[i]-1 != posx[i-1]) {
				glBegin(GL_LINES);
					glVertex2d(posx[i],posy[i]);
					glVertex2d(posx[i],posy[i]+1);
        		glEnd();
			}
		}
		if (posx[i] != posx[i+1] || posx[i] != posx[i-1]) {
			// line up
			if (posy[i]+1 != posy[i+1] && posy[i]+1 != posy[i-1]) {
				glBegin(GL_LINES);
					glVertex2d(posx[i],posy[i]+1);
					glVertex2d(posx[i]+1,posy[i]+1);
        		glEnd();
			}
			// line down
			if (posy[i]-1 != posy[i+1] && posy[i]-1 != posy[i-1]) {
				glBegin(GL_LINES);
					glVertex2d(posx[i],posy[i]);
					glVertex2d(posx[i]+1,posy[i]);
        		glEnd();
			}
		}
		
        // check HEAD
        if(i==0) {
            // handle hit the wall
            if(posx[i]==0||posx[i]==columns-1||posy[i]==0||posy[i]==rows-1)
                game_over=true;
            else if(posx[i]==foodx && posy[i]==foody)
            {
                food=false;
                score++;
                if(length<=MAX)
                    length_inc=true;
                if(length==MAX)
                    MessageBox(NULL,"You can still keep playing but the snake will not grow.","WIN !!!",0x00000040L);
            } // handle eat food
            
            // handle hit itself
            for(int j=1;j<length;j++)
            {
                if(posx[j]==posx[0] && posy[j]==posy[0])
                    game_over=true;
            }
            
    		// Draw eyes
    		glColor3f(1.0,1.0,1.0);
    		if (sDirection == UP || sDirection == DOWN) {
    			// White - left eye
    			glColor3f(1.0,1.0,1.0);
    			glBegin(GL_QUADS);
            		glVertex2d(posx[i]-0.2,posy[i]+0.2); glVertex2d(posx[i]+1-0.6,posy[i]+0.2);
					glVertex2d(posx[i]+1-0.6,posy[i]+1-0.2); glVertex2d(posx[i]-0.2,posy[i]+1-0.2);
        		glEnd();
        		// White - right eye
        		glColor3f(1.0,1.0,1.0);
        		glBegin(GL_QUADS);
            		glVertex2d(posx[i]+0.6,posy[i]+0.2); glVertex2d(posx[i]+1+0.2,posy[i]+0.2);
					glVertex2d(posx[i]+1+0.2,posy[i]+1-0.2); glVertex2d(posx[i]+0.6,posy[i]+1-0.2);
        		glEnd();
        		
        		glColor3f(0.0,0.0,0.0);
        		float a,b;
        		if (sDirection == UP) {
        			a = 0.2; b = -a;
				} else {
					a = 0.0; b = -0.4;
				}
        		// Black - left eye
    			glBegin(GL_QUADS);
            		glVertex2d(posx[i]-0.2+0.1,posy[i]+0.2+a); glVertex2d(posx[i]+1-0.6-0.1,posy[i]+0.2+a);
					glVertex2d(posx[i]+1-0.6-0.1,posy[i]+1+b); glVertex2d(posx[i]-0.2+0.1,posy[i]+1+b);
        		glEnd();
        		// Black - right eye
        		glBegin(GL_QUADS);
            		glVertex2d(posx[i]+0.6+0.1,posy[i]+0.2+a); glVertex2d(posx[i]+1+0.2-0.1,posy[i]+0.2+a);
					glVertex2d(posx[i]+1+0.2-0.1,posy[i]+1+b); glVertex2d(posx[i]+0.6+0.1,posy[i]+1+b);
        		glEnd();
			} else {
				// White - above eye
				glColor3f(1.0,1.0,1.0);
				glBegin(GL_QUADS);
            		glVertex2d(posx[i]+0.2,posy[i]+0.6); glVertex2d(posx[i]+1-0.2,posy[i]+0.6);
					glVertex2d(posx[i]+1-0.2,posy[i]+1+0.2); glVertex2d(posx[i]+0.2,posy[i]+1+0.2);
        		glEnd();
        		// White - under eye
        		glColor3f(1.0,1.0,1.0);
        		glBegin(GL_QUADS);
            		glVertex2d(posx[i]+0.2,posy[i]-0.2); glVertex2d(posx[i]+1-0.2,posy[i]-0.2);
					glVertex2d(posx[i]+1-0.2,posy[i]+1-0.6); glVertex2d(posx[i]+0.2,posy[i]+1-0.6);
        		glEnd();
        		
        		glColor3f(0.0,0.0,0.0);
        		float a,b;
        		if (sDirection == RIGHT) {
        			a = 0.2; b = 0.0;
				} else {
					a = 0.0; b = -0.2;
				}
        		// Black - above eye
				glBegin(GL_QUADS);
            		glVertex2d(posx[i]+0.2+a,posy[i]+0.6+0.1); glVertex2d(posx[i]+1-0.2+b,posy[i]+0.6+0.1);
					glVertex2d(posx[i]+1-0.2+b,posy[i]+1+0.2-0.1); glVertex2d(posx[i]+0.2+a,posy[i]+1+0.2-0.1);
        		glEnd();
        		// Black - under eye
        		glBegin(GL_QUADS);
            		glVertex2d(posx[i]+0.2+a,posy[i]-0.2+0.1); glVertex2d(posx[i]+1-0.2+b,posy[i]-0.2+0.1);
					glVertex2d(posx[i]+1-0.2+b,posy[i]+1-0.6-0.1); glVertex2d(posx[i]+0.2+a,posy[i]+1-0.6-0.1);
        		glEnd();
			}
        }
    }
    if(length_inc)
    {
        length++;
        length_inc=false;
        if (SPEED > 100) {
        	SPEED -= 10;
		}
		
		// update score title
    	sprintf(str_score, "%d", score);
    	char SCORE_TITLE[50] = "HUNTING SNAKE - current score: ";
    	strcat(SCORE_TITLE,str_score);
    	glutSetWindowTitle(SCORE_TITLE);
    }
}

void draw_food()
{
    if(!food)
    {
    	bool duplicate;
    	do {
    		duplicate = false;
    		foodx=random(2,columns-2);
        	foody=random(2,rows-2);
    		for(int i=0;i<length;i++) {
    			if (foodx == posx[i] && foody == posy[i]) {
    				duplicate = true;
    				break;
				}
			}
		} while (duplicate == true);
		std::cout<<foodx<<foody<<std::endl;
        food=true;
    }
    float a = 0.1, b = 0.2;
    glBegin(GL_POLYGON);
    	glColor3f(0.8,0.0,0.0);
    	glVertex2d(foodx+b,foody-a);
    	glColor3f(0.7,0.0,0.0);
		glVertex2d(foodx+1-b,foody-a);
		glColor3f(0.8,0.0,0.0);
		glVertex2d(foodx+1+a,foody+b);
		glColor3f(0.9,0.0,0.0);
		glVertex2d(foodx+1+a,foody+1-b);
		glColor3f(1.0,0.0,0.0);
		glVertex2d(foodx+1-b,foody+1+a);
		glVertex2d(foodx+b,foody+1+a);
		glVertex2d(foodx-a,foody+1-b);
		glColor3f(0.9,0.0,0.0);
    	glVertex2d(foodx-a,foody+b);
    glEnd();
    glBegin(GL_QUADS);
    	glColor3f(0.3,0.2,0.0);
        glVertex2d(foodx+0.4,foody+0.9);
        glColor3f(0.4,0.3,0.1);
		glVertex2d(foodx+1-0.4,foody+0.9);
		glColor3f(0.3,0.2,0.0);
		glVertex2d(foodx+1-0.4,foody+1+0.3);
		glColor3f(0.4,0.3,0.1);
		glVertex2d(foodx+0.4,foody+1+0.3);
    glEnd();
    glBegin(GL_QUADS);
    	glColor3f(0.3,0.6,0.2);
    	glVertex2d(foodx+0.5,foody+0.9);
    	glColor3f(0.4,0.7,0.3);
		glVertex2d(foodx+1-0.1,foody+0.9);
		glColor3f(0.3,0.6,0.2);
		glVertex2d(foodx+1,foody+1+0.2);
		glColor3f(0.4,0.7,0.3);
		glVertex2d(foodx+0.6,foody+1+0.2);
    glEnd();
}

void draw_info() {
	glLoadIdentity();
	draw_info_content(columns, rows);
}

void unit(int x,int y)
{
    glLoadIdentity();
    if(x==0||x==columns-1||y==0||y==rows-1)
    {
        glBegin(GL_QUADS);
        	glColor3f(0.9,0.4,0.0);
    		glVertex2d(x,y);
    		glColor3f(0.8,0.3,0.0);
			glVertex2d(x+1,y);
			glColor3f(0.9,0.4,0.0);
			glVertex2d(x+1,y+1);
			glColor3f(0.8,0.3,0.0);
			glVertex2d(x,y+1);
    	glEnd();
    	glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
       		glVertex2d(x,y); glVertex2d(x+1,y);
        	glVertex2d(x+1,y); glVertex2d(x+1,y+1);
        	glVertex2d(x+1,y+1); glVertex2d(x,y+1);
        	glVertex2d(x,y+1); glVertex2d(x,y);
    	glEnd();
    } else {
    	if (y%2 == 0) {
    		if (x%2 != 0) {
    			glColor3f(0.6,0.8,0.3);
    			glBegin(GL_QUADS);
    				glVertex2d(x,y);
					glVertex2d(x+1,y);
					glVertex2d(x+1,y+1);
					glVertex2d(x,y+1);
    			glEnd();
			}
		} else {
			if (x%2 == 0) {
    			glColor3f(0.6,0.8,0.3);
    			glBegin(GL_QUADS);
    				glVertex2d(x,y);
					glVertex2d(x+1,y);
					glVertex2d(x+1,y+1);
					glVertex2d(x,y+1);
    			glEnd();
			}
		}
    }
}
void unit_info(int x,int y)
{
    glLoadIdentity();
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_QUADS);
    	glVertex2d(x,y);
		glVertex2d(x+1,y);
		glVertex2d(x+1,y+1);
		glVertex2d(x,y+1);
    glEnd();

    glColor3f(0.7,0.7,0.7);
	glLineWidth(11.0);
	float z = 0.2;
  	if (x==columns) {
    	glBegin(GL_LINES);
			glVertex2d(x+z,y+1); glVertex2d(x+z,y);
   		glEnd();
	}
	if (x==columns+COLUMNS_INFO-1) {
    	glBegin(GL_LINES);
			glVertex2d(x+1-z,y); glVertex2d(x+1-z,y+1);
   		glEnd();
	}
	if (y==0) {
    	glBegin(GL_LINES);
    	    glVertex2d(x+1,y+z); glVertex2d(x,y+z);
   		glEnd();
	}
	if (y==rows-1) {
    	glBegin(GL_LINES);
    	  	glVertex2d(x+1,y+1-z); glVertex2d(x,y+1-z);
   		glEnd();
	}
	glLineWidth(1.0);
}
int random(int _min,int _max)
{
    if(!seedflag)
    {
        srand(time(NULL));
        seedflag=true;
    }
    else
        seedflag=false;
    return _min+rand()%(_max-_min);
}

void reset_snake() {
	score = 0;
	length = DEFAULT_LENGTH;
	SPEED = DEFAULT_SPEED;
	for (int i=0; i<length; i++) {
		posx[i] = length-1-i+2;
		posy[i] = 10;
	}
	sDirection = RIGHT;
	
	// update score title
    sprintf(str_score, "%d", score);
    char SCORE_TITLE[50] = "HUNTING SNAKE - current score: ";
    strcat(SCORE_TITLE,str_score);
    glutSetWindowTitle(SCORE_TITLE);
}
