#ifndef DISPLAYINFO_H_INCLUDED
#define DISPLAYINFO_H_INCLUDED

#define H1 5.0
#define H2 4.0
#define H3 3.0
#define H4 2.0
#define H5 1.0
#define START_I 0
#define END_I -1

void draw_info_content(int columns, int rows);










//int text_size;
//int grid_width, grid_height;
//int char_width, char_height, char_space, padding_x;
//int charx,chary;
//int check;
//
//void draw_char(int, int, int, int, char);
//
//// TESTING AREA
//
//// draw text int a specific row of unit
//void draw_text(int font_size, int font_style,int startx, int starty, int endx, int endy, char text[10]) {
//	text_size = sizeof(text);
//	grid_width = endx - startx;
//	grid_height = endy - endx;
//	char_width = font_size;
//	char_height = font_size+(font_size/3);
//	char_space = font_size/9;
//	// temporary variable to check
//	check = text_size*font_size + (text_size-1)*(font_size/4);
//	
//	if (check <= grid_width && char_height < grid_height) {
//		//caculate padding x (center horizontal)
//		padding_x = (grid_width - check)/2;
//		//init char x coordinate start
//		charx = startx + padding_x;
//		
//		for (int i = 0; i < text_size; i++) {
//			draw_char(text[i], charx, starty, charx + char_width, starty + char_height);
//			charx += (char_width + char_space);
//		}
//	}
//}
//
//void draw_char(int startx, int starty, int endx, int endy, char c) {
//    switch (c) {
//    	case 'H': {
//    		glBegin(GL_LINES);
//    			glColor3f(0.0,0.0,0.0);
//       			glVertex2d(startx,starty); glVertex2d(startx,endy);
//        		glVertex2d(startx,(endy-starty)/2); glVertex2d(endx,(endy-starty)/2);
//        		glVertex2d(endx,starty); glVertex2d(endx,endy);
//    		glEnd();
//			break;
//		}
//		case 'U': {
//    		glBegin(GL_LINES);
//    			glColor3f(0.0,0.0,0.0);
//       			glVertex2d(startx,starty); glVertex2d(startx,endy);
//        		glVertex2d(startx,starty); glVertex2d(endx,starty);
//        		glVertex2d(endx,starty); glVertex2d(endx,endy);
//    		glEnd();
//			break;
//		}
//	}
//}
#endif
