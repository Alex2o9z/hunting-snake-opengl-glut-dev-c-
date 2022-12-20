#include <GL/glut.h>
#include "game.h"
#include "displayinfo.h"

extern int high_score;
extern int score;

int draw_text(char text[50], float, float, float, float, float, float, int, int);
void draw_char(char, float, float, float, float);
void draw_numbers(int, int, int, float);
void draw_number(int, float, float, float);
void draw_moveicon(float, float, float);

void draw_info_content(int columns, int rows) {
	int startx = columns+1, starty = rows-2;
	
	// Draw Text "HUNTING SNAKE"
    glColor3f(0.0,0.0,0.0);
    starty--;
    starty = draw_text("HUNTING SNAKE", columns, starty, 0, 1, 0.5, H1, START_I, END_I);
    
    // Draw frame
    {
    starty -= 4;
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
       	glVertex2d(startx-0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty+3+0.2);
       	glVertex2d(startx-0.2,starty+3+0.2);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
       	glVertex2d(startx-0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty+3+0.2);
       	glVertex2d(startx-0.2,starty+3+0.2);
    glEnd();
    starty += 4;
	}
	    
    // Draw Text "SCORE"
    glColor3f(0.0,0.0,0.0);
    starty -= 2;
    starty = draw_text("SCORE", columns, starty, 0, 1, 0, H4, START_I, END_I);
    
    //Draw Score
    glColor3f(0.0,0.0,0.0);
    starty -= 2;
    draw_numbers(score, columns, starty, 0.5);
    
    // Draw frame
    {
    starty -= 5;
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
       	glVertex2d(startx-0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty+4+0.2);
       	glVertex2d(startx-0.2,starty+4+0.2);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
       	glVertex2d(startx-0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty-0.2);
       	glVertex2d(startx+7+0.2,starty+4+0.2);
       	glVertex2d(startx-0.2,starty+4+0.2);
    glEnd();
    starty += 5;
	}
    
    //Draw Text "HIGH SCORE"
    glColor3f(0.0,0.0,0.0);
    starty -= 2;
    starty = draw_text("HIGH SCORE", columns, starty, 0, 1, 0, H4, START_I, END_I);
	
	//Draw High Score
	glColor3f(0.0,0.0,0.0);
	starty -= 2;
    draw_numbers(high_score, columns, starty, 0.5);
    
    // MOVE ICON
    glColor3f(0.0,0.0,0.0);
    starty -= 3;
    draw_moveicon(columns, startx, starty);
    
    // Draw Text "MOVE"
    glColor3f(0.0,0.0,0.0);
    starty = draw_text("MOVE", columns+1.7, starty, 0.5, 1, 0, H5, START_I, END_I);
    
    glLineWidth(1.0);
}
 
void draw_moveicon(float columns, float startx, float starty) {
	starty++;
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
}

int draw_text(char text[50], float columns, float rows, float padding_bottom, float paddingx, float extra_height, float line_width, int starti, int endi) {
	// Check default endi
	if(endi == END_I) { endi = strlen(text); }
	// Caculate content center
	float col = columns + paddingx + ((COLUMNS_INFO - paddingx*2 - (endi - starti))/2);
	glLineWidth(line_width);
	if(endi - starti > COLUMNS_INFO - paddingx*2) {
		int pos[10]; int count = 0;
		// Check space position & count
		for(int i=starti; i<endi; i++) {
			if(text[i] == ' ') {
				pos[count] = i;
				count++;
			}
		}
		if (count > 0) {
			int tempi;
			if (count%2 == 1) {
				tempi = pos[(count+1)/2 - 1]; // space's count is odd
			} else {
				tempi = pos[count/2 - 1]; // space's count is even
			}
			// split text into 2 components & recursive
			rows = draw_text(text, columns, rows, padding_bottom, paddingx, extra_height, line_width, starti, tempi); // 1 for print
			rows = draw_text(text, columns, rows-1-extra_height, padding_bottom, paddingx, extra_height, line_width, tempi+1, endi); // 1 for continue check
		} else {
			// text is a word & longer than info's width - still print
			// Print the text
			for(int i=starti; i < endi; i++) {
				draw_char(text[i], col, rows+padding_bottom, extra_height, line_width);
				col++;
			}
		}
	} else {
		// Print the text
		for(int i=starti; i < endi; i++) {
			draw_char(text[i], col, rows+padding_bottom, extra_height, line_width);
			col++;
		}
	}
	glLineWidth(1.0);
	return rows;
}

