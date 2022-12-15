#include <GL/glut.h>

#define H1 0.9
#define H2 0.6
#define STYLE_1 1
#define STYLE_2 2

int text_size;
int grid_width, grid_height;
int char_width, char_height, char_space, padding_x;
int charx,chary;
int check;

void draw_char(int, int, int, int, char);

// draw text int a specific row of unit
void draw_text(int font_size, int font_style,int startx, int starty, int endx, int endy, char text[10]) {
	text_size = sizeof(text);
	grid_width = endx - startx;
	grid_height = endy - endx;
	char_width = font_size;
	char_height = font_size+(font_size/3);
	char_space = font_size/9;
	// temporary variable to check
	check = text_size*font_size + (text_size-1)*(font_size/4);
	
	if (check <= grid_width && char_height < grid_height) {
		//caculate padding x (center horizontal)
		padding_x = (grid_width - check)/2;
		//init char x coordinate start
		charx = startx + padding_x;
		
		for (int i = 0; i < text_size; i++) {
			draw_char(text[i], charx, starty, charx + char_width, starty + char_height);
			charx += (char_width + char_space);
		}
	}
}

void draw_char(int startx, int starty, int endx, int endy, char c) {
    switch (c) {
    	case 'H': {
    		glBegin(GL_LINES);
    			glColor3f(0.0,0.0,0.0);
       			glVertex2d(startx,starty); glVertex2d(startx,endy);
        		glVertex2d(startx,(endy-starty)/2); glVertex2d(endx,(endy-starty)/2);
        		glVertex2d(endx,starty); glVertex2d(endx,endy);
    		glEnd();
			break;
		}
		case 'U': {
    		glBegin(GL_LINES);
    			glColor3f(0.0,0.0,0.0);
       			glVertex2d(startx,starty); glVertex2d(startx,endy);
        		glVertex2d(startx,starty); glVertex2d(endx,starty);
        		glVertex2d(endx,starty); glVertex2d(endx,endy);
    		glEnd();
			break;
		}
	}
}

void draw_text_byhand(int columns, int rows) {
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
    startx = columns+4;
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
    startx = columns+3;
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
    starty--;
    startx = columns+3;
    glBegin(GL_LINES); // M
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.5,starty+1-0.5);
        glVertex2d(startx+1-0.5,starty+1-0.5); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // O
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
        glVertex2d(startx+1-0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // O
       	glVertex2d(startx+1-0.5,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+1-0.5,starty+0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
    glEnd();
    startx++;
    glBegin(GL_LINES); // E
       	glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+1-0.1); glVertex2d(startx+1-0.1,starty+1-0.1);
        glVertex2d(startx+0.1,starty+0.4+0.1); glVertex2d(startx+1-0.1,starty+0.4+0.1);
        glVertex2d(startx+0.1,starty+0.1); glVertex2d(startx+1-0.1,starty+0.1);
    glEnd();
    
    glLineWidth(1.0);
}
