#include <GL/glut.h>
#include "game.h"

extern int high_score;
extern int score;

int draw_text(char*, int, int, float, float);
void draw_numbers(int, int, int, float);
void draw_number(int, float, float, float);

void draw_info_content(int columns, int rows) {
	int startx = columns+1, starty = rows-2;
	// HUNTING
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
	glBegin(GL_LINES); // H
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.4+0.1); glVertex2d(startx+1-0.1,starty+0.4+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES);// U
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // N
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // T
    	glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
       	glVertex2d(startx+0.5,starty+0.1); glVertex2d(startx+0.5,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // I
       	glVertex2d(startx+0.3,starty+1-0.1); glVertex2d(startx+1-0.3,starty+1-0.1);
       	glVertex2d(startx+0.5,starty+0.1); glVertex2d(startx+0.5,starty+1-0.1);
       	glVertex2d(startx+0.3,starty+0.1); glVertex2d(startx+1-0.3,starty+0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // N
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // G
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+0.1,starty+0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.5);
        glVertex2d(startx+0.5,starty+1-0.5); glVertex2d(startx+1-0.1,starty+1-0.5);
    glEnd();
    
    starty--;
    startx = columns+1;
    
    // SNAKE
    startx++;
    glBegin(GL_LINES); // S
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+0.1,starty+0.5);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.5);
        glVertex2d(startx+0.1,starty+1-0.5); glVertex2d(startx+1-0.1,starty+1-0.5);
    glEnd();
    startx++;
    glBegin(GL_LINES); // N
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // A
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.5); glVertex2d(startx+1-0.1,starty+1-0.5);
    glEnd();
    startx++;
    glBegin(GL_LINES); // K
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+1-0.1,starty+1-0.1); glVertex2d(startx+0.1,starty+1-0.5);
        glVertex2d(startx+0.1,starty+1-0.5); glVertex2d(startx+1-0.1,starty+0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // E
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.4+0.1); glVertex2d(startx+1-0.1,starty+0.4+0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
    glEnd();
    
    // MOVE ICON
    glColor3f(0.0,0.0,0.0);
    starty -= 2;
    startx = columns+2;
    glBegin(GL_TRIANGLES); // UP
       	glVertex2d(startx+0.2,starty+0.2);
		glVertex2d(startx+1-0.2,starty+0.2);
       	glVertex2d(startx+0.5,starty+1-0.3);
    glEnd();
    glBegin(GL_LINES);
       	glVertex2d(startx,starty); glVertex2d(startx+1,starty);
        glVertex2d(startx+1,starty); glVertex2d(startx+1,starty+1);
        glVertex2d(startx+1,starty+1); glVertex2d(startx,starty+1);
        glVertex2d(startx,starty+1); glVertex2d(startx,starty);
    glEnd();
    starty--;
    startx = columns+1;
    glBegin(GL_TRIANGLES); // LEFT
       	glVertex2d(startx+0.3,starty+0.5);
		glVertex2d(startx+1-0.2,starty+0.2);
       	glVertex2d(startx+1-0.2,starty+1-0.2);
    glEnd();
    glBegin(GL_LINES);
       	glVertex2d(startx,starty); glVertex2d(startx+1,starty);
        glVertex2d(startx+1,starty); glVertex2d(startx+1,starty+1);
        glVertex2d(startx+1,starty+1); glVertex2d(startx,starty+1);
        glVertex2d(startx,starty+1); glVertex2d(startx,starty);
    glEnd();
    startx++;
    glBegin(GL_TRIANGLES); // DOWN
       	glVertex2d(startx+0.2,starty+1-0.2);
		glVertex2d(startx+0.5,starty+0.2);
       	glVertex2d(startx+1-0.2,starty+1-0.2);
    glEnd();
    glBegin(GL_LINES);
       	glVertex2d(startx,starty); glVertex2d(startx+1,starty);
        glVertex2d(startx+1,starty); glVertex2d(startx+1,starty+1);
        glVertex2d(startx+1,starty+1); glVertex2d(startx,starty+1);
        glVertex2d(startx,starty+1); glVertex2d(startx,starty);
    glEnd();
    startx++;
    glBegin(GL_TRIANGLES); // RIGHT
       	glVertex2d(startx+0.2,starty+0.2);
		glVertex2d(startx+1-0.2,starty+0.5);
       	glVertex2d(startx+0.2,starty+1-0.2);
    glEnd();
    glBegin(GL_LINES);
       	glVertex2d(startx,starty); glVertex2d(startx+1,starty);
        glVertex2d(startx+1,starty); glVertex2d(startx+1,starty+1);
        glVertex2d(startx+1,starty+1); glVertex2d(startx,starty+1);
        glVertex2d(startx,starty+1); glVertex2d(startx,starty);
    glEnd();
    startx++;
    
    // MOVE
    glColor3f(0.0,0.0,0.0);
//    starty--;
    startx = columns+4;
    glBegin(GL_LINES); // M
       	glVertex2d(startx+0.1,starty+0.5+0.1); glVertex2d(startx+0.1,starty+0.5+1-0.1);
        glVertex2d(startx+0.1,starty+0.5+1-0.1); glVertex2d(startx+1-0.5,starty+0.5+1-0.5);
        glVertex2d(startx+1-0.5,starty+0.5+1-0.5); glVertex2d(startx+1-0.1,starty+0.5+1-0.1);
        glVertex2d(startx+1-0.1,starty+0.5+0.1); glVertex2d(startx+1-0.1,starty+0.5+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // O
       	glVertex2d(startx+0.1,starty+0.5+0.1); glVertex2d(startx+0.1,starty+0.5+1-0.1);
        glVertex2d(startx+0.1,starty+0.5+0.1); glVertex2d(startx+1-0.1,starty+0.5+0.1);
        glVertex2d(startx+1-0.1,starty+0.5+0.1); glVertex2d(startx+1-0.1,starty+0.5+1-0.1);
        glVertex2d(startx+0.1,starty+0.5+1-0.1); glVertex2d(startx+1-0.1,starty+0.5+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // V
       	glVertex2d(startx+1-0.5,starty+0.5+0.1); glVertex2d(startx+0.1,starty+0.5+1-0.1);
        glVertex2d(startx+1-0.5,starty+0.5+0.1); glVertex2d(startx+1-0.1,starty+0.5+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // E
       	glVertex2d(startx+0.1,starty+0.5+0.1); glVertex2d(startx+0.1,starty+0.5+1-0.1);
        glVertex2d(startx+0.1,starty+0.5+1-0.1); glVertex2d(startx+1-0.1,starty+0.5+1-0.1);
        glVertex2d(startx+0.1,starty+0.5+0.4+0.1); glVertex2d(startx+1-0.1,starty+0.5+0.4+0.1);
        glVertex2d(startx+0.1,starty+0.5+0.1); glVertex2d(startx+1-0.1,starty+0.5+0.1);
    glEnd();
    
    // SCORE
    starty -= 2;
    startx = columns+2;
    glBegin(GL_LINES); // S
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+0.1,starty+0.5);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.5);
        glVertex2d(startx+0.1,starty+1-0.5); glVertex2d(startx+1-0.1,starty+1-0.5);
    glEnd();
    startx++;
    glBegin(GL_LINES); // C
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // O
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // R
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+1-0.1,starty+0.4+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.5); glVertex2d(startx+1-0.1,starty+1-0.5);
        glVertex2d(startx+0.1,starty+1-0.5); glVertex2d(startx+1-0.1,starty+0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // E
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.4+0.1); glVertex2d(startx+1-0.1,starty+0.4+0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
    glEnd();
    
    //Draw Score
    starty -= 2;
    draw_numbers(score, columns, starty, 0.5);
    
    //Draw Text "HIGH SCORE"
    starty -= 2;
    draw_text("HIGH SCORE", columns, starty, 0, 0);
	
	//Draw High Score
	starty -= 2;
    draw_numbers(high_score, columns, starty, 0.5);
    
    glLineWidth(1.0);
}

int draw_text(char* text, int columns, int rows, float padding_bottom, float extra_height) {
//	draw_numbers(strlen(text), columns, rows, extra_height);
	return rows;
}

void draw_numbers(int score, int columns, int rows, float extra_height) {
    if(score < 10) {
    	draw_number(score, columns+(int)(COLUMNS_INFO/2), rows, extra_height);
	} else {
    	draw_number(score/10, columns+(int)(COLUMNS_INFO/2-1)+0.3, rows, extra_height);
    	draw_number(score%10, columns+(int)(COLUMNS_INFO/2)+0.7, rows, extra_height);
	}
}

void draw_number(int score, float startx, float starty, float extra_height) {
	float a = extra_height;
	float b = a/2, c = a/4;
	glColor3f(0.0,0.0,0.0);
	glLineWidth(5.0);
	switch(score) {
		case 0: {
			glBegin(GL_LINE_LOOP); // 0
       			glVertex2d(startx+0.1-c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
       			glVertex2d(startx+0.1-c,starty+0.1);
    		glEnd();
			break;
		}
		case 1: {
			glBegin(GL_LINES); // 1
				glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
    		glEnd();
			break;
		}
		case 2: {
			glBegin(GL_LINE_STRIP); // 2
				glVertex2d(startx+0.1-c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
       			glVertex2d(startx+0.1-c,starty+0.1);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
    		glEnd();
			break;
		}
		case 3: {
			glBegin(GL_LINE_STRIP); // 3
				glVertex2d(startx+0.1-c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
       			glVertex2d(startx+0.1-c,starty+0.1);
    		glEnd();
			break;
		}
		case 4: {
			glBegin(GL_LINE_STRIP); // 4
       			glVertex2d(startx+0.1-c,starty+1-0.1+a);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
    		glEnd();
			break;
		}
		case 5: {
			glBegin(GL_LINE_STRIP); // 5
				glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
				glVertex2d(startx+0.1-c,starty+1-0.1+a);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
       			glVertex2d(startx+0.1-c,starty+0.1);
    		glEnd();
			break;
		}
		case 6: {
			glBegin(GL_LINE_STRIP); // 6
				glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
				glVertex2d(startx+0.1-c,starty+1-0.1+a);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
       			glVertex2d(startx+0.1-c,starty+0.1);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
    		glEnd();
			break;
		}
		case 7: {
			glBegin(GL_LINE_STRIP); // 7
				glVertex2d(startx+0.1-c,starty+1-0.1+a);
				glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
    		glEnd();
			break;
		}
		case 8: {
			glBegin(GL_LINE_LOOP); // 8
				glVertex2d(startx+0.1-c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
       			glVertex2d(startx+0.1-c,starty+0.1);
    		glEnd();
			break;
		}
		case 9: {
			glBegin(GL_LINE_STRIP); // 9
       			glVertex2d(startx+1-0.1+c,starty+0.5+b);
       			glVertex2d(startx+0.1-c,starty+0.5+b);
				glVertex2d(startx+0.1-c,starty+1-0.1+a);
				glVertex2d(startx+1-0.1+c,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1+c,starty+0.1);
       			glVertex2d(startx+0.1-c,starty+0.1);
    		glEnd();
			break;
		}
		default: {
			// ?
			glBegin(GL_LINE_STRIP);
				glVertex2d(startx+0.1,starty+1-0.1+a-b);
				glVertex2d(startx+0.1+b,starty+1-0.1+a);
				glVertex2d(startx+0.7+c,starty+1-0.1+a);
				glVertex2d(startx+0.7+c,starty+1-0.1+a-a);
				glVertex2d(startx+0.5,starty+0.1+a);
				glVertex2d(startx+0.5,starty+0.1+a-b);
    		glEnd();
    		glBegin(GL_LINES);
				glVertex2d(startx+0.5,starty+0.3);
				glVertex2d(startx+0.5,starty);
    		glEnd();
			break;
		}
	}
	glLineWidth(1.0);
}
