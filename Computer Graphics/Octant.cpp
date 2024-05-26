#include<gl/glut.h>
#include<iostream>
using namespace std;
string str = "origin";

void myInit() {
	gluOrtho2D(-100, 100, -100, 100);
}

void draw() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
}

void octant(int x, int y) {
	if (x == 0 && y == 0)str = "origin";
	else if (x >= 0 && y >= 0) {
		str = (x >= y) ? "1st octant" : "2nd Octant";
	}
	else if (x <= 0 && y>=0) {
		str = (abs(x) >= y) ? "4th octant" : "3rd octant";
	}
	else if (x <= 0 && y <= 0) {
		str = (abs(x) >= abs(y)) ? "5th octant" : "6th octant";
	}
	else if (x >= 0 && y <= 0) {
		str = (x >= abs(y)) ? "8th octant" : "7th octant";
	}
}

void display() {
	//draw();
	int x, y;
	cout << "Enter coordinates\n";
	cin >> x >> y;
	octant(x, y);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glColor3f(1, 0, 0);
	
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	
	glEnd();
	glRasterPos2i(70, 70);
	for (int i = 0; i < str.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, str[i]);
	}
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);

	double angle = 0;
	for (int i = 0; i < 8; i++) {
		angle = (3.14 / 4) * i;
		glVertex2d(0, 0);
		glVertex2d(250 * cos(angle), 250 * sin(angle));
	}
	glEnd();
	glFlush();
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Moving Text");
	myInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

/*
#include<gl/glut.h>
#include<iostream>
using namespace std;
string str;
int x1=0, x2=250,j=0;

void myInit() {
	gluOrtho2D(0, 500, 0, 500);
}


void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
	glColor3f(0, 0, 0);
	glRasterPos2i(x1+5*j, x2);
	for (int i = 0; i < str.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	glFlush();
}

void update(int value) {
	j+=1;
	while (j < 300) {
		glutPostRedisplay();
		glutTimerFunc(100, update, 0);
	}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Moving Text");
	myInit();
	cout << "Enter a text\n";
	cin >> str;
	glutDisplayFunc(display);
	glutTimerFunc(100, update, 0);
	glutMainLoop();
	return 0;
}
*/