void draw_char(char ch, float startx, float starty, float extra_height, float line_width) {
	float a = extra_height, w = line_width/50;
	float b = a/2, c = a/4;
	switch (ch) {
		case 'A': {
			glBegin(GL_LINE_STRIP); // A
       			glVertex2d(startx+0.1+w,starty);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w,starty);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
    		glEnd();
			break;
		}
		case 'B': {
			glBegin(GL_LINE_STRIP); // B
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w-w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
       			glVertex2d(startx+1-0.1-w-w,starty+0.5-w+b);
    		glEnd();
			break;
		}
		case 'C': {
			glBegin(GL_LINE_STRIP); // C
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
    		glEnd();
			break;
		}
		case 'D': {
			glBegin(GL_LINE_LOOP); // D
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w-0.2,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a-0.2);
       			glVertex2d(startx+1-0.1-w,starty+w+0.2);
       			glVertex2d(startx+1-0.1-w-0.2,starty+w);
       			glVertex2d(startx+0.1+w,starty+w);
    		glEnd();
			break;
		}
		case 'E': {
			glBegin(GL_LINE_STRIP); // E
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+0.1+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
    		glEnd();
			break;
		}
		case 'F': {
			glBegin(GL_LINE_STRIP); // F
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+0.1+w,starty);
    		glEnd();
			break;
		}
		case 'G': {
			glBegin(GL_LINE_STRIP); // G
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+0.5,starty+0.5-w+b);
    		glEnd();
			break;
		}
		case 'H': {
			glBegin(GL_LINE_STRIP); // H
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
       			glVertex2d(startx+0.1+w,starty);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1-w,starty);
    		glEnd();
			break;
		}
		case 'I': {
			glBegin(GL_LINE_STRIP); // I
				glVertex2d(startx+w,starty+1-0.1-w+a);
				glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.5-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.5-w,starty+w);
       			glVertex2d(startx+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
    		glEnd();
			break;
		}
		case 'J': {
			glBegin(GL_LINE_STRIP); // J
				glVertex2d(startx+w,starty+1-0.1-w+a);
				glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.6-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.6-w,starty+w);
       			glVertex2d(startx+0.2-w,starty+w);
       			glVertex2d(startx+w,starty+0.1+w);
    		glEnd();
			break;
		}
		case 'K': {
			glBegin(GL_LINE_STRIP); // K
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
       			glVertex2d(startx+0.1+w,starty);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty);
    		glEnd();
			break;
		}
		case 'L': {
			glBegin(GL_LINE_STRIP); // L
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
       			glVertex2d(startx+0.1+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
    		glEnd();
			break;
		}
		case 'M': {
			glBegin(GL_LINE_STRIP); // M
       			glVertex2d(startx+0.1+w,starty);
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
       			glVertex2d(startx+0.5,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1-w,starty);
    		glEnd();
			break;
		}
		case 'N': {
			glBegin(GL_LINE_STRIP); // N
       			glVertex2d(startx+0.1+w,starty);
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
       			glVertex2d(startx+1-0.1-w,starty);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
    		glEnd();
			break;
		}
		case 'O': {
			glBegin(GL_LINE_LOOP); // O
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
    		glEnd();
			break;
		}
		case 'P': {
			glBegin(GL_LINE_STRIP); // P
       			glVertex2d(startx+0.1+w,starty);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
    		glEnd();
			break;
		}
		case 'Q': {
			glBegin(GL_LINE_LOOP); // Q
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+w);
       			glVertex2d(startx+1-0.1-w,starty+w);
    		glEnd();
    		glBegin(GL_LINES); // Q
       			glVertex2d(startx+0.7-0.1-w,starty+0.3+w);
       			glVertex2d(startx+1.1-0.1-w,starty-0.1+w);
    		glEnd();
			break;
		}
		case 'R': {
			glBegin(GL_LINE_STRIP); // R
       			glVertex2d(startx+0.1+w,starty);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty);
    		glEnd();
			break;
		}
		case 'S': {
			glBegin(GL_LINE_STRIP); // S
       			glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.1+w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+0.5-w+b);
       			glVertex2d(startx+1-0.1-w,starty+w);
       			glVertex2d(startx+0.1+w,starty+w);
    		glEnd();
			break;
		}
		case 'T': {
			glBegin(GL_LINE_STRIP); // T
				glVertex2d(startx+w,starty+1-0.1-w+a);
				glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.5-w,starty+1-0.1-w+a);
       			glVertex2d(startx+0.5-w,starty);
    		glEnd();
			break;
		}
		case 'U': {
			glBegin(GL_LINE_STRIP); // U
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
				glVertex2d(startx+0.1+w,starty+w);
				glVertex2d(startx+1-0.1-w,starty+w);
				glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
    		glEnd();
			break;
		}
		case 'V': {
			glBegin(GL_LINE_STRIP); // V
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
				glVertex2d(startx+0.5,starty);
				glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
    		glEnd();
			break;
		}
		case 'W': {
			glBegin(GL_LINE_STRIP); // W
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
				glVertex2d(startx+0.3+w,starty);
				glVertex2d(startx+0.5,starty+0.5);
				glVertex2d(startx+0.7-w,starty);
				glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
    		glEnd();
			break;
		}
		case 'X': {
			glBegin(GL_LINES); // X
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
				glVertex2d(startx+1-0.1-w,starty);
				glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
				glVertex2d(startx+0.1+w,starty);
    		glEnd();
			break;
		}
		case 'Y': {
			glBegin(GL_LINE_STRIP); // Y
       			glVertex2d(startx+0.1+w,starty+1-0.1+a);
       			glVertex2d(startx+0.5,starty+0.5);
				glVertex2d(startx+1-0.1-w,starty+1-0.1+a);
       			glVertex2d(startx+0.5,starty+0.5);
				glVertex2d(startx+0.5-w,starty);
    		glEnd();
			break;
		}
		case 'Z': {
			glBegin(GL_LINE_STRIP); // Z
       			glVertex2d(startx+0.1+w,starty+1-0.1-w+a);
				glVertex2d(startx+1-0.1-w,starty+1-0.1-w+a);
				glVertex2d(startx+0.1+w,starty+w);
				glVertex2d(startx+1-0.1-w,starty+w);
    		glEnd();
			break;
		}
		default: {
			//space - draw nothing
			break;
		}
	}
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
