#include<gl/glut.h>
#include<cmath>
#include<iostream>

#define max_x 500
#define max_y 500

using namespace std;
int j = 0;

void myinit() {
	gluOrtho2D(-1*(max_x/2), max_x/2, -1 * (max_y / 2), max_y / 2);
}

void coordinates() {
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(max_x / 2, 0);
	glVertex2i(-(max_x / 2), 0);
	glVertex2i(0, max_y / 2);
	glVertex2i(0, -(max_y / 2));
	glEnd();
}

void wheel(int x,int y,int r) {
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	int i;
	double angle;
	for (i = 0; i <= 18; i++) {
		angle = i*3.14 / 9;
		glVertex2d(r * cos(angle)+x, r * sin(angle)+y);
	}
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	for (i = 0; i < 8; i++) {
		angle =  (j % 8) + i * 3.14 / 4;
		glVertex2d(x, y);
		glVertex2d(r * sin(angle) + x, r * cos(angle) + y);
	}
	glEnd();
	
}

void handle(double x, double y) {
	int i;
	double angle;
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	for (i = 270; i < 450; i++)
	{
		angle = (i % 360) * 3.142 / 180;
		glVertex2d(5 * cos(angle)+x-5, 5 * sin(angle)+y);
	}
	glEnd();
}


void triangle(double x,double y,int w) {
	glColor3f(1, 1, 1);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2d(x+(w*2), y);
	glVertex2d(x+w+20, y + 20);
	glVertex2d(x, y);
	glVertex2d(x+w-10, y + 20);
	glVertex2d(x, y);
	glVertex2d(x+w, y);
	glEnd();
	glLineWidth(1);
	glColor3f(1, 0, 0);
	x = x + w;
	glBegin(GL_LINE_LOOP);
	glVertex2d(x, y);
	glVertex2d(x + 20, y + 20);
	glVertex2d(x - 10, y + 20);
	glEnd();
	glBegin(GL_LINES);
	glVertex2d(x, y + 20);
	glVertex2d(x, y + 25);
	glLineWidth(5);
	glVertex2d(x - 5, y + 25);
	glVertex2d(x + 5, y + 27);
	glVertex2d(x + 20, y + 20);
	glVertex2d(x + 22, y + 28);
	glEnd();
	x += 22;
	y += 28;
	handle(x, y);
}

void update(int value) {
	j+=2;
	if (j <= max_x - 105) {
		//cout << j << endl;
		glutPostRedisplay();
		glutTimerFunc(200, update, 0);
	}
}

void display() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//coordinates();
	int r = 15,h=60,w=50;
	wheel(-1 * (max_x / 2) + r + 5 + j, -1 * (max_y / 2) + r + 5, r);
	wheel(-1 * (max_x / 2) + r + 55 + j, -1 * (max_y / 2) + r + 5, r);
	//Body of the bicycle
	triangle(-1 * (max_x / 2) + r + 5 + j, -1 * (max_y / 2) + r + 5, (w / 2));
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(max_x, max_y);
	glutCreateWindow("Cycle");
	myinit();
	glutDisplayFunc(display);
	glutTimerFunc(200, update, 0);
	glutMainLoop();
	return 0;
}